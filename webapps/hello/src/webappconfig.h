#ifndef WEBAPPCONFIG_H
#define WEBAPPCONFIG_H

#include <webapp.h>

class WebAppConfig : public calassomys::WebApp
{
public:
    WebAppConfig(cppcms::service &srv);
    ~WebAppConfig();

};

extern "C" calassomys::WebAppPtr create(cppcms::service& srv);

#endif // WEBAPPCONFIG_H
