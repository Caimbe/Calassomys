#ifndef PERGUNTAR_H
#define PERGUNTAR_H

#include <webapp.h>
#include <view.h>
#include "model/perguntamodel.h"

class Perguntar : public calassomys::WebApp {
    PerguntaModel model;
public:
    Perguntar(cppcms::service &srv, cppcms::json::value& cfg);
    void fazerPergunta();
    void novaPergunta();

};

#endif // PERGUNTAR_H
