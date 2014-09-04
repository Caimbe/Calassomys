#ifndef Home_H
#define Home_H

#include <webapp.h>
#include <view.h>

class Home : public calassomys::WebApp {
    calassomys::View index;
public:
    Home(cppcms::service &srv, cppcms::json::value& cfg);
    void all();
};



#endif // Home_H
