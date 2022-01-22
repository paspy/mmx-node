
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_get_utxo_list.hxx>
#include <mmx/Wallet_get_utxo_list_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_get_utxo_list::VNX_TYPE_HASH(0xa9416ad9f318f1feull);
const vnx::Hash64 Wallet_get_utxo_list::VNX_CODE_HASH(0x1954265d1394137dull);

vnx::Hash64 Wallet_get_utxo_list::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_get_utxo_list::get_type_name() const {
	return "mmx.Wallet.get_utxo_list";
}

const vnx::TypeCode* Wallet_get_utxo_list::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_get_utxo_list;
}

std::shared_ptr<Wallet_get_utxo_list> Wallet_get_utxo_list::create() {
	return std::make_shared<Wallet_get_utxo_list>();
}

std::shared_ptr<vnx::Value> Wallet_get_utxo_list::clone() const {
	return std::make_shared<Wallet_get_utxo_list>(*this);
}

void Wallet_get_utxo_list::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_get_utxo_list::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_get_utxo_list::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_get_utxo_list;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, index);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, min_confirm);
	_visitor.type_end(*_type_code);
}

void Wallet_get_utxo_list::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.get_utxo_list\"";
	_out << ", \"index\": "; vnx::write(_out, index);
	_out << ", \"min_confirm\": "; vnx::write(_out, min_confirm);
	_out << "}";
}

void Wallet_get_utxo_list::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_get_utxo_list::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.get_utxo_list";
	_object["index"] = index;
	_object["min_confirm"] = min_confirm;
	return _object;
}

void Wallet_get_utxo_list::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "index") {
			_entry.second.to(index);
		} else if(_entry.first == "min_confirm") {
			_entry.second.to(min_confirm);
		}
	}
}

vnx::Variant Wallet_get_utxo_list::get_field(const std::string& _name) const {
	if(_name == "index") {
		return vnx::Variant(index);
	}
	if(_name == "min_confirm") {
		return vnx::Variant(min_confirm);
	}
	return vnx::Variant();
}

void Wallet_get_utxo_list::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "index") {
		_value.to(index);
	} else if(_name == "min_confirm") {
		_value.to(min_confirm);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_get_utxo_list& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_get_utxo_list& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_get_utxo_list::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_get_utxo_list::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.get_utxo_list";
	type_code->type_hash = vnx::Hash64(0xa9416ad9f318f1feull);
	type_code->code_hash = vnx::Hash64(0x1954265d1394137dull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Wallet_get_utxo_list);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_get_utxo_list>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Wallet_get_utxo_list_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "index";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "min_confirm";
		field.value = vnx::to_string(0);
		field.code = {3};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_get_utxo_list& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.index, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.min_confirm, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Wallet_get_utxo_list& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_get_utxo_list;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_get_utxo_list>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.index);
	vnx::write_value(_buf + 4, value.min_confirm);
}

void read(std::istream& in, ::mmx::Wallet_get_utxo_list& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_get_utxo_list& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_get_utxo_list& value) {
	value.accept(visitor);
}

} // vnx
