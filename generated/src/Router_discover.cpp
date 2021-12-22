
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Router_discover.hxx>
#include <mmx/Router_discover_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Router_discover::VNX_TYPE_HASH(0xeda51767d96e246cull);
const vnx::Hash64 Router_discover::VNX_CODE_HASH(0x3d96f8d693a2fa38ull);

vnx::Hash64 Router_discover::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Router_discover::get_type_name() const {
	return "mmx.Router.discover";
}

const vnx::TypeCode* Router_discover::get_type_code() const {
	return mmx::vnx_native_type_code_Router_discover;
}

std::shared_ptr<Router_discover> Router_discover::create() {
	return std::make_shared<Router_discover>();
}

std::shared_ptr<vnx::Value> Router_discover::clone() const {
	return std::make_shared<Router_discover>(*this);
}

void Router_discover::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Router_discover::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Router_discover::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Router_discover;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void Router_discover::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Router.discover\"";
	_out << "}";
}

void Router_discover::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Router_discover::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Router.discover";
	return _object;
}

void Router_discover::from_object(const vnx::Object& _object) {
}

vnx::Variant Router_discover::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void Router_discover::set_field(const std::string& _name, const vnx::Variant& _value) {
	throw std::logic_error("no such field: '" + _name + "'");
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Router_discover& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Router_discover& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Router_discover::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Router_discover::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Router.discover";
	type_code->type_hash = vnx::Hash64(0xeda51767d96e246cull);
	type_code->code_hash = vnx::Hash64(0x3d96f8d693a2fa38ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Router_discover);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Router_discover>(); };
	type_code->return_type = ::mmx::Router_discover_return::static_get_type_code();
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Router_discover& value, const TypeCode* type_code, const uint16_t* code) {
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
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Router_discover& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Router_discover;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Router_discover>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::mmx::Router_discover& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Router_discover& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Router_discover& value) {
	value.accept(visitor);
}

} // vnx
