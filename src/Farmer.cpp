/*
 * Farmer.cpp
 *
 *  Created on: Dec 12, 2021
 *      Author: mad
 */

#include <mmx/Farmer.h>
#include <mmx/Transaction.hxx>
#include <mmx/utils.h>


namespace mmx {

Farmer::Farmer(const std::string& _vnx_name)
	:	FarmerBase(_vnx_name)
{
}

void Farmer::init()
{
	pipe = vnx::open_pipe(vnx_name, this, 1000);
	pipe->pause();

	vnx::open_pipe(vnx_get_id(), this, 1000);

	subscribe(input_info, 1000);
}

void Farmer::main()
{
	if(reward_addr) {
		if(*reward_addr == addr_t()) {
			throw std::logic_error("reward_addr == zero");
		}
		log(INFO) << "Reward address: " << reward_addr->to_string();
	}
	params = get_params();

	wallet = std::make_shared<WalletAsyncClient>(wallet_server);
	wallet->vnx_set_non_blocking(true);
	add_async_client(wallet);

	set_timer_millis(60 * 1000, std::bind(&Farmer::update, this));

	update();

	Super::main();
}

vnx::Hash64 Farmer::get_mac_addr() const
{
	return vnx_get_id();
}

std::vector<bls_pubkey_t> Farmer::get_farmer_keys() const
{
	std::vector<bls_pubkey_t> out;
	for(const auto& entry : key_map) {
		out.push_back(entry.first);
	}
	return out;
}

std::shared_ptr<const FarmInfo> Farmer::get_farm_info() const
{
	auto info = FarmInfo::create();
	for(const auto& entry : info_map) {
		if(auto value = std::dynamic_pointer_cast<const FarmInfo>(entry.second->value)) {
			if(value->harvester) {
				info->harvester_bytes[*value->harvester] += value->total_bytes;
			}
			for(const auto& entry : value->plot_count) {
				info->plot_count[entry.first] += entry.second;
			}
			for(const auto& dir : value->plot_dirs) {
				info->plot_dirs.push_back((value->harvester ? *value->harvester + ":" : "") + dir);
			}
			info->total_bytes += value->total_bytes;
			info->total_balance += value->total_balance;
		}
	}
	return info;
}

void Farmer::update()
{
	vnx::open_flow(vnx::get_pipe(node_server), vnx::get_pipe(vnx_get_id()));

	wallet->get_all_farmer_keys(
		[this](const std::vector<std::shared_ptr<const FarmerKeys>>& list) {
			for(auto keys : list) {
				if(key_map.emplace(keys->farmer_public_key, keys->farmer_private_key).second) {
					log(INFO) << "Got Farmer Key: " << keys->farmer_public_key;
				}
			}
			pipe->resume();
		},
		[this](const vnx::exception& ex) {
			log(WARN) << "Failed to get keys from wallet: " << ex.what();
		});

	if(!reward_addr) {
		wallet->get_all_accounts(
			[this](const std::map<uint32_t, account_t>& accounts) {
				if(accounts.empty()) {
					log(WARN) << "Failed to get reward address from wallet: no wallet available";
					return;
				}
				wallet->get_address(accounts.begin()->first, 0,
					[this](const addr_t& address) {
						if(!reward_addr) {
							log(INFO) << "Reward address: " << address.to_string();
						}
						reward_addr = address;
					},
					[this](const vnx::exception& ex) {
						log(WARN) << "Failed to get reward address from wallet: " << ex.what();
					});

			},
			[this](const vnx::exception& ex) {
				log(WARN) << "Failed to get reward address from wallet: " << ex.what();
			});
	}

	const auto now = vnx::get_sync_time_micros();
	for(auto iter = info_map.begin(); iter != info_map.end();) {
		if((now - iter->second->recv_time) / 1000000 > harvester_timeout) {
			iter = info_map.erase(iter);
		} else {
			iter++;
		}
	}
}

void Farmer::handle(std::shared_ptr<const FarmInfo> value)
{
	if(auto sample = vnx_sample) {
		if(value->harvester_id) {
			info_map[*value->harvester_id] = sample;
		} else if(value->harvester) {
			info_map[hash_t(*value->harvester)] = sample;
		}
	}
}

skey_t Farmer::find_skey(const bls_pubkey_t& pubkey) const
{
	auto iter = key_map.find(pubkey);
	if(iter == key_map.end()) {
		throw std::logic_error("unknown farmer key: " + pubkey.to_string());
	}
	return iter->second;
}

bls_signature_t Farmer::sign_proof(std::shared_ptr<const ProofResponse> value) const
{
	if(!value || !value->is_valid()) {
		throw std::logic_error("invalid argument");
	}
	// TODO: verify proof
	return bls_signature_t::sign(find_skey(value->proof->farmer_key), value->hash);
}

std::shared_ptr<const BlockHeader>
Farmer::sign_block(std::shared_ptr<const BlockHeader> block, const uint64_t& reward_amount) const
{
	if(!block) {
		throw std::logic_error("!block");
	}
	if(!block->proof) {
		throw std::logic_error("!proof");
	}
	const auto farmer_sk = find_skey(block->proof->farmer_key);

	auto base = Transaction::create();
	base->expires = block->height;
	base->note = tx_note_e::REWARD;
	base->salt = block->prev;

	auto amount_left = reward_amount;
	if(project_addr && amount_left > 0)
	{
		txout_t out;
		out.address = *project_addr;
		out.amount = double(amount_left) * devfee_ratio;
		if(out.amount > 0) {
			amount_left -= out.amount;
			base->outputs.push_back(out);
		}
	}
	if(reward_addr && amount_left > 0)
	{
		txout_t out;
		out.address = *reward_addr;
		out.amount = amount_left;
		amount_left -= out.amount;
		base->outputs.push_back(out);
	}
	base->finalize();

	base->static_cost = base->calc_cost(params);
	{
		exec_result_t res;
		res.total_cost = base->static_cost;
		for(const auto& out : base->outputs) {
			res.total_fee += out.amount;
		}
		base->exec_result = res;
	}
	base->content_hash = base->calc_hash(true);

	auto out = vnx::clone(block);
	out->nonce = vnx::rand64();
	out->tx_base = base;
	out->hash = out->calc_hash().first;
	out->farmer_sig = bls_signature_t::sign(farmer_sk, out->hash);
	return out;
}


} // mmx
