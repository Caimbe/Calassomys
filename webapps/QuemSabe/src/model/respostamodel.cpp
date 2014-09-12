#include "respostamodel.h"

RespostaModel::RespostaModel()
{
    dao = Dao::getInstance();
}

void RespostaModel::novaResposta(string idPergunta, Resposta &resposta)
{
    dao->insert(resposta);
}

