#ifndef WEBAPPMANAGER_H
#define WEBAPPMANAGER_H

#include <cppcms/application.h>
#include <webapp.h>

namespace calassomys {

class WebAppManager : public cppcms::application
{
public:
    WebAppManager(cppcms::service &service);
private:
    void configure(cppcms::service &srv);
    std::vector<std::string> findWebApp();
    WebAppPtr loadWebApp(std::string& path, std::string& name, cppcms::service &srv);
};

} // calassomys

#endif // WEBAPPMANAGER_H
