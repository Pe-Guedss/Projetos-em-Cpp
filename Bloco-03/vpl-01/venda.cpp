#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

// Esta função é bastante simples. Ela simplesmente faz a inserção de um novo celular, recebido por referência (apesar de ser tratado como constante, um truque de otimização que não está no escopo desta justificativa) ao fim da lista chamada "m_celulares", que é declarada no arquivo de cabeçalho "venda.hpp", que também não está no escopo desta justificativa (creio eu).
void Venda::adicionaCelular(const Celular& celular) {
    // TODO: Implemente este metodo
    this->m_celulares.push_back(celular);
}

// Esta função também é bastante simples, ela se aproveita do fato de já haver a definição de "operator <" para estruturas do tipo "celular", que são justamente o tipo dos elementos da lista "m_celulares". Como o contrato de tipo já foi definido e explicado, a simples utilização do método ".sort()" é o suficiente para ordenar os elementos por febricante e modelo sem maiores esforços.
void Venda::ordena() {
    // TODO: Implemente este metodo
    // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
    // a fabricante antes do modelo do celular
    this->m_celulares.sort();
}

// Para esta função, o usuário deve fornecer o código do celular, que é informado na instanciação deste objeto e incrementado por um a cada nova instanciação, assim como já foi explicado no arquivo "celular.cpp". Além disso também deve ser informada a quantidade de novos celulares que serão adicionados ao estoque.
// A função faz um loop por todos os elementos da lista "m_celulares" procurando pelo que tenha o valor da propriedade "cod" igual à que foi recebida como parâmetro. Quando encontra, faz a adição do novo carregamento, caso não encontre, não faz nada.
void Venda::recarregaEstoque(int cod, int qtd) {
    // TODO: Implemente este metodo
    for (std::list<Celular>::iterator it = this->m_celulares.begin();
                                      it != this->m_celulares.end();
                                      ++it)
    {
        if (it->cod == cod)
        {
            it->qtd += qtd;
        }
    }
}

// Esta função efetua a venda de uma quantidade "qtd" de celulares, cuja instância da classe possui o código equivalente ao parâmetro "cod" recebido. É feito um loop por todos os elementos da lista "m_celulares", quando um que possua o mesmo código (que é um valor único para cada instância), verifica se a quantidade de celulares disponíveis em estoque é pelo menos igual à de celulares que se quer vender, caso seja, a venda é efetuada.
void Venda::efetuaVenda(int cod, int qtd) {
    // TODO: Implemente este metodo
    /**
     * Observe na descricao do enunciado que nao e permita a venda de um modelo
     * cuja quantidade seja maior que a quantidade atual em estoque.
     * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
     * partir de 6 unidades devem ser ignoradas.
     */
    for (std::list<Celular>::iterator it = this->m_celulares.begin();
                                      it != this->m_celulares.end();
                                      ++it)
    {
        if (it->cod == cod)
        {
            if (it->qtd >= qtd)
            {
                it->qtd -= qtd;
            }
            return;
        }
    }
}

// Esta função recebe um fabricante de celulares e um desconto, itera sobre todos os elementos da lista "m_celulares" e, para todos que possuírem o fabricante igual ao que foi recebido como parâmetro, aplica o desconto dado.
// Esta questão possui uma forma muito específica de se calcular a porcentagem, penalizando com perda de muitos pontos todos os alunos que não acertarem exatamente as casas decimais do novo valor com o desconto. Sendo assim, tive que testar várias formas de se calcular a porcentagem, até que encontrei essa que funcionou. Quando vi que havia funcionado, parei de tentar.
void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
    // TODO: Implemente este metodo
    for (std::list<Celular>::iterator it = this->m_celulares.begin();
                                      it != this->m_celulares.end();
                                      ++it)
    {
        if (it->fabricante == fabricante)
        {
            it->valor -= (it->valor * desconto)/100;
        }
    }
}

// Recebe um código como parâmetro, itera sobre a lista "m_celulares" até encontrar o único elemento que possui o código igual ao recebido para removê-lo da lista de celulares. Para realizae esta operação, utilizei o método ".erase()", que é o mais indicado segundo a documentação para remover itens de uma lista. Ele aceita uma posição como parâmetro ou mesmo o próprio elemento que se deseja remover, como estava usando um "iterator", achei mais prático enviar o elemento.
void Venda::removeModelo(int cod) {
    // TODO: Implemente este metodo
    for (std::list<Celular>::iterator it = this->m_celulares.begin();
                                      it != this->m_celulares.end();
                                      ++it)
    {
        if (it->cod == cod)
        {
            this->m_celulares.erase(it);
            break;
        }
    }
}

// Esta função faz a impressão de todos os celulares armazenados na lista "m_celulares". Ele deve seguir uma formatação específica definida no enunciado do VPL, portanto, há vários "std::cout" para que a saída seja exatamente como se deseja. Ao final há também a definição de precisão de casas decimais como sendo de "2" para imprivir o valor do celular pelo quai se está iterando.
void Venda::imprimeEstoque() const {
    // TODO: Implemente este metodo.
    /**
     * Aqui voce tera que imprimir a lista de celulares em estoque com as
     * restricoes descritas no enunciado do problema. Notem no exemplo que a
     * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
     * apenas um item em estoque de determinado modelo de celular, voce tera que
     * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
     * celulares com pelo menos um item em estoque deverao ser exibidos.
     */
    for (std::list<Celular>::const_iterator it = this->m_celulares.begin();
                                      it != this->m_celulares.end();
                                      ++it)
    {
        if (it->qtd > 0)
        {
            std::cout << it->fabricante << " " << it->modelo << ", ";
            std::cout << it->armazenamento << "GB" << ", ";
            std::cout << it->memoria << "GB RAM" << ", ";
            std::cout << it->peso*1000 << " gramas, ";
            std::cout << (char) toupper(it->cor[0]) << it->cor.substr(1) << ", ";
            if (it->qtd == 1)
            {
                std::cout << it->qtd << " restante, ";
            }
            else
            {
                std::cout << it->qtd << " restantes, ";
            }
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "R$ " << it->valor << std::endl;
            std::cout << std::fixed << std::setprecision(0);
        }
    }
}