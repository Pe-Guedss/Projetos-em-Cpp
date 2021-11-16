#include "ListaProcessos.hpp"

void ListaProcessos::adicionar_processo(Processo* proc){

    if (start != nullptr) {
        ajuda_para_add_proc(start, proc);
    } else {
        start = proc;
    }
}

void ListaProcessos::troca_essa_porra(Processo* node, Processo* next, Processo* proc){
    if (node->next == next){
        node->next = proc;
    }
    else{
        troca_essa_porra(node->next, next, proc);
    }
}

void ListaProcessos::ajuda_para_add_proc(Processo* node, Processo* proc){
    if (node->_prioridade > proc->_prioridade){
        if (node->next == nullptr){
            node->next = proc;
        } else{
            ajuda_para_add_proc(node->next, proc);
        }
    } 
    else if (node->_prioridade < proc->_prioridade){
        if (node == start){
            start = proc;
            proc->next = node;
        } else {
            proc->next = node;
            troca_essa_porra(start, node, proc);
        }
    }
    else{
        if (node->next == nullptr){
            node->next = proc;
        } else{
            ajuda_para_add_proc(node->next, proc);
        }
    }
}

Processo* ListaProcessos::remover_processo_maior_prioridade(){
    Processo* aux;
    aux = start;
    start = start->next;
    return aux;
}

Processo* ListaProcessos::remover_processo_menor_prioridade(){
    Processo* aux;
    aux = start;
    while (aux->next->next != nullptr)
    {
        aux = aux->next;
    }
    Processo* ret;
    ret = aux->next;
    aux->next = nullptr;
    return ret;
}

Processo* ListaProcessos::remover_processo_por_id(int id){
    if (start->_id == id)
    {
        return this->remover_processo_maior_prioridade();
    }
    else
    {
        Processo* aux;
        aux = start;
        while (aux->next->_id != id)
        {
            if (aux->next->next == nullptr && aux->next->_id != id)
            {
                return nullptr;
            }
            aux = aux->next;
        }
        Processo* ret;
        ret = aux->next;
        aux->next = aux->next->next;
        return ret;
    }
    
}

void ListaProcessos::imprimir_lista(){
    Processo* aux;
    aux = start;
    while (aux->next != nullptr)
    {
        aux->imprimir_dados();
        aux = aux->next;
    }
    aux->imprimir_dados();
}