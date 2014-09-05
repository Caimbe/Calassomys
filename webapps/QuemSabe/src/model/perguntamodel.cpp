#include "perguntamodel.h"
#include "entity/pergunta.h"

PerguntaModel::PerguntaModel()
{
    dao = Dao::getInstance();
}

int PerguntaModel::novaPergunta(Pergunta &pergunta)
{
    dao->insert(pergunta);
}
