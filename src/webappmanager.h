#ifndef WEBAPPMANAGER_H
#define WEBAPPMANAGER_H

#include <cppcms/service.h>
#include <string>
#include <iwebappconfig.h>

class WebAppManager
{
    ServicePtr service;
    std::string pathBase;
public:
    WebAppManager(std::string pathBase);
    void run();

private:
    void configure();
    std::vector<std::string> findWebApp();
    WebAppConfigPtr loadWebApp(std::string& name);
};

#endif // WEBAPPMANAGER_H
