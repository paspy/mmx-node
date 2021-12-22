
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/FarmerKeys.hxx>
#include <mmx/bls_pubkey_t.hpp>
#include <mmx/skey_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 FarmerKeys::VNX_TYPE_HASH(0x9942f861520098b3ull);
const vnx::Hash64 FarmerKeys::VNX_CODE_HASH(0x4ddeff6874388914ull);

vnx::Hash64 FarmerKeys::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string FarmerKeys::get_type_name() const {
	return "mmx.FarmerKeys";
}

const vnx::TypeCode* FarmerKeys::get_type_code() const {
	return mmx::vnx_native_type_code_FarmerKeys;
}

std::shared_ptr<FarmerKeys> FarmerKeys::create() {
	return std::make_shared<FarmerKeys>();
}

std::shared_ptr<vnx::Value> FarmerKeys::clone() const {
	return std::make_shared<FarmerKeys>(*this);
}

void FarmerKeys::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void FarmerKeys::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void FarmerKeys::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_FarmerKeys;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, pool_private_key);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, farmer_private_key);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, pool_public_key);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, farmer_public_key);
	_visitor.type_end(*_type_code);
}

void FarmerKeys::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.FarmerKeys\"";
	_out << ", \"pool_private_key\": "; vnx::write(_out, pool_private_key);
	_out << ", \"farmer_private_key\": "; vnx::write(_out, farmer_private_key);
	_out << ", \"pool_public_key\": "; vnx::write(_out, pool_public_key);
	_out << ", \"farmer_public_key\": "; vnx::write(_out, farmer_public_key);
	_out << "}";
}

void FarmerKeys::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object FarmerKeys::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.FarmerKeys";
	_object["pool_private_key"] = pool_private_key;
	_object["farmer_private_key"] = farmer_private_key;
	_object["pool_public_key"] = pool_public_key;
	_object["farmer_public_key"] = farmer_public_key;
	return _object;
}

void FarmerKeys::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "farmer_private_key") {
			_entry.second.to(farmer_private_key);
		} else if(_entry.first == "farmer_public_key") {
			_entry.second.to(farmer_public_key);
		} else if(_entry.first == "pool_private_key") {
			_entry.second.to(pool_private_key);
		} else if(_entry.first == "pool_public_key") {
			_entry.second.to(pool_public_key);
		}
	}
}

vnx::Variant FarmerKeys::get_field(const std::string& _name) const {
	if(_name == "pool_private_key") {
		return vnx::Variant(pool_private_key);
	}
	if(_name == "farmer_private_key") {
		return vnx::Variant(farmer_private_key);
	}
	if(_name == "pool_public_key") {
		return vnx::Variant(pool_public_key);
	}
	if(_name == "farmer_public_key") {
		return vnx::Variant(farmer_public_key);
	}
	return vnx::Variant();
}

void FarmerKeys::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "pool_private_key") {
		_value.to(pool_private_key);
	} else if(_name == "farmer_private_key") {
		_value.to(farmer_private_key);
	} else if(_name == "pool_public_key") {
		_value.to(pool_public_key);
	} else if(_name == "farmer_public_key") {
		_value.to(farmer_public_key);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const FarmerKeys& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, FarmerKeys& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* FarmerKeys::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> FarmerKeys::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.FarmerKeys";
	type_code->type_hash = vnx::Hash64(0x9942f861520098b3ull);
	type_code->code_hash = vnx::Hash64(0x4ddeff6874388914ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::FarmerKeys);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<FarmerKeys>(); };
	type_code->fields.resize(4);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "pool_private_key";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "farmer_private_key";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "pool_public_key";
		field.code = {11, 48, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "farmer_public_key";
		field.code = {11, 48, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::FarmerKeys& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.pool_private_key, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.farmer_private_key, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.pool_public_key, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.farmer_public_key, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::FarmerKeys& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_FarmerKeys;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::FarmerKeys>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.pool_private_key, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.farmer_private_key, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.pool_public_key, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.farmer_public_key, type_code, type_code->fields[3].code.data());
}

void read(std::istream& in, ::mmx::FarmerKeys& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::FarmerKeys& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::FarmerKeys& value) {
	value.accept(visitor);
}

} // vnx
