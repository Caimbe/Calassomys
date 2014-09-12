#ifndef HOMEMODEL_H
#define HOMEMODEL_H

#include "perguntamodel.h"
#include <vector>

class HomeModel
{
    PerguntaModel perguntaModel;
public:
    HomeModel();
    std::vector<Pergunta> getUltimasPerguntas();
};

#endif // HOMEMODEL_H
