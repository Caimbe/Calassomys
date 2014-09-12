#include <loadwebapp.h>
#include "home.h"
#include "perguntaresponse.h"


namespace calassomys {
    void LoadWebApp::loader()
    {
        attach( new Home(service(), settings), "/home");
        attach( new PerguntaResponse(service(), settings), "/perguntar");
    }
}

CREATE
