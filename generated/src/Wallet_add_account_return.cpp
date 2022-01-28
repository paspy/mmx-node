
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_add_account_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_add_account_return::VNX_TYPE_HASH(0xda0b2d71dd9e8336ull);
const vnx::Hash64 Wallet_add_account_return::VNX_CODE_HASH(0x4a65f998a0ed8d87ull);

vnx::Hash64 Wallet_add_account_return::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_add_account_return::get_type_name() const {
	return "mmx.Wallet.add_account.return";
}

const vnx::TypeCode* Wallet_add_account_return::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_add_account_return;
}

std::shared_ptr<Wallet_add_account_return> Wallet_add_account_return::create() {
	return std::make_shared<Wallet_add_account_return>();
}

std::shared_ptr<vnx::Value> Wallet_add_account_return::clone() const {
	return std::make_shared<Wallet_add_account_return>(*this);
}

void Wallet_add_account_return::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_add_account_return::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_add_account_return::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_add_account_return;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void Wallet_add_account_return::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.add_account.return\"";
	_out << "}";
}

void Wallet_add_account_return::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_add_account_return::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.add_account.return";
	return _object;
}

void Wallet_add_account_return::from_object(const vnx::Object& _object) {
}

vnx::Variant Wallet_add_account_return::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void Wallet_add_account_return::set_field(const std::string& _name, const vnx::Variant& _value) {
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_add_account_return& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_add_account_return& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_add_account_return::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_add_account_return::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.add_account.return";
	type_code->type_hash = vnx::Hash64(0xda0b2d71dd9e8336ull);
	type_code->code_hash = vnx::Hash64(0x4a65f998a0ed8d87ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_return = true;
	type_code->native_size = sizeof(::mmx::Wallet_add_account_return);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_add_account_return>(); };
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_add_account_return& value, const TypeCode* type_code, const uint16_t* code) {
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

void write(TypeOutput& out, const ::mmx::Wallet_add_account_return& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_add_account_return;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_add_account_return>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::mmx::Wallet_add_account_return& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_add_account_return& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_add_account_return& value) {
	value.accept(visitor);
}

} // vnx
