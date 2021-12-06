#include "Disciplina.hpp"

Disciplina::Disciplina(string codigo, string nome){
    this->codigo = codigo;
    this->nome = nome;
}

void Disciplina::inserir_alocacao(string dia, string horario, string sala){
    this->alocacao.push_back(Alocacao(dia, horario, sala));
}

void Disciplina::remover_alocacao(string horario){
    for (std::list<Alocacao>::iterator it = this->alocacao.begin(); it != this->alocacao.end(); it++)
    {
        if (it->horario == horario)
        {
            this->alocacao.erase(it);
        }
        
    }
    
}

void Disciplina::imprimir_alocacao(){
    std::sort(this->alocacao.begin( ), this->alocacao.end( ), [](const Alocacao& a, const Alocacao& b){return a.horario < b.horario;});

    for (std::list<Alocacao>::iterator it = this->alocacao.begin(); it != this->alocacao.end(); it++){
        cout << this->codigo << " " << this->nome << " ";
        it->imprimir_dados();
    }

}