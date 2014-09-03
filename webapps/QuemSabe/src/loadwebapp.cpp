#include <loadwebapp.h>
#include "home.h"


namespace calassomys {
    void LoadWebApp::loader()
    {
        attach( new Home(service(), settings), "/home");
    }
}

CREATE
