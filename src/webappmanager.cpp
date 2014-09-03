#include "webappmanager.h"
#include <boost/filesystem.hpp>
#include <cppcms/json.h>
#include <dlfcn.h>
#include <fstream>
#include <booster/log.h>

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
        BOOSTER_INFO("calossomys") << "Loading: " << name;
        string path = settings().get<string>("calassomys.path_webapps") + "/" +name+ "/build/";
        WebAppPtr webApp = loadWebApp(path, name, srv);
        if(webApp)
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
        BOOSTER_ERROR("calossomys") << strDirWebApps << " not found";
        return std::vector<std::string>();
    }

    std::vector<std::string> webApps;
    directory_iterator dir_itr(dirWebApp);
    directory_iterator end_itr;

    for (; dir_itr != end_itr; ++dir_itr)
    {
        if (is_directory (dir_itr->status())){
            std::string str = dir_itr->path().filename().c_str();
            webApps.push_back( str );
        }
    }
    return webApps;
}

WebAppPtr WebAppManager::loadWebApp(std::string& path, std::string& name, cppcms::service &srv)
{
    void *handle;
    handle = dlopen((path+PREFIX_LIB+name+SUFIX_LIB).c_str(), RTLD_NOW);
    if (handle)
    {
        typedef WebAppPtr create_t(cppcms::service&, std::string&);

        create_t* creat=(create_t*)dlsym(handle,"create");
        if (creat)
        {
            return creat(srv, name);
        }
    }

    BOOSTER_ERROR("calassomys") << dlerror();
    return NULL;
}

}
