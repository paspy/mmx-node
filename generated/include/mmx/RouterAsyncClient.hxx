
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Router_ASYNC_CLIENT_HXX_
#define INCLUDE_mmx_Router_ASYNC_CLIENT_HXX_

#include <vnx/AsyncClient.h>
#include <mmx/Block.hxx>
#include <mmx/PeerInfo.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/pubkey_t.hpp>
#include <mmx/signature_t.hpp>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/TcpServer.h>


namespace mmx {

class RouterAsyncClient : public vnx::AsyncClient {
public:
	RouterAsyncClient(const std::string& service_name);
	
	RouterAsyncClient(vnx::Hash64 service_addr);
	
	uint64_t vnx_get_config_object(
			const std::function<void(const ::vnx::Object&)>& _callback = std::function<void(const ::vnx::Object&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_get_config(const std::string& name = "", 
			const std::function<void(const ::vnx::Variant&)>& _callback = std::function<void(const ::vnx::Variant&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_set_config_object(const ::vnx::Object& config = ::vnx::Object(), 
			const std::function<void()>& _callback = std::function<void()>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_set_config(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant(), 
			const std::function<void()>& _callback = std::function<void()>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_get_type_code(
			const std::function<void(const ::vnx::TypeCode&)>& _callback = std::function<void(const ::vnx::TypeCode&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_get_module_info(
			const std::function<void(std::shared_ptr<const ::vnx::ModuleInfo>)>& _callback = std::function<void(std::shared_ptr<const ::vnx::ModuleInfo>)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_restart(
			const std::function<void()>& _callback = std::function<void()>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_stop(
			const std::function<void()>& _callback = std::function<void()>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t vnx_self_test(
			const std::function<void(const vnx::bool_t&)>& _callback = std::function<void(const vnx::bool_t&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t discover(
			const std::function<void()>& _callback = std::function<void()>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_id(
			const std::function<void(const ::mmx::hash_t&)>& _callback = std::function<void(const ::mmx::hash_t&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t sign_msg(const ::mmx::hash_t& msg = ::mmx::hash_t(), 
			const std::function<void(const std::pair<::mmx::pubkey_t, ::mmx::signature_t>&)>& _callback = std::function<void(const std::pair<::mmx::pubkey_t, ::mmx::signature_t>&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_peers(const uint32_t& max_count = 10, 
			const std::function<void(const std::vector<std::string>&)>& _callback = std::function<void(const std::vector<std::string>&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_known_peers(
			const std::function<void(const std::vector<std::string>&)>& _callback = std::function<void(const std::vector<std::string>&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_connected_peers(
			const std::function<void(const std::vector<std::string>&)>& _callback = std::function<void(const std::vector<std::string>&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_peer_info(
			const std::function<void(std::shared_ptr<const ::mmx::PeerInfo>)>& _callback = std::function<void(std::shared_ptr<const ::mmx::PeerInfo>)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_farmer_credits(
			const std::function<void(const std::vector<std::pair<std::string, uint32_t>>&)>& _callback = std::function<void(const std::vector<std::pair<std::string, uint32_t>>&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
	uint64_t get_blocks_at(const uint32_t& height = 0, 
			const std::function<void(const std::vector<std::shared_ptr<const ::mmx::Block>>&)>& _callback = std::function<void(const std::vector<std::shared_ptr<const ::mmx::Block>>&)>(),
			const std::function<void(const vnx::exception&)>& _error_callback = std::function<void(const vnx::exception&)>());
	
protected:
	int32_t vnx_purge_request(uint64_t _request_id, const vnx::exception& _ex) override;
	
	int32_t vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Value> _value) override;
	
private:
	std::unordered_map<uint64_t, std::pair<std::function<void(const ::vnx::Object&)>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_get_config_object;
	std::unordered_map<uint64_t, std::pair<std::function<void(const ::vnx::Variant&)>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_get_config;
	std::unordered_map<uint64_t, std::pair<std::function<void()>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_set_config_object;
	std::unordered_map<uint64_t, std::pair<std::function<void()>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_set_config;
	std::unordered_map<uint64_t, std::pair<std::function<void(const ::vnx::TypeCode&)>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_get_type_code;
	std::unordered_map<uint64_t, std::pair<std::function<void(std::shared_ptr<const ::vnx::ModuleInfo>)>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_get_module_info;
	std::unordered_map<uint64_t, std::pair<std::function<void()>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_restart;
	std::unordered_map<uint64_t, std::pair<std::function<void()>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_stop;
	std::unordered_map<uint64_t, std::pair<std::function<void(const vnx::bool_t&)>, std::function<void(const vnx::exception&)>>> vnx_queue_vnx_self_test;
	std::unordered_map<uint64_t, std::pair<std::function<void()>, std::function<void(const vnx::exception&)>>> vnx_queue_discover;
	std::unordered_map<uint64_t, std::pair<std::function<void(const ::mmx::hash_t&)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_id;
	std::unordered_map<uint64_t, std::pair<std::function<void(const std::pair<::mmx::pubkey_t, ::mmx::signature_t>&)>, std::function<void(const vnx::exception&)>>> vnx_queue_sign_msg;
	std::unordered_map<uint64_t, std::pair<std::function<void(const std::vector<std::string>&)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_peers;
	std::unordered_map<uint64_t, std::pair<std::function<void(const std::vector<std::string>&)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_known_peers;
	std::unordered_map<uint64_t, std::pair<std::function<void(const std::vector<std::string>&)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_connected_peers;
	std::unordered_map<uint64_t, std::pair<std::function<void(std::shared_ptr<const ::mmx::PeerInfo>)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_peer_info;
	std::unordered_map<uint64_t, std::pair<std::function<void(const std::vector<std::pair<std::string, uint32_t>>&)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_farmer_credits;
	std::unordered_map<uint64_t, std::pair<std::function<void(const std::vector<std::shared_ptr<const ::mmx::Block>>&)>, std::function<void(const vnx::exception&)>>> vnx_queue_get_blocks_at;
	
};


} // namespace mmx

#endif // INCLUDE_mmx_Router_ASYNC_CLIENT_HXX_
