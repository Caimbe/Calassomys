#ifndef Pergunta_H
#define Pergunta_H

#include "dao/dao.h"
#include <iostream>
using namespace std;

class Pergunta
{
    long id;
    string titulo;
    string descricao;
    string data;
public:
    Pergunta();
    Pergunta(string titulo, string descricao);
    Pergunta(sql::ResultSet& rs);
    void operator >>(string& columnsValue);

    string getData() const;
    void setData(const string& value);
    string getDescricao() const;
    void setDescricao(const string &value);
    string getTitulo() const;
    void setTitulo(const string &value);
    long getId() const;
    void setId(long value);
};

#endif // Pergunta_H
