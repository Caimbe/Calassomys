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

Pergunta PerguntaModel::getPergunta(string id)
{
    const auto& vec = dao->select<Pergunta>("pergunta", "id="+id);
    if( ! vec.empty())
        return vec[0];

    return Pergunta();
}

std::vector<Pergunta> PerguntaModel::getUltimasPerguntas()
{
    return dao->select<Pergunta>("pergunta", "", "ORDER BY data DESC LIMIT 20");
}
