#include "home.h"

Home::Home(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
{
    dispatcher().assign("",&Home::all,this);
    mapper().assign("");

    index.setContent(config.get<string>("calassomys.webapp.web_content_path")+"index.html");
    index.setContentId("header", config.get<string>("calassomys.webapp.web_content_path") + config.get<string>("calassomys.header_page") );
    index.setContentId("footer", config.get<string>("calassomys.webapp.web_content_path") + config.get<string>("calassomys.footer_page") );

}

void Home::all()
{
    response().out() << index;
}
