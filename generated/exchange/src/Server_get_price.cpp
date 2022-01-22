
// AUTO GENERATED by vnxcppcodegen

#include <mmx/exchange/package.hxx>
#include <mmx/exchange/Server_get_price.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/exchange/Server_get_price_return.hxx>
#include <mmx/exchange/amount_t.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace exchange {


const vnx::Hash64 Server_get_price::VNX_TYPE_HASH(0x97209facb005ead5ull);
const vnx::Hash64 Server_get_price::VNX_CODE_HASH(0x993019c635894b04ull);

vnx::Hash64 Server_get_price::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Server_get_price::get_type_name() const {
	return "mmx.exchange.Server.get_price";
}

const vnx::TypeCode* Server_get_price::get_type_code() const {
	return mmx::exchange::vnx_native_type_code_Server_get_price;
}

std::shared_ptr<Server_get_price> Server_get_price::create() {
	return std::make_shared<Server_get_price>();
}

std::shared_ptr<vnx::Value> Server_get_price::clone() const {
	return std::make_shared<Server_get_price>(*this);
}

void Server_get_price::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Server_get_price::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Server_get_price::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::exchange::vnx_native_type_code_Server_get_price;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, want);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, have);
	_visitor.type_end(*_type_code);
}

void Server_get_price::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.exchange.Server.get_price\"";
	_out << ", \"want\": "; vnx::write(_out, want);
	_out << ", \"have\": "; vnx::write(_out, have);
	_out << "}";
}

void Server_get_price::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Server_get_price::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.exchange.Server.get_price";
	_object["want"] = want;
	_object["have"] = have;
	return _object;
}

void Server_get_price::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "have") {
			_entry.second.to(have);
		} else if(_entry.first == "want") {
			_entry.second.to(want);
		}
	}
}

vnx::Variant Server_get_price::get_field(const std::string& _name) const {
	if(_name == "want") {
		return vnx::Variant(want);
	}
	if(_name == "have") {
		return vnx::Variant(have);
	}
	return vnx::Variant();
}

void Server_get_price::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "want") {
		_value.to(want);
	} else if(_name == "have") {
		_value.to(have);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Server_get_price& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Server_get_price& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Server_get_price::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Server_get_price::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.exchange.Server.get_price";
	type_code->type_hash = vnx::Hash64(0x97209facb005ead5ull);
	type_code->code_hash = vnx::Hash64(0x993019c635894b04ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::exchange::Server_get_price);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Server_get_price>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::exchange::amount_t::static_get_type_code();
	type_code->is_const = true;
	type_code->return_type = ::mmx::exchange::Server_get_price_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "want";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "have";
		field.code = {19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace exchange


namespace vnx {

void read(TypeInput& in, ::mmx::exchange::Server_get_price& value, const TypeCode* type_code, const uint16_t* code) {
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
	in.read(type_code->total_field_size);
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.want, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.have, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::exchange::Server_get_price& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::exchange::vnx_native_type_code_Server_get_price;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::exchange::Server_get_price>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.want, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.have, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::exchange::Server_get_price& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::exchange::Server_get_price& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::exchange::Server_get_price& value) {
	value.accept(visitor);
}

} // vnx
