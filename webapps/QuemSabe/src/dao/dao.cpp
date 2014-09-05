#include "dao.h"
#include <webapp.h>

DaoPrt Dao::instance;

Dao::Dao()
{
    string url = calassomys::WebApp::getConfig().get<string>("calassomys.connection_string");
    sql.open(url);
}

DaoPrt Dao::getInstance()
{
    if( ! instance)
        instance.reset(new Dao());

    return instance;
}

