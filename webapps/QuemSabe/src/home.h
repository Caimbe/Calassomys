#ifndef Home_H
#define Home_H

#include <webapp.h>
#include <view.h>
#include "model/homemodel.h"

class Home : public calassomys::WebApp {
    HomeModel model;
public:
    Home(cppcms::service &srv, cppcms::json::value& cfg);
    void inicio();
};



#endif // Home_H
