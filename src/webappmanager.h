#ifndef WEBAPPMANAGER_H
#define WEBAPPMANAGER_H

#include <cppcms/service.h>
#include <string>
#include <webapp.h>

class WebAppManager
{
    ServicePtr service;
    std::vector<AppManager> webapps;
    std::string pathBase;
public:
    WebAppManager(std::string pathBase);
    void run();

private:
    void configure();
    std::vector<std::string> findWebApp();
    std::shared_ptr<AppManager> loadWebApp(std::string& name);
};

#endif // WEBAPPMANAGER_H
