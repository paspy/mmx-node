
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Router_sign_msg.hxx>
#include <mmx/Router_sign_msg_return.hxx>
#include <mmx/hash_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Router_sign_msg::VNX_TYPE_HASH(0x88ede2fbb99ab63eull);
const vnx::Hash64 Router_sign_msg::VNX_CODE_HASH(0x994b29aed2a3d558ull);

vnx::Hash64 Router_sign_msg::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Router_sign_msg::get_type_name() const {
	return "mmx.Router.sign_msg";
}

const vnx::TypeCode* Router_sign_msg::get_type_code() const {
	return mmx::vnx_native_type_code_Router_sign_msg;
}

std::shared_ptr<Router_sign_msg> Router_sign_msg::create() {
	return std::make_shared<Router_sign_msg>();
}

std::shared_ptr<vnx::Value> Router_sign_msg::clone() const {
	return std::make_shared<Router_sign_msg>(*this);
}

void Router_sign_msg::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Router_sign_msg::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Router_sign_msg::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Router_sign_msg;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, msg);
	_visitor.type_end(*_type_code);
}

void Router_sign_msg::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Router.sign_msg\"";
	_out << ", \"msg\": "; vnx::write(_out, msg);
	_out << "}";
}

void Router_sign_msg::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Router_sign_msg::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Router.sign_msg";
	_object["msg"] = msg;
	return _object;
}

void Router_sign_msg::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "msg") {
			_entry.second.to(msg);
		}
	}
}

vnx::Variant Router_sign_msg::get_field(const std::string& _name) const {
	if(_name == "msg") {
		return vnx::Variant(msg);
	}
	return vnx::Variant();
}

void Router_sign_msg::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "msg") {
		_value.to(msg);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Router_sign_msg& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Router_sign_msg& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Router_sign_msg::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Router_sign_msg::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Router.sign_msg";
	type_code->type_hash = vnx::Hash64(0x88ede2fbb99ab63eull);
	type_code->code_hash = vnx::Hash64(0x994b29aed2a3d558ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Router_sign_msg);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Router_sign_msg>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Router_sign_msg_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "msg";
		field.code = {11, 32, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Router_sign_msg& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.msg, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Router_sign_msg& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Router_sign_msg;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Router_sign_msg>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.msg, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::Router_sign_msg& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Router_sign_msg& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Router_sign_msg& value) {
	value.accept(visitor);
}

} // vnx
