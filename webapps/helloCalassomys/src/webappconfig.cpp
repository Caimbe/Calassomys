#include "webappconfig.h"
#include"hello.h"

WebAppConfig::WebAppConfig()
{
}

void WebAppConfig::configure(ServicePtr& service)
{
    service->applications_pool().mount(cppcms::applications_factory<Hello>());
}

extern "C" std::shared_ptr<iWebAppConfig> create()
{
    return std::shared_ptr<iWebAppConfig>(new WebAppConfig);
}
