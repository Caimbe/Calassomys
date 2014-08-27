#include "webappmanager.h"
#include <boost/filesystem.hpp>
#include <cppcms/json.h>
#include <dlfcn.h>
#include <fstream>

using namespace std;

namespace calassomys {

WebAppManager::WebAppManager(cppcms::service &srv) : cppcms::application(srv)
{
    configure(srv);
}

void WebAppManager::configure(cppcms::service &srv)
{
    auto webappsNames = findWebApp();
    for(string& name: webappsNames)
    {
        string path = settings().get<string>("calassomys.path_webapps") + "/" +name+ "/build/";
        WebAppPtr webApp = loadWebApp(path, name, srv);
        attach(	webApp,
                name,
                "/"+name+"{1}", // mapping
                "/"+name+"(/(.*))?", 1);   // dispatching
    }
}


std::vector<std::string> WebAppManager::findWebApp()
{
    using namespace boost::filesystem;
    string strDirWebApps = settings().get<string>("calassomys.path_webapps");
    path dirWebApp(strDirWebApps);
    if (!exists(dirWebApp) || !is_directory(dirWebApp)) {
        std::cerr << strDirWebApps << " not found" << std::endl;
        return std::vector<std::string>();
    }

    std::vector<std::string> webApps;
    directory_iterator dir_itr(dirWebApp);
    directory_iterator end_itr;

    for (; dir_itr != end_itr; ++dir_itr)
    {
        if (is_directory (dir_itr->status())){
            std::string str = dir_itr->path().filename().c_str();
            std::cout <<  str << std::endl;
            webApps.push_back( str );
        }
    }
    return webApps;
}

WebAppPtr WebAppManager::loadWebApp(std::string& path, std::string& name, cppcms::service &srv)
{
    void *handle;
    handle = dlopen((path+PREFIX_LIB+name+SUFIX_LIB).c_str(), RTLD_NOW);
    if (!handle)
    {
        printf("The error is %s", dlerror());
    }

    typedef WebAppPtr create_t(cppcms::service&);

    create_t* creat=(create_t*)dlsym(handle,"create");
    if (!creat)
    {
        cerr<<"The error is %s"<<dlerror();
    }
    return creat(srv);
}

}
