#include "resposta.h"


long Resposta::getId() const
{
    return id;
}

void Resposta::setId(long value)
{
    id = value;
}

string Resposta::getNome() const
{
    return nome;
}

void Resposta::setNome(const string &value)
{
    nome = value;
}

string Resposta::getResposta() const
{
    return resposta;
}

void Resposta::setResposta(const string &value)
{
    resposta = value;
}

string Resposta::getData() const
{
    return data;
}

void Resposta::setData(const string &value)
{
    data = value;
}
Resposta::Resposta()
{
}

Resposta::Resposta(sql::ResultSet &rs)
{
    id = rs.getInt64(1);
    nome = rs.getString(2);
    resposta = rs.getString(3);
    data = rs.getString(4);
}

void Resposta::operator >>(string &columnsValue)
{
    columnsValue+="resposta(nome, resposta) ";
    columnsValue+="VALUES('"+nome+"', '"+resposta+"') ";
}
