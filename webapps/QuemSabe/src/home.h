#ifndef Home_H
#define Home_H

#include <webapp.h>
#include <view.h>

class Home : public calassomys::WebApp {
    calassomys::View index;
public:
    Home(cppcms::service &srv, cppcms::json::value& cfg) : calassomys::WebApp(srv, cfg)
    {
        dispatcher().assign("",&Home::all,this);
        mapper().assign("");

        dispatcher().assign("/odd(/(.*))?",&Home::odd,this);
        mapper().assign("odd","/odd");

        dispatcher().assign("/even",&Home::even,this);
        mapper().assign("even","/even");

        dispatcher().assign("/prime",&Home::prime,this);
        mapper().assign("prime","/prime");

        index.setContent(config.get<string>("calassomys.webapp.web_content_path")+"index.html");
        index.setContentId("header", config.get<string>("calassomys.webapp.web_content_path") + config.get<string>("calassomys.header_page") );
        index.setContentId("footer", config.get<string>("calassomys.webapp.web_content_path") + config.get<string>("calassomys.footer_page") );

    }

    void all()
    {
        response().out() << index;
    }

    void prime()
    {
        response().out() << "2,3,5,7,...";
    }
    void odd()
    {
        response().out() << "1,3,5,7,9,...";
    }
    void even()
    {
        response().out() << "2,4,6,8,10,...";
    }
};



#endif // Home_H
