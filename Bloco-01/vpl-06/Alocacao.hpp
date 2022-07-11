#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <iostream>
using namespace std;

struct Alocacao
{
    string dia, horario, sala;
    Alocacao(string dia, string horario, string sala);
    void imprimir_dados();
};

#endif