#include <iostream>
using namespace std;

struct Processo{
    int _id;
    string _nome;
    int _prioridade;
    Processo* next;

    Processo(int id, std::string nome, int prioridade);
    
    void imprimir_dados();
};

struct ListaProcessos
{
    Processo* start = nullptr;

    void adicionar_processo(Processo* proc); // Obrigatória
    void ajuda_para_add_proc(Processo* node, Processo* proc);
    void troca_essa_porra(Processo* node, Processo* next, Processo* proc);

    Processo* remover_processo_maior_prioridade(); // Obrigatória

    Processo* remover_processo_menor_prioridade(); // Obrigatória

    Processo* remover_processo_por_id(int id); // Obrigatória

    void imprimir_lista(); // Obrigatória
};

Processo::Processo(int id, std::string nome, int prioridade){
    this->_id = id;
    this->_nome = nome;
    this->_prioridade = prioridade;
    this->next = nullptr;
}

void Processo::imprimir_dados(){
    cout << this->_id << " " << this->_nome << " " << this->_prioridade << endl;
}

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

int main() {

  ListaProcessos lp;
  
  Processo* proc_1;
  proc_1 = new Processo(2, "proc_1", 3);
  proc_1->imprimir_dados();
  
  Processo* proc_2;
  proc_2 = new Processo(25, "proc_2", 2);
  proc_2->imprimir_dados();
  
  Processo* proc_3;
  proc_3 = new Processo(20, "proc_3", 2);
  proc_3->imprimir_dados();

  Processo* proc_4;
  proc_4 = new Processo(12, "proc_4", 1);
  proc_4->imprimir_dados();
  
  Processo* proc_5;
  proc_5 = new Processo(5, "proc_5", 5);
  proc_5->imprimir_dados();

  lp.adicionar_processo(proc_1);
  lp.adicionar_processo(proc_2);
  lp.adicionar_processo(proc_3);
  lp.adicionar_processo(proc_4);
  lp.adicionar_processo(proc_5);

  
  cout << endl << endl;
  lp.imprimir_lista();

  cout << endl << endl;
  lp.remover_processo_maior_prioridade()->imprimir_dados();

  cout << endl << endl;
  lp.imprimir_lista();

  cout << endl << endl;
  lp.remover_processo_menor_prioridade()->imprimir_dados();

  cout << endl << endl;
  lp.imprimir_lista();

  cout << endl << endl;
  lp.remover_processo_por_id(20)->imprimir_dados();

  cout << endl << endl;
  lp.imprimir_lista();

  cout << endl << endl;

  return 0;
}