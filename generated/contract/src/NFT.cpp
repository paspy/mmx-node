
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/NFT.hxx>
#include <mmx/Contract.hxx>
#include <mmx/contract/Condition.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 NFT::VNX_TYPE_HASH(0x7cb24b9888a47906ull);
const vnx::Hash64 NFT::VNX_CODE_HASH(0xf0ca10c845f08403ull);

vnx::Hash64 NFT::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string NFT::get_type_name() const {
	return "mmx.contract.NFT";
}

const vnx::TypeCode* NFT::get_type_code() const {
	return mmx::contract::vnx_native_type_code_NFT;
}

std::shared_ptr<NFT> NFT::create() {
	return std::make_shared<NFT>();
}

std::shared_ptr<vnx::Value> NFT::clone() const {
	return std::make_shared<NFT>(*this);
}

void NFT::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void NFT::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void NFT::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_NFT;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, owner);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, transfer_cond);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, is_burnable);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, is_transferable);
	_visitor.type_end(*_type_code);
}

void NFT::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.NFT\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"owner\": "; vnx::write(_out, owner);
	_out << ", \"transfer_cond\": "; vnx::write(_out, transfer_cond);
	_out << ", \"is_burnable\": "; vnx::write(_out, is_burnable);
	_out << ", \"is_transferable\": "; vnx::write(_out, is_transferable);
	_out << "}";
}

void NFT::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object NFT::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.NFT";
	_object["version"] = version;
	_object["owner"] = owner;
	_object["transfer_cond"] = transfer_cond;
	_object["is_burnable"] = is_burnable;
	_object["is_transferable"] = is_transferable;
	return _object;
}

void NFT::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "is_burnable") {
			_entry.second.to(is_burnable);
		} else if(_entry.first == "is_transferable") {
			_entry.second.to(is_transferable);
		} else if(_entry.first == "owner") {
			_entry.second.to(owner);
		} else if(_entry.first == "transfer_cond") {
			_entry.second.to(transfer_cond);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		}
	}
}

vnx::Variant NFT::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "owner") {
		return vnx::Variant(owner);
	}
	if(_name == "transfer_cond") {
		return vnx::Variant(transfer_cond);
	}
	if(_name == "is_burnable") {
		return vnx::Variant(is_burnable);
	}
	if(_name == "is_transferable") {
		return vnx::Variant(is_transferable);
	}
	return vnx::Variant();
}

void NFT::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "owner") {
		_value.to(owner);
	} else if(_name == "transfer_cond") {
		_value.to(transfer_cond);
	} else if(_name == "is_burnable") {
		_value.to(is_burnable);
	} else if(_name == "is_transferable") {
		_value.to(is_transferable);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const NFT& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, NFT& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* NFT::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> NFT::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.NFT";
	type_code->type_hash = vnx::Hash64(0x7cb24b9888a47906ull);
	type_code->code_hash = vnx::Hash64(0xf0ca10c845f08403ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::contract::NFT);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::Contract::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<NFT>(); };
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "owner";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "transfer_cond";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 1;
		field.name = "is_burnable";
		field.code = {31};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 1;
		field.name = "is_transferable";
		field.code = {31};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::NFT& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.is_burnable, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.is_transferable, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.owner, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.transfer_cond, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::NFT& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_NFT;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::NFT>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(6);
	vnx::write_value(_buf + 0, value.version);
	vnx::write_value(_buf + 4, value.is_burnable);
	vnx::write_value(_buf + 5, value.is_transferable);
	vnx::write(out, value.owner, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.transfer_cond, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::contract::NFT& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::NFT& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::NFT& value) {
	value.accept(visitor);
}

} // vnx
