#ifndef HELLO_H
#define HELLO_H

#include <webapp.h>

class Hello : public calassomys::WebApp
{
public:
    Hello(cppcms::service& srv);
    void homer();
    void smile();
};


class Numbers : public calassomys::WebApp {
public:
    Numbers(cppcms::service &srv) : calassomys::WebApp(srv)
    {
        dispatcher().assign("",&Numbers::all,this);
        mapper().assign("");

        dispatcher().assign("/odd",&Numbers::odd,this);
        mapper().assign("odd","/odd");

        dispatcher().assign("/even",&Numbers::even,this);
        mapper().assign("even","/even");

        dispatcher().assign("/prime",&Numbers::prime,this);
        mapper().assign("prime","/prime");
    }

    void all()
    {
        response().out()
            << "<a href='" << url("/")       << "'>Top</a><br>"
            << "<a href='" << url("/letters")<< "'>Letters</a><br>"
            << "<a href='" << url(".")       << "'>All Numbers</a><br>"
            << "<a href='" << url("odd")     << "'>Odd Numbers</a><br>"
            << "<a href='" << url("even")    << "'>Even Numbers</a><br>"
            << "<a href='" << url("prime")   << "'>Prime Numbers</a><br>"
            << "1,2,3,4,5,6,7,8,9,10,...";
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



#endif // HELLO_H
