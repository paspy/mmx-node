
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_exchange_ServerBase_HXX_
#define INCLUDE_mmx_exchange_ServerBase_HXX_

#include <mmx/exchange/package.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/exchange/amount_t.hxx>
#include <mmx/exchange/limit_order_t.hxx>
#include <mmx/exchange/order_t.hxx>
#include <mmx/exchange/trade_order_t.hxx>
#include <mmx/exchange/trade_pair_t.hxx>
#include <mmx/txio_key_t.hxx>
#include <mmx/ulong_fraction_t.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>


namespace mmx {
namespace exchange {

class ServerBase : public ::vnx::Module {
public:
	
	::vnx::TopicPtr input_blocks = "node.verified_blocks";
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x573a9f3b899c4e1dull;
	
	ServerBase(const std::string& _vnx_name);
	
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
	
	friend std::ostream& operator<<(std::ostream& _out, const ServerBase& _value);
	friend std::istream& operator>>(std::istream& _in, ServerBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual void approve(std::shared_ptr<const ::mmx::Transaction> tx) = 0;
	virtual void place_async(const ::mmx::exchange::trade_pair_t& pair, const ::mmx::exchange::limit_order_t& orders, const vnx::request_id_t& _request_id) = 0;
	void place_async_return(const vnx::request_id_t& _request_id) const;
	virtual void execute_async(const ::mmx::exchange::trade_pair_t& pair, const ::mmx::exchange::trade_order_t& orders, const vnx::request_id_t& _request_id) const = 0;
	void execute_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::mmx::Transaction>& _ret_0) const;
	virtual std::vector<::mmx::exchange::order_t> get_orders(const ::mmx::exchange::trade_pair_t& pair) const = 0;
	virtual ::mmx::ulong_fraction_t get_price(const ::mmx::addr_t& want, const ::mmx::exchange::amount_t& have) const = 0;
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};


} // namespace mmx
} // namespace exchange


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_exchange_ServerBase_HXX_
