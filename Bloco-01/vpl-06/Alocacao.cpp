#include "Alocacao.hpp"

Alocacao::Alocacao(string dia, string horario, string sala){
    this->dia = dia;
    this->horario = horario;
    this->sala = sala;
}

void Alocacao::imprimir_dados(){
    cout << this->dia << " " << this->horario << " " << this->sala << endl;
}