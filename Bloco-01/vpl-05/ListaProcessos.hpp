#ifndef LISTAPROCESSOS_H
#define LISTAPROCESSOS_H

#include <iostream>
#include "Processo.hpp"

using namespace std;

struct ListaProcessos
{
    Processo* start = nullptr;

    void adicionar_processo(Processo* proc);
    void ajuda_para_add_proc(Processo* node, Processo* proc);
    void troca_essa_porra(Processo* node, Processo* next, Processo* proc);

    Processo* remover_processo_maior_prioridade();

    Processo* remover_processo_menor_prioridade();

    Processo* remover_processo_por_id(int id);

    void imprimir_lista();
};

#endif