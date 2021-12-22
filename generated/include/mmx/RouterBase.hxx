
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_RouterBase_HXX_
#define INCLUDE_mmx_RouterBase_HXX_

#include <mmx/package.hxx>
#include <mmx/Block.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/Transaction.hxx>
#include <vnx/TopicPtr.hpp>
#include <vnx/addons/TcpServer.h>


namespace mmx {

class RouterBase : public ::vnx::addons::TcpServer {
public:
	
	::vnx::TopicPtr input_vdfs = "timelord.proofs";
	::vnx::TopicPtr input_blocks = "node.verified_blocks";
	::vnx::TopicPtr input_verified_vdfs = "node.verified_vdfs";
	::vnx::TopicPtr input_transactions = "node.transactions";
	::vnx::TopicPtr output_vdfs = "network.vdfs";
	::vnx::TopicPtr output_blocks = "network.blocks";
	::vnx::TopicPtr output_transactions = "network.transactions";
	int32_t max_queue_ms = 1000;
	int32_t info_interval_ms = 60000;
	int32_t update_interval_ms = 1000;
	int32_t connect_interval_ms = 10000;
	uint32_t discover_interval = 300;
	uint32_t num_peers_out = 8;
	uint32_t min_sync_peers = 2;
	uint32_t max_sync_peers = 4;
	uint32_t max_msg_size = 67108864;
	std::set<std::string> seed_peers;
	std::string node_server = "Node";
	
	typedef ::vnx::addons::TcpServer Super;
	
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
	virtual std::vector<std::string> get_peers(const uint32_t& max_count) const = 0;
	virtual void get_blocks_at_async(const uint32_t& height, const vnx::request_id_t& _request_id) const = 0;
	void get_blocks_at_async_return(const vnx::request_id_t& _request_id, const std::vector<std::shared_ptr<const ::mmx::Block>>& _ret_0) const;
	virtual void handle(std::shared_ptr<const ::mmx::Block> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::Transaction> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofOfTime> _value) {}
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_RouterBase_HXX_
