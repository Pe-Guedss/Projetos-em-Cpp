#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
using namespace std;
#include "Alocacao.hpp"

#include <algorithm>
#include <list>

struct Disciplina
{
    string codigo, nome;
    std::list<Alocacao> alocacao;

    Disciplina(string codigo, string nome);
    void inserir_alocacao(string dia, string horario, string sala);
    void remover_alocacao(string horario);
    void imprimir_alocacao();
};

#endif