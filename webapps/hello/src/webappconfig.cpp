#include "webappconfig.h"
#include"hello.h"
#include <fstream>
#include <cppcms/json.h>

WebAppConfig::WebAppConfig(cppcms::service &srv, std::string& nome) : calassomys::WebApp(srv)
{
    nameWebApp = nome;
    attach(	new Hello(srv));
    attach( new Numbers(srv), "/numbers");

    dispatcher().assign("/(.*)",&WebAppConfig::serveFile,this,1);
}


void WebAppConfig::serveFile(std::string file_name)
{
    file_name = file_name.length()?file_name:settings().get<string>("calassomys.index_page");
    const char* name = (settings().get<string>("calassomys.path_webapps")+"/"+nameWebApp + "/"WEBCONTENT"/" + file_name).c_str();
    std::ifstream f(name);
    if(!f) {
        response().status(404);
    }
    else {
        response().out() << f.rdbuf();
    }
}

extern "C" calassomys::WebAppPtr create(cppcms::service& srv, std::string& name)
{
    return calassomys::WebAppPtr(new WebAppConfig(srv, name));
}
