#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <fstream>
#include <booster/log.h>
#include "webappmanager.h"

using namespace std;
using namespace calassomys;

int main(int argc,char ** argv)
{
    try {
        string pathBase = argv[0];
        pathBase = pathBase.substr(0, pathBase.rfind('/'));
        pathBase = pathBase.substr(0, pathBase.rfind('/'));
        ifstream fileSetting(pathBase+"/etc/calassomys.conf");
        cppcms::json::value settings;
        settings.load(fileSetting, true);
        cppcms::service service(settings);
        settings["path_run_time"] = pathBase;
        service.applications_pool().mount(cppcms::applications_factory<WebAppManager>());

        BOOSTER_NOTICE("calassomys") << "Server Up!";
        service.run();
    }
    catch(std::exception const &e) {
        BOOSTER_ERROR("calassomys") << e.what()<<std::endl;
        BOOSTER_ERROR("calassomys") << booster::trace(e);
    }
    catch(...) {
        BOOSTER_ERROR("calassomys") << "Erro Desconhecido!";
    }

    BOOSTER_NOTICE("calassomys") << "Server Down!";
}
