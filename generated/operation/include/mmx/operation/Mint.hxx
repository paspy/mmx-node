
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_operation_Mint_HXX_
#define INCLUDE_mmx_operation_Mint_HXX_

#include <mmx/operation/package.hxx>
#include <mmx/Operation.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>


namespace mmx {
namespace operation {

class Mint : public ::mmx::Operation {
public:
	
	::mmx::addr_t target;
	uint64_t amount = 0;
	
	typedef ::mmx::Operation Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x936aeac3aa6373c0ull;
	
	Mint() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<Mint> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const Mint& _value);
	friend std::istream& operator>>(std::istream& _in, Mint& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace mmx
} // namespace operation


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_operation_Mint_HXX_
