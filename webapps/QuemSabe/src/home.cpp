#include "home.h"

Home::Home(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
{
    dispatcher().assign("",&Home::inicio,this);
}

void Home::inicio()
{    
    calassomys::View index;
    index.setContent(config.get<string>("calassomys.webapp.web_content_path")+"simple.html");
    index.setContentId("content", config.get<string>("calassomys.webapp.web_content_path") + "index.html" );

    response().out() << index;
}
