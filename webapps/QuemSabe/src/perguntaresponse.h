#ifndef PerguntaResponse_H
#define PerguntaResponse_H

#include <webapp.h>
#include <view.h>
#include "model/perguntamodel.h"

using namespace calassomys;

class PerguntaResponse : public calassomys::WebApp {
    PerguntaModel model;
public:
    PerguntaResponse(cppcms::service &srv, cppcms::json::value& cfg);
    void fazerPergunta();
    void novaPergunta();
    void novaResposta();
    void mostrarPergunta();

};

#endif // PERGUNTA_H
