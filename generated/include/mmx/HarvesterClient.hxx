
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Harvester_CLIENT_HXX_
#define INCLUDE_mmx_Harvester_CLIENT_HXX_

#include <vnx/Client.h>
#include <mmx/Challenge.hxx>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>


namespace mmx {

class HarvesterClient : public vnx::Client {
public:
	HarvesterClient(const std::string& service_name);
	
	HarvesterClient(vnx::Hash64 service_addr);
	
	::vnx::Object vnx_get_config_object();
	
	::vnx::Variant vnx_get_config(const std::string& name = "");
	
	void vnx_set_config_object(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config_object_async(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	void vnx_set_config_async(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	::vnx::TypeCode vnx_get_type_code();
	
	std::shared_ptr<const ::vnx::ModuleInfo> vnx_get_module_info();
	
	void vnx_restart();
	
	void vnx_restart_async();
	
	void vnx_stop();
	
	void vnx_stop_async();
	
	vnx::bool_t vnx_self_test();
	
	void reload();
	
	void reload_async();
	
	uint32_t get_plot_count();
	
	uint64_t get_total_space();
	
};


} // namespace mmx

#endif // INCLUDE_mmx_Harvester_CLIENT_HXX_
