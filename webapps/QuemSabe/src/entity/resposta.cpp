#include "resposta.h"

Resposta::Resposta()
{
}

Resposta::Resposta(sql::ResultSet &rs)
{
    id = rs.getInt64(1);
    autor = rs.getString(2);
    resposta = rs.getString(3);
    data = rs.getString(4);
}

void Resposta::operator >>(string &columnsValue)
{
    columnsValue+="resposta(autor, resposta, pergunta_id) ";
    columnsValue+="VALUES('"+autor+"', '"+resposta+"', '"+to_string(idPergunta)+"') ";
}

long Resposta::getId() const
{
    return id;
}

void Resposta::setId(long value)
{
    id = value;
}

string Resposta::getAutor() const
{
    return autor;
}

void Resposta::setAutor(const string &value)
{
    autor = value;
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



long Resposta::getIdPergunta() const
{
    return idPergunta;
}

void Resposta::setIdPergunta(long value)
{
    idPergunta = value;
}
