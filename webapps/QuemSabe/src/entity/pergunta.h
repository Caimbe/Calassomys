#ifndef Pergunta_H
#define Pergunta_H

#include <iostream>
#include <cppdb/frontend.h>
using namespace std;

class Pergunta
{
    string titulo;
    string descricao;
public:
    Pergunta(string titulo, string descricao);

    cppdb::statement& operator>>(cppdb::statement& out);
};

#endif // Pergunta_H
