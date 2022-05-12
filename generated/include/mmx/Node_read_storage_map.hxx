
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Node_read_storage_map_HXX_
#define INCLUDE_mmx_Node_read_storage_map_HXX_

#include <mmx/package.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>


namespace mmx {

class MMX_EXPORT Node_read_storage_map : public ::vnx::Value {
public:
	
	::mmx::addr_t contract;
	uint64_t address = 0;
	uint32_t height = -1;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x1cc0cc12bc2c1b4eull;
	
	Node_read_storage_map() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<Node_read_storage_map> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const Node_read_storage_map& _value);
	friend std::istream& operator>>(std::istream& _in, Node_read_storage_map& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void Node_read_storage_map::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Node_read_storage_map>(3);
	_visitor.type_field("contract", 0); _visitor.accept(contract);
	_visitor.type_field("address", 1); _visitor.accept(address);
	_visitor.type_field("height", 2); _visitor.accept(height);
	_visitor.template type_end<Node_read_storage_map>(3);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_Node_read_storage_map_HXX_
