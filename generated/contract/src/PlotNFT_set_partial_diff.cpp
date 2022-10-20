
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/PlotNFT_set_partial_diff.hxx>
#include <mmx/contract/PlotNFT_set_partial_diff_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 PlotNFT_set_partial_diff::VNX_TYPE_HASH(0xe1401fa23c077c00ull);
const vnx::Hash64 PlotNFT_set_partial_diff::VNX_CODE_HASH(0x2602eb77ce79ef65ull);

vnx::Hash64 PlotNFT_set_partial_diff::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string PlotNFT_set_partial_diff::get_type_name() const {
	return "mmx.contract.PlotNFT.set_partial_diff";
}

const vnx::TypeCode* PlotNFT_set_partial_diff::get_type_code() const {
	return mmx::contract::vnx_native_type_code_PlotNFT_set_partial_diff;
}

std::shared_ptr<PlotNFT_set_partial_diff> PlotNFT_set_partial_diff::create() {
	return std::make_shared<PlotNFT_set_partial_diff>();
}

std::shared_ptr<vnx::Value> PlotNFT_set_partial_diff::clone() const {
	return std::make_shared<PlotNFT_set_partial_diff>(*this);
}

void PlotNFT_set_partial_diff::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void PlotNFT_set_partial_diff::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void PlotNFT_set_partial_diff::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_PlotNFT_set_partial_diff;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, new_partial_diff);
	_visitor.type_end(*_type_code);
}

void PlotNFT_set_partial_diff::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.PlotNFT.set_partial_diff\"";
	_out << ", \"new_partial_diff\": "; vnx::write(_out, new_partial_diff);
	_out << "}";
}

void PlotNFT_set_partial_diff::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object PlotNFT_set_partial_diff::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.PlotNFT.set_partial_diff";
	_object["new_partial_diff"] = new_partial_diff;
	return _object;
}

void PlotNFT_set_partial_diff::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "new_partial_diff") {
			_entry.second.to(new_partial_diff);
		}
	}
}

vnx::Variant PlotNFT_set_partial_diff::get_field(const std::string& _name) const {
	if(_name == "new_partial_diff") {
		return vnx::Variant(new_partial_diff);
	}
	return vnx::Variant();
}

void PlotNFT_set_partial_diff::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "new_partial_diff") {
		_value.to(new_partial_diff);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const PlotNFT_set_partial_diff& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, PlotNFT_set_partial_diff& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* PlotNFT_set_partial_diff::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> PlotNFT_set_partial_diff::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.PlotNFT.set_partial_diff";
	type_code->type_hash = vnx::Hash64(0xe1401fa23c077c00ull);
	type_code->code_hash = vnx::Hash64(0x2602eb77ce79ef65ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::contract::PlotNFT_set_partial_diff);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<PlotNFT_set_partial_diff>(); };
	type_code->return_type = ::mmx::contract::PlotNFT_set_partial_diff_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "new_partial_diff";
		field.code = {33, 4};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::PlotNFT_set_partial_diff& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.new_partial_diff, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::PlotNFT_set_partial_diff& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_PlotNFT_set_partial_diff;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::PlotNFT_set_partial_diff>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.new_partial_diff, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::contract::PlotNFT_set_partial_diff& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::PlotNFT_set_partial_diff& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::PlotNFT_set_partial_diff& value) {
	value.accept(visitor);
}

} // vnx
