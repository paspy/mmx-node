
// AUTO GENERATED by vnxcppcodegen

#include <mmx/exchange/package.hxx>
#include <mmx/exchange/RouterBase.hxx>
#include <vnx/NoSuchMethod.hxx>
#include <vnx/ModuleInterface_vnx_get_config.hxx>
#include <vnx/ModuleInterface_vnx_get_config_return.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object.hxx>
#include <vnx/ModuleInterface_vnx_get_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info.hxx>
#include <vnx/ModuleInterface_vnx_get_module_info_return.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code_return.hxx>
#include <vnx/ModuleInterface_vnx_restart.hxx>
#include <vnx/ModuleInterface_vnx_restart_return.hxx>
#include <vnx/ModuleInterface_vnx_self_test.hxx>
#include <vnx/ModuleInterface_vnx_self_test_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config.hxx>
#include <vnx/ModuleInterface_vnx_set_config_return.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object.hxx>
#include <vnx/ModuleInterface_vnx_set_config_object_return.hxx>
#include <vnx/ModuleInterface_vnx_stop.hxx>
#include <vnx/ModuleInterface_vnx_stop_return.hxx>
#include <vnx/addons/MsgServer.h>

#include <vnx/vnx.h>


namespace mmx {
namespace exchange {


const vnx::Hash64 RouterBase::VNX_TYPE_HASH(0xf7789bd63f26f69aull);
const vnx::Hash64 RouterBase::VNX_CODE_HASH(0xb8a9a3b880d0e1c2ull);

RouterBase::RouterBase(const std::string& _vnx_name)
	:	MsgServer::MsgServer(_vnx_name)
{
}

vnx::Hash64 RouterBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string RouterBase::get_type_name() const {
	return "mmx.exchange.Router";
}

const vnx::TypeCode* RouterBase::get_type_code() const {
	return mmx::exchange::vnx_native_type_code_RouterBase;
}

void RouterBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::exchange::vnx_native_type_code_RouterBase;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, port);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, host);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, max_connections);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, listen_queue_size);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, stats_interval_ms);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, connection_timeout_ms);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, send_buffer_size);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, receive_buffer_size);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, tcp_no_delay);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, tcp_keepalive);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, show_warnings);
	_visitor.type_field(_type_code->fields[11], 11); vnx::accept(_visitor, max_msg_size);
	_visitor.type_end(*_type_code);
}

void RouterBase::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"port\": "; vnx::write(_out, port);
	_out << ", \"host\": "; vnx::write(_out, host);
	_out << ", \"max_connections\": "; vnx::write(_out, max_connections);
	_out << ", \"listen_queue_size\": "; vnx::write(_out, listen_queue_size);
	_out << ", \"stats_interval_ms\": "; vnx::write(_out, stats_interval_ms);
	_out << ", \"connection_timeout_ms\": "; vnx::write(_out, connection_timeout_ms);
	_out << ", \"send_buffer_size\": "; vnx::write(_out, send_buffer_size);
	_out << ", \"receive_buffer_size\": "; vnx::write(_out, receive_buffer_size);
	_out << ", \"tcp_no_delay\": "; vnx::write(_out, tcp_no_delay);
	_out << ", \"tcp_keepalive\": "; vnx::write(_out, tcp_keepalive);
	_out << ", \"show_warnings\": "; vnx::write(_out, show_warnings);
	_out << ", \"max_msg_size\": "; vnx::write(_out, max_msg_size);
	_out << "}";
}

void RouterBase::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object RouterBase::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.exchange.Router";
	_object["port"] = port;
	_object["host"] = host;
	_object["max_connections"] = max_connections;
	_object["listen_queue_size"] = listen_queue_size;
	_object["stats_interval_ms"] = stats_interval_ms;
	_object["connection_timeout_ms"] = connection_timeout_ms;
	_object["send_buffer_size"] = send_buffer_size;
	_object["receive_buffer_size"] = receive_buffer_size;
	_object["tcp_no_delay"] = tcp_no_delay;
	_object["tcp_keepalive"] = tcp_keepalive;
	_object["show_warnings"] = show_warnings;
	_object["max_msg_size"] = max_msg_size;
	return _object;
}

void RouterBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "connection_timeout_ms") {
			_entry.second.to(connection_timeout_ms);
		} else if(_entry.first == "host") {
			_entry.second.to(host);
		} else if(_entry.first == "listen_queue_size") {
			_entry.second.to(listen_queue_size);
		} else if(_entry.first == "max_connections") {
			_entry.second.to(max_connections);
		} else if(_entry.first == "max_msg_size") {
			_entry.second.to(max_msg_size);
		} else if(_entry.first == "port") {
			_entry.second.to(port);
		} else if(_entry.first == "receive_buffer_size") {
			_entry.second.to(receive_buffer_size);
		} else if(_entry.first == "send_buffer_size") {
			_entry.second.to(send_buffer_size);
		} else if(_entry.first == "show_warnings") {
			_entry.second.to(show_warnings);
		} else if(_entry.first == "stats_interval_ms") {
			_entry.second.to(stats_interval_ms);
		} else if(_entry.first == "tcp_keepalive") {
			_entry.second.to(tcp_keepalive);
		} else if(_entry.first == "tcp_no_delay") {
			_entry.second.to(tcp_no_delay);
		}
	}
}

vnx::Variant RouterBase::get_field(const std::string& _name) const {
	if(_name == "port") {
		return vnx::Variant(port);
	}
	if(_name == "host") {
		return vnx::Variant(host);
	}
	if(_name == "max_connections") {
		return vnx::Variant(max_connections);
	}
	if(_name == "listen_queue_size") {
		return vnx::Variant(listen_queue_size);
	}
	if(_name == "stats_interval_ms") {
		return vnx::Variant(stats_interval_ms);
	}
	if(_name == "connection_timeout_ms") {
		return vnx::Variant(connection_timeout_ms);
	}
	if(_name == "send_buffer_size") {
		return vnx::Variant(send_buffer_size);
	}
	if(_name == "receive_buffer_size") {
		return vnx::Variant(receive_buffer_size);
	}
	if(_name == "tcp_no_delay") {
		return vnx::Variant(tcp_no_delay);
	}
	if(_name == "tcp_keepalive") {
		return vnx::Variant(tcp_keepalive);
	}
	if(_name == "show_warnings") {
		return vnx::Variant(show_warnings);
	}
	if(_name == "max_msg_size") {
		return vnx::Variant(max_msg_size);
	}
	return vnx::Variant();
}

void RouterBase::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "port") {
		_value.to(port);
	} else if(_name == "host") {
		_value.to(host);
	} else if(_name == "max_connections") {
		_value.to(max_connections);
	} else if(_name == "listen_queue_size") {
		_value.to(listen_queue_size);
	} else if(_name == "stats_interval_ms") {
		_value.to(stats_interval_ms);
	} else if(_name == "connection_timeout_ms") {
		_value.to(connection_timeout_ms);
	} else if(_name == "send_buffer_size") {
		_value.to(send_buffer_size);
	} else if(_name == "receive_buffer_size") {
		_value.to(receive_buffer_size);
	} else if(_name == "tcp_no_delay") {
		_value.to(tcp_no_delay);
	} else if(_name == "tcp_keepalive") {
		_value.to(tcp_keepalive);
	} else if(_name == "show_warnings") {
		_value.to(show_warnings);
	} else if(_name == "max_msg_size") {
		_value.to(max_msg_size);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const RouterBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, RouterBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* RouterBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> RouterBase::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.exchange.Router";
	type_code->type_hash = vnx::Hash64(0xf7789bd63f26f69aull);
	type_code->code_hash = vnx::Hash64(0xb8a9a3b880d0e1c2ull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::exchange::RouterBase);
	type_code->parents.resize(2);
	type_code->parents[0] = ::vnx::addons::MsgServerBase::static_get_type_code();
	type_code->parents[1] = ::vnx::addons::TcpServerBase::static_get_type_code();
	type_code->methods.resize(9);
	type_code->methods[0] = ::vnx::ModuleInterface_vnx_get_config_object::static_get_type_code();
	type_code->methods[1] = ::vnx::ModuleInterface_vnx_get_config::static_get_type_code();
	type_code->methods[2] = ::vnx::ModuleInterface_vnx_set_config_object::static_get_type_code();
	type_code->methods[3] = ::vnx::ModuleInterface_vnx_set_config::static_get_type_code();
	type_code->methods[4] = ::vnx::ModuleInterface_vnx_get_type_code::static_get_type_code();
	type_code->methods[5] = ::vnx::ModuleInterface_vnx_get_module_info::static_get_type_code();
	type_code->methods[6] = ::vnx::ModuleInterface_vnx_restart::static_get_type_code();
	type_code->methods[7] = ::vnx::ModuleInterface_vnx_stop::static_get_type_code();
	type_code->methods[8] = ::vnx::ModuleInterface_vnx_self_test::static_get_type_code();
	type_code->fields.resize(12);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "port";
		field.value = vnx::to_string(9090);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "host";
		field.value = vnx::to_string("localhost");
		field.code = {32};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 4;
		field.name = "max_connections";
		field.value = vnx::to_string(-1);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "listen_queue_size";
		field.value = vnx::to_string(100);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 4;
		field.name = "stats_interval_ms";
		field.value = vnx::to_string(10000);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 4;
		field.name = "connection_timeout_ms";
		field.value = vnx::to_string(-1);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[6];
		field.data_size = 4;
		field.name = "send_buffer_size";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[7];
		field.data_size = 4;
		field.name = "receive_buffer_size";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[8];
		field.data_size = 1;
		field.name = "tcp_no_delay";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[9];
		field.data_size = 1;
		field.name = "tcp_keepalive";
		field.value = vnx::to_string(true);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[10];
		field.data_size = 1;
		field.name = "show_warnings";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[11];
		field.data_size = 4;
		field.name = "max_msg_size";
		field.value = vnx::to_string(67108864);
		field.code = {3};
	}
	type_code->build();
	return type_code;
}

