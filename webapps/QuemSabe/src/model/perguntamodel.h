#ifndef PERGUNTAMODEL_H
#define PERGUNTAMODEL_H

#include "dao/dao.h"
#include "entity/pergunta.h"
#include "entity/resposta.h"
#include "respostamodel.h"
#include <vector>

class PerguntaModel
{
    DaoPrt dao;
    RespostaModel respostaModel;
public:
    PerguntaModel();
    int novaPergunta(Pergunta& pergunta);
    int novaResposta(string idPergunta, Resposta& resposta);
    Pergunta getPergunta(string id);
    std::vector<Pergunta> getUltimasPerguntas();
};

#endif // PERGUNTAMODEL_H
