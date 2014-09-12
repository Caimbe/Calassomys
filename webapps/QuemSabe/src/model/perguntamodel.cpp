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

int PerguntaModel::novaResposta(string idPergunta, Resposta &resposta)
{
    return respostaModel.novaResposta(idPergunta, resposta);
}

Pergunta PerguntaModel::getPergunta(string id)
{
    auto vec = dao->select<Pergunta>("pergunta", "id="+id);
    if( ! vec->empty())
        return vec->at(0);

    return Pergunta();
}

shared_ptr<vector<Resposta> > PerguntaModel::getRespostas(string idPergunta)
{
    return respostaModel.getRespostas(idPergunta);
}

shared_ptr<vector<Pergunta> > PerguntaModel::getUltimasPerguntas()
{
    return dao->select<Pergunta>("pergunta", "", "ORDER BY data DESC LIMIT 20");
}