void RouterBase::vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) {
	const auto* _type_code = _value->get_type_code();
	while(_type_code) {
		switch(_type_code->type_hash) {
			default:
				_type_code = _type_code->super;
		}
	}
	handle(std::static_pointer_cast<const vnx::Value>(_value));
}

std::shared_ptr<vnx::Value> RouterBase::vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) {
	switch(_method->get_type_hash()) {
		case 0x17f58f68bf83abc0ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_object_return::create();
			_return_value->_ret_0 = vnx_get_config_object();
			return _return_value;
		}
		case 0xbbc7f1a01044d294ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_config_return::create();
			_return_value->_ret_0 = vnx_get_config(_args->name);
			return _return_value;
		}
		case 0xca30f814f17f322full: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config_object>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_object_return::create();
			vnx_set_config_object(_args->config);
			return _return_value;
		}
		case 0x362aac91373958b7ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_set_config>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_set_config_return::create();
			vnx_set_config(_args->name, _args->value);
			return _return_value;
		}
		case 0x305ec4d628960e5dull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_type_code_return::create();
			_return_value->_ret_0 = vnx_get_type_code();
			return _return_value;
		}
		case 0xf6d82bdf66d034a1ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_get_module_info>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_get_module_info_return::create();
			_return_value->_ret_0 = vnx_get_module_info();
			return _return_value;
		}
		case 0x9e95dc280cecca1bull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_restart>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_restart_return::create();
			vnx_restart();
			return _return_value;
		}
		case 0x7ab49ce3d1bfc0d2ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_stop>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_stop_return::create();
			vnx_stop();
			return _return_value;
		}
		case 0x6ce3775b41a42697ull: {
			auto _args = std::static_pointer_cast<const ::vnx::ModuleInterface_vnx_self_test>(_method);
			auto _return_value = ::vnx::ModuleInterface_vnx_self_test_return::create();
			_return_value->_ret_0 = vnx_self_test();
			return _return_value;
		}
	}
	auto _ex = vnx::NoSuchMethod::create();
	_ex->dst_mac = vnx_request ? vnx_request->dst_mac : vnx::Hash64();
	_ex->method = _method->get_type_name();
	return _ex;
}


} // namespace mmx
} // namespace exchange


namespace vnx {

void read(TypeInput& in, ::mmx::exchange::RouterBase& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.port, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.max_connections, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.listen_queue_size, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.stats_interval_ms, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.connection_timeout_ms, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[6]) {
			vnx::read_value(_buf + _field->offset, value.send_buffer_size, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[7]) {
			vnx::read_value(_buf + _field->offset, value.receive_buffer_size, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[8]) {
			vnx::read_value(_buf + _field->offset, value.tcp_no_delay, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[9]) {
			vnx::read_value(_buf + _field->offset, value.tcp_keepalive, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[10]) {
			vnx::read_value(_buf + _field->offset, value.show_warnings, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[11]) {
			vnx::read_value(_buf + _field->offset, value.max_msg_size, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.host, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::exchange::RouterBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::exchange::vnx_native_type_code_RouterBase;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::exchange::RouterBase>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(35);
	vnx::write_value(_buf + 0, value.port);
	vnx::write_value(_buf + 4, value.max_connections);
	vnx::write_value(_buf + 8, value.listen_queue_size);
	vnx::write_value(_buf + 12, value.stats_interval_ms);
	vnx::write_value(_buf + 16, value.connection_timeout_ms);
	vnx::write_value(_buf + 20, value.send_buffer_size);
	vnx::write_value(_buf + 24, value.receive_buffer_size);
	vnx::write_value(_buf + 28, value.tcp_no_delay);
	vnx::write_value(_buf + 29, value.tcp_keepalive);
	vnx::write_value(_buf + 30, value.show_warnings);
	vnx::write_value(_buf + 31, value.max_msg_size);
	vnx::write(out, value.host, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::exchange::RouterBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::exchange::RouterBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::exchange::RouterBase& value) {
	value.accept(visitor);
}

} // vnx
