#ifndef WEBAPPCONFIG_H
#define WEBAPPCONFIG_H

#include <webapp.h>

class WebAppConfig : public calassomys::WebApp
{
    std::string nameWebApp;
public:
    WebAppConfig(cppcms::service &srv, std::string& nameWebApp);
    void serveFile(std::string file_name);

};


#endif // WEBAPPCONFIG_H
