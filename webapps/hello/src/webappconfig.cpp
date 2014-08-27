#include "webappconfig.h"
#include"hello.h"

WebAppConfig::WebAppConfig(cppcms::service &srv) : calassomys::WebApp(srv)
{
    attach(	new Hello(srv),
            "hello",
            "/{1}",
            "(/(\\d+)?)?",2);

}

WebAppConfig::~WebAppConfig()
{

}

extern "C" calassomys::WebAppPtr create(cppcms::service& srv)
{
    return calassomys::WebAppPtr(new WebAppConfig(srv));
}
