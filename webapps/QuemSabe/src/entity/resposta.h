#ifndef RESPOSTA_H
#define RESPOSTA_H

#include <dao/dao.h>

class Resposta
{
    long id;
    string nome;
    string resposta;
    string data;

public:
    Resposta();
    Resposta(sql::ResultSet& rs);
    void operator >>(string& columnsValue);

    long getId() const;
    void setId(long value);
    string getNome() const;
    void setNome(const string &value);
    string getResposta() const;
    void setResposta(const string &value);
    string getData() const;
    void setData(const string &value);
};

#endif // RESPOSTA_H
