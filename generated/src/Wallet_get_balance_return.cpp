
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_get_balance_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_get_balance_return::VNX_TYPE_HASH(0xfa00e6f62563141full);
const vnx::Hash64 Wallet_get_balance_return::VNX_CODE_HASH(0xd535aee95ef02359ull);

vnx::Hash64 Wallet_get_balance_return::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_get_balance_return::get_type_name() const {
	return "mmx.Wallet.get_balance.return";
}

const vnx::TypeCode* Wallet_get_balance_return::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_get_balance_return;
}

std::shared_ptr<Wallet_get_balance_return> Wallet_get_balance_return::create() {
	return std::make_shared<Wallet_get_balance_return>();
}

std::shared_ptr<vnx::Value> Wallet_get_balance_return::clone() const {
	return std::make_shared<Wallet_get_balance_return>(*this);
}

void Wallet_get_balance_return::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_get_balance_return::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_get_balance_return::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_get_balance_return;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, _ret_0);
	_visitor.type_end(*_type_code);
}

void Wallet_get_balance_return::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.get_balance.return\"";
	_out << ", \"_ret_0\": "; vnx::write(_out, _ret_0);
	_out << "}";
}

void Wallet_get_balance_return::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_get_balance_return::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.get_balance.return";
	_object["_ret_0"] = _ret_0;
	return _object;
}

void Wallet_get_balance_return::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "_ret_0") {
			_entry.second.to(_ret_0);
		}
	}
}

vnx::Variant Wallet_get_balance_return::get_field(const std::string& _name) const {
	if(_name == "_ret_0") {
		return vnx::Variant(_ret_0);
	}
	return vnx::Variant();
}

void Wallet_get_balance_return::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "_ret_0") {
		_value.to(_ret_0);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_get_balance_return& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_get_balance_return& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_get_balance_return::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_get_balance_return::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.get_balance.return";
	type_code->type_hash = vnx::Hash64(0xfa00e6f62563141full);
	type_code->code_hash = vnx::Hash64(0xd535aee95ef02359ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_return = true;
	type_code->native_size = sizeof(::mmx::Wallet_get_balance_return);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_get_balance_return>(); };
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.data_size = 8;
		field.name = "_ret_0";
		field.code = {4};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_get_balance_return& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value._ret_0, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Wallet_get_balance_return& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_get_balance_return;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_get_balance_return>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value._ret_0);
}

void read(std::istream& in, ::mmx::Wallet_get_balance_return& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_get_balance_return& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_get_balance_return& value) {
	value.accept(visitor);
}

} // vnx
