#ifndef PERGUNTAMODEL_H
#define PERGUNTAMODEL_H

#include "dao/dao.h"
#include "entity/pergunta.h"

class PerguntaModel
{
    DaoPrt dao;
public:
    PerguntaModel();
    int novaPergunta(Pergunta& pergunta);
};

#endif // PERGUNTAMODEL_H
