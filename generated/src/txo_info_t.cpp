
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/txo_info_t.hxx>
#include <mmx/txio_key_t.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 txo_info_t::VNX_TYPE_HASH(0x41e366a847ba3fb4ull);
const vnx::Hash64 txo_info_t::VNX_CODE_HASH(0xf587ff980dce9077ull);

vnx::Hash64 txo_info_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string txo_info_t::get_type_name() const {
	return "mmx.txo_info_t";
}

const vnx::TypeCode* txo_info_t::get_type_code() const {
	return mmx::vnx_native_type_code_txo_info_t;
}

std::shared_ptr<txo_info_t> txo_info_t::create() {
	return std::make_shared<txo_info_t>();
}

std::shared_ptr<txo_info_t> txo_info_t::clone() const {
	return std::make_shared<txo_info_t>(*this);
}

void txo_info_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void txo_info_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void txo_info_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_txo_info_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, created_at);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, spent_on);
	_visitor.type_end(*_type_code);
}

void txo_info_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"created_at\": "; vnx::write(_out, created_at);
	_out << ", \"spent_on\": "; vnx::write(_out, spent_on);
	_out << "}";
}

void txo_info_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object txo_info_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.txo_info_t";
	_object["created_at"] = created_at;
	_object["spent_on"] = spent_on;
	return _object;
}

void txo_info_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "created_at") {
			_entry.second.to(created_at);
		} else if(_entry.first == "spent_on") {
			_entry.second.to(spent_on);
		}
	}
}

vnx::Variant txo_info_t::get_field(const std::string& _name) const {
	if(_name == "created_at") {
		return vnx::Variant(created_at);
	}
	if(_name == "spent_on") {
		return vnx::Variant(spent_on);
	}
	return vnx::Variant();
}

void txo_info_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "created_at") {
		_value.to(created_at);
	} else if(_name == "spent_on") {
		_value.to(spent_on);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const txo_info_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, txo_info_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* txo_info_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> txo_info_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.txo_info_t";
	type_code->type_hash = vnx::Hash64(0x41e366a847ba3fb4ull);
	type_code->code_hash = vnx::Hash64(0xf587ff980dce9077ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::txo_info_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<txo_info_t>>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::txio_key_t::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "created_at";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "spent_on";
		field.code = {33, 19, 0};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::txo_info_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.created_at, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.spent_on, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::txo_info_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_txo_info_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::txo_info_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.created_at);
	vnx::write(out, value.spent_on, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::txo_info_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::txo_info_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::txo_info_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::txo_info_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::txo_info_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
