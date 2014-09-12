#include "dao.h"
#include <webapp.h>

DaoPrt Dao::instance;

Dao::Dao()
{
    string url = calassomys::WebApp::getConfig().get<string>("quemsabe.db.url");
    string user = calassomys::WebApp::getConfig().get<string>("quemsabe.db.user");
    string password = calassomys::WebApp::getConfig().get<string>("quemsabe.db.password");
    string database = calassomys::WebApp::getConfig().get<string>("quemsabe.db.database");

    sql::Driver *driver = get_driver_instance();
    connection.reset(driver->connect("tcp://127.0.0.1:3306", user, password));
    connection->setSchema(database);
}

DaoPrt Dao::getInstance()
{
    if( ! instance)
        instance.reset(new Dao());

    return instance;
}

