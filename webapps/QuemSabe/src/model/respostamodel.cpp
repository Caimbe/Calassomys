#include "respostamodel.h"

RespostaModel::RespostaModel()
{
    dao = Dao::getInstance();
}

long long RespostaModel::novaResposta(string idPergunta, Resposta &resposta)
{
    return dao->insert(resposta);
}



shared_ptr<vector<Resposta> > RespostaModel::getRespostas(std::string idPergunta)
{
    return dao->select<Resposta>("resposta", "pergunta_id="+idPergunta);
}
