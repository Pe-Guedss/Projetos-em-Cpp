#include "japonesa.hpp"

std::string Japonesa::descricao() const {
    // TODO: Implemente este metodo.
    /*
    * Note que aqui voce deve retornar uma descricao detalhada da comida
    * japonesa.
    *
    * Exemplos:
    * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
    * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
    */
    // char str[100];

    // std::sprintf(str, "%dX Comida japonesa - %s, %d sushis, %d temakis e %d hots", 
    // this->getQtd(), 
    // this->combinado, 
    // this->sushi,
    // this->temaki,
    // this->hots);

    // return std::string(str);

    char aux1[30];
    char aux2[20];
    char aux3[20];
    char aux4[20];
    std::string str = "";

    std::sprintf(aux1, "%dX Comida japonesa - ", this->getQtd());
    str += std::string(aux1);
    str += this->combinado;
    std::sprintf(aux2, ", %d sushis, ", this->sushi);
    str += std::string(aux2);
    std::sprintf(aux3, "%d temakis e ", this->temaki);
    str += std::string(aux3);
    std::sprintf(aux4, "%d hots.", this->hots);
    str += std::string(aux4);
    
    return str;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushi,
                   int temaki,
                   int hots,
                   int qtd,
                   float valor_unitario) {
    // TODO: Implemente este metodo.
    this->combinado = combinado;
    this->sushi = sushi;
    this->temaki = temaki;
    this->hots = hots;
    this->m_qtd = qtd;
    this->m_valor_unitario = valor_unitario;
}