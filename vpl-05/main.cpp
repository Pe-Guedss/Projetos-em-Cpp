// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"

#include "ListaProcessos.hpp"

int main() {
    char choice;

    cout << choice << endl << endl;

    int id;
    std::string name;
    int priority;
    Processo* proc;

    ListaProcessos lp;

    while (true)
    {
        cin >> choice;

        switch (choice)
        {
    // 'a id nome prioridade': comando para adicionar um novo processo na lista de acordo com os parâmetros passados. Você pode assumir que o nome sempre será uma única palavra.
        case 'a':
            cin >> id;
            cin >> name;
            cin >> priority;
            proc = new Processo(id, name, priority);
            lp.adicionar_processo(proc);
        break;

    // 'm': comando para remover o processo de MAIOR prioridade da lista.
        case 'm':
            proc = lp.remover_processo_maior_prioridade();
        break;

    // 'n': comando para remover o processo de MENOR prioridade da lista.
        case 'n':
            proc = lp.remover_processo_menor_prioridade();
        break;

    // 'r id': comando para remover um processo da lista de acordo com o ID informado.
        case 'r':
            cin >> id;
            proc = lp.remover_processo_por_id(id);
        break;

    // 'p': comando para imprimir a lista.
        case 'p':
            lp.imprimir_lista();
        break;

    // 'b': deve chamar a função 'avaliacao_basica()' implementada no arquivo "avaliacao_basica_escalonador.hpp" (já incluído no main.cpp). Essa função faz uma avaliação do código (não apenas dos resultados).
        case 'b':
            avaliacao_basica();
        break;
        
        default:
            break;
        }
    }

    return 0;
}