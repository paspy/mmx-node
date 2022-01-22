
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_exchange_trade_order_t_HXX_
#define INCLUDE_mmx_exchange_trade_order_t_HXX_

#include <vnx/Type.h>
#include <mmx/exchange/package.hxx>
#include <mmx/Solution.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/txio_key_t.hxx>


namespace mmx {
namespace exchange {

struct trade_order_t {
	
	
	uint64_t bid = 0;
	vnx::optional<uint64_t> ask;
	std::vector<::mmx::txio_key_t> bid_keys;
	std::shared_ptr<const ::mmx::Solution> solution;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x96dc9b77e428e71ull;
	
	trade_order_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	::mmx::hash_t calc_hash() const;
	
	static std::shared_ptr<trade_order_t> create();
	std::shared_ptr<trade_order_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const trade_order_t& _value);
	friend std::istream& operator>>(std::istream& _in, trade_order_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace mmx
} // namespace exchange


namespace vnx {

template<>
struct is_equivalent<::mmx::exchange::trade_order_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_exchange_trade_order_t_HXX_
