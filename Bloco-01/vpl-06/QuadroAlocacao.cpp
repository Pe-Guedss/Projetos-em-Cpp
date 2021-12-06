#include "QuadroAlocacao.hpp"

void QuadroAlocacao::inserir_alocacao (string codigo, string nome, string dia, string horario, string sala){
    Disciplina *dis = new Disciplina(nome, codigo);
    dis->inserir_alocacao(dia, horario, sala);

    this->quadro_alocacao.insert(std::pair<std::string, Disciplina>(codigo, *dis));
}

void QuadroAlocacao::remover_alocacao_disciplina(string codigo, string horario){
    this->quadro_alocacao[codigo].remover_alocacao(horario);
}

vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas(){
    std::vector<Disciplina> ret;
    int count = 0;

    for (std::map<std::string, Disciplina>::iterator it = this->quadro_alocacao.begin(); it != this->quadro_alocacao.end(); it++){
        if (it->second.alocacao.size() > count)
        {
            count = it->second.alocacao.size();
        }
    }
    for (std::map<std::string, Disciplina>::iterator it = this->quadro_alocacao.begin(); it != this->quadro_alocacao.end(); it++){
        if (it->second.alocacao.size() == count)
        {
            ret.push_back(it->second);
        }
    }
}

void QuadroAlocacao::imprimir_alocacao_completa(){
    for (std::map<std::string, Disciplina>::iterator it = this->quadro_alocacao.begin(); it != this->quadro_alocacao.end(); it++){
        it->second.imprimir_alocacao();
    }
}