#include <loadwebapp.h>
#include "home.h"
#include "perguntar.h"


namespace calassomys {
    void LoadWebApp::loader()
    {
        attach( new Home(service(), settings), "/home");
        attach( new Perguntar(service(), settings), "/perguntar");
    }
}

CREATE
