#include "webappconfig.h"
#include"hello.h"

WebAppConfig::WebAppConfig(cppcms::service &srv) : calassomys::WebApp(srv)
{
    attach(	new Hello(srv));
}


extern "C" calassomys::WebAppPtr create(cppcms::service& srv)
{
    return calassomys::WebAppPtr(new WebAppConfig(srv));
}
