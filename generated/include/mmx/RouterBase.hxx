
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_RouterBase_HXX_
#define INCLUDE_mmx_RouterBase_HXX_

#include <mmx/package.hxx>
#include <mmx/Block.hxx>
#include <mmx/PeerInfo.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/node_info_t.hxx>
#include <mmx/node_type_e.hxx>
#include <mmx/pubkey_t.hpp>
#include <mmx/signature_t.hpp>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/MsgServer.h>


namespace mmx {

class RouterBase : public ::vnx::addons::MsgServer {
public:
	
	::vnx::TopicPtr input_vdfs = "timelord.proofs";
	::vnx::TopicPtr input_blocks = "node.verified_blocks";
	::vnx::TopicPtr input_verified_vdfs = "node.verified_vdfs";
	::vnx::TopicPtr input_verified_proof = "node.verified_proof";
	::vnx::TopicPtr input_transactions = "node.transactions";
	::vnx::TopicPtr output_vdfs = "network.vdfs";
	::vnx::TopicPtr output_proof = "network.proof";
	::vnx::TopicPtr output_blocks = "network.blocks";
	::vnx::TopicPtr output_transactions = "network.transactions";
	int32_t max_queue_ms = 1000;
	int32_t query_interval_ms = 10000;
	int32_t update_interval_ms = 1000;
	int32_t connect_interval_ms = 10000;
	int32_t fetch_timeout_ms = 10000;
	uint32_t sync_loss_delay = 60;
	uint32_t discover_interval = 60;
	uint32_t num_threads = 32;
	uint32_t num_peers_out = 8;
	uint32_t min_sync_peers = 2;
	uint32_t max_sync_peers = 4;
	uint32_t max_hash_cache = 100000;
	uint32_t tx_credits = 8;
	uint32_t vdf_credits = 1024;
	uint32_t block_credits = 256;
	uint32_t proof_credits = 10;
	uint32_t tx_relay_cost = 1;
	uint32_t vdf_relay_cost = 768;
	uint32_t proof_relay_cost = 2;
	uint32_t block_relay_cost = 8;
	uint32_t max_node_credits = 1024;
	uint32_t max_node_tx_credits = 1024;
	uint32_t max_farmer_credits = 32;
	uint32_t node_version = 101;
	::mmx::node_type_e mode = ::mmx::node_type_e::FULL_NODE;
	vnx::bool_t do_relay = true;
	std::set<std::string> seed_peers;
	std::set<std::string> block_peers;
	std::string storage_path;
	std::string node_server = "Node";
	
	typedef ::vnx::addons::MsgServer Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x952c4ef2956f31c4ull;
	
	RouterBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const RouterBase& _value);
	friend std::istream& operator>>(std::istream& _in, RouterBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual void discover() = 0;
	virtual ::mmx::hash_t get_id() const = 0;
	virtual ::mmx::node_info_t get_info() const = 0;
	virtual std::pair<::mmx::pubkey_t, ::mmx::signature_t> sign_msg(const ::mmx::hash_t& msg) const = 0;
	virtual std::vector<std::string> get_peers(const uint32_t& max_count) const = 0;
	virtual std::vector<std::string> get_known_peers() const = 0;
	virtual std::vector<std::string> get_connected_peers() const = 0;
	virtual std::shared_ptr<const ::mmx::PeerInfo> get_peer_info() const = 0;
	virtual std::vector<std::pair<std::string, uint32_t>> get_farmer_credits() const = 0;
	virtual void get_blocks_at_async(const uint32_t& height, const vnx::request_id_t& _request_id) const = 0;
	void get_blocks_at_async_return(const vnx::request_id_t& _request_id, const std::vector<std::shared_ptr<const ::mmx::Block>>& _ret_0) const;
	virtual void fetch_block_at_async(const std::string& address, const uint32_t& height, const vnx::request_id_t& _request_id) const = 0;
	void fetch_block_at_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::mmx::Block>& _ret_0) const;
	virtual void handle(std::shared_ptr<const ::mmx::Block> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::Transaction> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofOfTime> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofResponse> _value) {}
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_RouterBase_HXX_
