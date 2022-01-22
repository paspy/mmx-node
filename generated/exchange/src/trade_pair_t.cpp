
// AUTO GENERATED by vnxcppcodegen

#include <mmx/exchange/package.hxx>
#include <mmx/exchange/trade_pair_t.hxx>
#include <mmx/addr_t.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace exchange {


const vnx::Hash64 trade_pair_t::VNX_TYPE_HASH(0xb905dc58e1616f03ull);
const vnx::Hash64 trade_pair_t::VNX_CODE_HASH(0xff2680aa833f3641ull);

vnx::Hash64 trade_pair_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string trade_pair_t::get_type_name() const {
	return "mmx.exchange.trade_pair_t";
}

const vnx::TypeCode* trade_pair_t::get_type_code() const {
	return mmx::exchange::vnx_native_type_code_trade_pair_t;
}

std::shared_ptr<trade_pair_t> trade_pair_t::create() {
	return std::make_shared<trade_pair_t>();
}

std::shared_ptr<trade_pair_t> trade_pair_t::clone() const {
	return std::make_shared<trade_pair_t>(*this);
}

void trade_pair_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void trade_pair_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void trade_pair_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::exchange::vnx_native_type_code_trade_pair_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, bid);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, ask);
	_visitor.type_end(*_type_code);
}

void trade_pair_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"bid\": "; vnx::write(_out, bid);
	_out << ", \"ask\": "; vnx::write(_out, ask);
	_out << "}";
}

void trade_pair_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object trade_pair_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.exchange.trade_pair_t";
	_object["bid"] = bid;
	_object["ask"] = ask;
	return _object;
}

void trade_pair_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "ask") {
			_entry.second.to(ask);
		} else if(_entry.first == "bid") {
			_entry.second.to(bid);
		}
	}
}

vnx::Variant trade_pair_t::get_field(const std::string& _name) const {
	if(_name == "bid") {
		return vnx::Variant(bid);
	}
	if(_name == "ask") {
		return vnx::Variant(ask);
	}
	return vnx::Variant();
}

void trade_pair_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "bid") {
		_value.to(bid);
	} else if(_name == "ask") {
		_value.to(ask);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const trade_pair_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, trade_pair_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* trade_pair_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> trade_pair_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.exchange.trade_pair_t";
	type_code->type_hash = vnx::Hash64(0xb905dc58e1616f03ull);
	type_code->code_hash = vnx::Hash64(0xff2680aa833f3641ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::exchange::trade_pair_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<trade_pair_t>>(); };
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "bid";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "ask";
		field.code = {11, 32, 1};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx
} // namespace exchange


namespace vnx {

void read(TypeInput& in, ::mmx::exchange::trade_pair_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.bid, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.ask, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::exchange::trade_pair_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::exchange::vnx_native_type_code_trade_pair_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::exchange::trade_pair_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.bid, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.ask, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::exchange::trade_pair_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::exchange::trade_pair_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::exchange::trade_pair_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::exchange::trade_pair_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::exchange::trade_pair_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
