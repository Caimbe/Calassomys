#ifndef HOMEMODEL_H
#define HOMEMODEL_H

#include "perguntamodel.h"
#include <vector>

class HomeModel
{
    PerguntaModel perguntaModel;
public:
    HomeModel();
    shared_ptr<vector<Pergunta> > getUltimasPerguntas();
};

#endif // HOMEMODEL_H
