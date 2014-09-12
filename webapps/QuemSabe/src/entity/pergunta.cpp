#include "pergunta.h"

#define TABLE "pergunta"

Pergunta::Pergunta()
{
    id = -1;
}

Pergunta::Pergunta(string titulo, string descricao)
{
    this->titulo = titulo;
    this->descricao = descricao;
}
Pergunta::Pergunta(sql::ResultSet &rs)
{
    id = rs.getInt64(1);
    titulo = rs.getString(2);
    descricao = rs.getString(3);
    data = rs.getString(4);
}

void Pergunta::operator>>(string& columnsValue)
{
    columnsValue+=TABLE"(titulo, descricao)";
    columnsValue+=" VALUES('"+titulo+"', '"+descricao+"') ";
}




string Pergunta::getDescricao() const
{
    return descricao;
}

void Pergunta::setDescricao(const string &value)
{
    descricao = value;
}




string Pergunta::getData() const
{
    return data;
}

void Pergunta::setData(const string& value)
{
    data = value;
}

string Pergunta::getTitulo() const
{
    return titulo;
}

void Pergunta::setTitulo(const string &value)
{
    titulo = value;
}

long Pergunta::getId() const
{
    return id;
}

void Pergunta::setId(long value)
{
    id = value;
}
