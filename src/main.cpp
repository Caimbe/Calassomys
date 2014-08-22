#include <cppcms/service.h>
#include <cppcms/applications_pool.h>
#include <iostream>

#include "webappmanager.h"

using namespace std;


int main(int argc, char** argv)
{
    cout << "Server Up!" << endl;
    try {
        WebAppManager manager(argv[0]);
        manager.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    cout << "Server Dow!" << endl;
    return 0;
}

