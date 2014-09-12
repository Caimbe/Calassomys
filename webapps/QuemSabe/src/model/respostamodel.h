#ifndef RESPOSTAMODEL_H
#define RESPOSTAMODEL_H

#include "dao/dao.h"
#include "entity/resposta.h"

class RespostaModel
{
    DaoPrt dao;
public:
    RespostaModel();
    void novaResposta(string idPergunta, Resposta& resposta);
};

#endif // RESPOSTAMODEL_H
