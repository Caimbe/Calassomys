#ifndef RESPOSTAMODEL_H
#define RESPOSTAMODEL_H

#include "dao/dao.h"
#include "entity/resposta.h"

class RespostaModel
{
    DaoPrt dao;
public:
    RespostaModel();
    long long novaResposta(string idPergunta, Resposta& resposta);
    shared_ptr<vector<Resposta> > getRespostas(string idPergunta);
};

#endif // RESPOSTAMODEL_H
