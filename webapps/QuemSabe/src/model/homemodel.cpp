#include "homemodel.h"

HomeModel::HomeModel()
{
}

shared_ptr<vector<Pergunta> > HomeModel::getUltimasPerguntas()
{
    return perguntaModel.getUltimasPerguntas();
}
