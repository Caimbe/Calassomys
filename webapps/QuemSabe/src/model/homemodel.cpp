#include "homemodel.h"

HomeModel::HomeModel()
{
}

std::vector<Pergunta> HomeModel::getUltimasPerguntas()
{
    return perguntaModel.getUltimasPerguntas();
}
