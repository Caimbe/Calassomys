#include <loadwebapp.h>
#include "hello.h"


namespace calassomys {
    void LoadWebApp::loader()
    {
        attach(	new Hello(service()));
        attach( new Numbers(service()), "/numbers");
    }
}

CREATE


