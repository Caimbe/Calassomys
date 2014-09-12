#ifndef RESPOSTA_H
#define RESPOSTA_H

#include <dao/dao.h>

class Resposta
{
    long id;
    string autor;
    string resposta;
    string data;
    long idPergunta;

public:
    Resposta();
    Resposta(sql::ResultSet& rs);
    void operator >>(string& columnsValue);

    long getId() const;
    void setId(long value);
    string getAutor() const;
    void setAutor(const string &value);
    string getResposta() const;
    void setResposta(const string &value);
    string getData() const;
    void setData(const string &value);
    long getIdPergunta() const;
    void setIdPergunta(long value);
};

#endif // RESPOSTA_H
