
// AUTO GENERATED by vnxcppcodegen

#include <mmx/operation/package.hxx>
#include <mmx/operation/Transfer.hxx>
#include <mmx/Contract.hxx>
#include <mmx/Operation.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace operation {


const vnx::Hash64 Transfer::VNX_TYPE_HASH(0xc412d1446361cb09ull);
const vnx::Hash64 Transfer::VNX_CODE_HASH(0x5bc15fa1d63fce05ull);

vnx::Hash64 Transfer::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Transfer::get_type_name() const {
	return "mmx.operation.Transfer";
}

const vnx::TypeCode* Transfer::get_type_code() const {
	return mmx::operation::vnx_native_type_code_Transfer;
}

std::shared_ptr<Transfer> Transfer::create() {
	return std::make_shared<Transfer>();
}

std::shared_ptr<vnx::Value> Transfer::clone() const {
	return std::make_shared<Transfer>(*this);
}

void Transfer::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Transfer::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Transfer::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::operation::vnx_native_type_code_Transfer;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, solution);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, new_owner);
	_visitor.type_end(*_type_code);
}

void Transfer::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.operation.Transfer\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"address\": "; vnx::write(_out, address);
	_out << ", \"solution\": "; vnx::write(_out, solution);
	_out << ", \"new_owner\": "; vnx::write(_out, new_owner);
	_out << "}";
}

void Transfer::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Transfer::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.operation.Transfer";
	_object["version"] = version;
	_object["address"] = address;
	_object["solution"] = solution;
	_object["new_owner"] = new_owner;
	return _object;
}

void Transfer::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "new_owner") {
			_entry.second.to(new_owner);
		} else if(_entry.first == "solution") {
			_entry.second.to(solution);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		}
	}
}

vnx::Variant Transfer::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "solution") {
		return vnx::Variant(solution);
	}
	if(_name == "new_owner") {
		return vnx::Variant(new_owner);
	}
	return vnx::Variant();
}

void Transfer::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "address") {
		_value.to(address);
	} else if(_name == "solution") {
		_value.to(solution);
	} else if(_name == "new_owner") {
		_value.to(new_owner);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Transfer& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Transfer& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Transfer::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Transfer::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.operation.Transfer";
	type_code->type_hash = vnx::Hash64(0xc412d1446361cb09ull);
	type_code->code_hash = vnx::Hash64(0x5bc15fa1d63fce05ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::operation::Transfer);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::Operation::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Transfer>(); };
	type_code->fields.resize(4);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "solution";
		field.code = {16};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "new_owner";
		field.code = {16};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace operation


namespace vnx {

void read(TypeInput& in, ::mmx::operation::Transfer& value, const TypeCode* type_code, const uint16_t* code) {
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
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.solution, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.new_owner, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::operation::Transfer& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::operation::vnx_native_type_code_Transfer;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::operation::Transfer>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.version);
	vnx::write(out, value.address, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.solution, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.new_owner, type_code, type_code->fields[3].code.data());
}

void read(std::istream& in, ::mmx::operation::Transfer& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::operation::Transfer& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::operation::Transfer& value) {
	value.accept(visitor);
}

} // vnx
