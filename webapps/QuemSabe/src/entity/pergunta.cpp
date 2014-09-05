#include "pergunta.h"

Pergunta::Pergunta(string titulo, string descricao)
{
    this->titulo = titulo;
    this->descricao = descricao;
}

cppdb::statement& Pergunta::operator>>(cppdb::statement& sql)
{
    return sql << "pergunta(titulo, descricao) "
                  "VALUES(?,?)"
                  << titulo << descricao;
}
