// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_alocacao.hpp"

int main() {
    char choice;

    std::string codigo, nome, dia, horario, sala;

    QuadroAlocacao* qa;

    while (cin >> choice)
    {
        switch (choice){
            case 'a':{
                cin >> codigo;
                cin >> nome;
                cin >> dia;
                cin >> horario;
                cin >> sala;

                qa->inserir_alocacao(codigo, nome, dia, horario, sala);
            break;
            }

            case 'm':{
                std::vector<Disciplina> ret = qa->recuperar_disciplinas_mais_ofertadas();
                for (std::vector<Disciplina>::iterator it = ret.begin(); it < ret.end(); it++)
                {
                    it->imprimir_alocacao();
                }
            break;
            }

            case 'r':{
                cin >> codigo;
                cin >> horario;

                qa->remover_alocacao_disciplina(codigo, horario);
            break;
            }

            case 'p':{
                qa->imprimir_alocacao_completa();
            break;
            }

            case 'b':{
                avaliacao_basica();
            break;
            }

            default:
            break;
        }

    }

    return 0;
}