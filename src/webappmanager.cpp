#include "webappmanager.h"
#include <boost/filesystem.hpp>
#include<dlfcn.h>
#include <fstream>

using namespace std;

WebAppManager::WebAppManager(std::string path)
{
    pathBase = path.substr(0, path.rfind('/'));
    pathBase = pathBase.substr(0, pathBase.rfind('/'));
    ifstream fileSetting(pathBase+"/etc/calassomys.conf");
    cppcms::json::value settings;
    settings.load(fileSetting, true);
    service.reset( new cppcms::service(settings) );
    configure();
}

void WebAppManager::run()
{
    service->run();
}

void WebAppManager::configure()
{
    auto webappsNames = findWebApp();
    for(string& webappName: webappsNames)
    {
        webappName = pathBase+"/webapps/"+webappName+"/build/lib"+webappName;
        WebAppConfigPtr config = loadWebApp(webappName);
        config->configure(service);
    }
}

std::vector<std::string> WebAppManager::findWebApp()
{
    using namespace boost::filesystem;
    string strDirWebApps = pathBase+"/webapps";
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

WebAppConfigPtr WebAppManager::loadWebApp(std::string& name)
{
    void *handle;
    handle = dlopen((name+SUFIX_LIB).c_str(), RTLD_NOW);
    if (!handle)
    {
        printf("The error is %s", dlerror());
    }

    typedef WebAppConfigPtr create_t();

    create_t* creat=(create_t*)dlsym(handle,"create");
    if (!creat)
    {
        cerr<<"The error is %s"<<dlerror();
    }
    return creat();
}
