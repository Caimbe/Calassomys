#ifndef WEBAPPCONFIG_H
#define WEBAPPCONFIG_H

#include <iwebappconfig.h>

class WebAppConfig : public iWebAppConfig
{
public:
    WebAppConfig();
    void configure(ServicePtr& service);
};

#endif // WEBAPPCONFIG_H
