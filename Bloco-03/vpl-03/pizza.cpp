#include "pizza.hpp"

std::string Pizza::descricao() const {
    // TODO: Implemente este metodo.
    /*
    * Note que aqui voce deve retornar uma descricao detalhada da pizza.
    *
    * Exemplos:
    * 2X Pizza Calabresa, 4 pedacos e borda recheada.
    * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
    */
    char aux1[20];
    char aux2[20];
    std::string str = "";

    std::sprintf(aux1, "%dX Pizza ", this->getQtd());
    str += std::string(aux1);
    str += this->sabor;
    std::sprintf(aux2, ", %d pedacos ", this->pedacos);
    str += std::string(aux2);

    if (this->borda_recheada)
    {
        str += "e borda recheada.";
    } else
    {
        str += "e sem borda recheada.";
    }
    
    return str;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
    // TODO: Implemente este metodo.
    this->sabor = sabor;
    this->pedacos = pedacos;
    this->borda_recheada = borda_recheada;
    this->m_qtd = qtd;
    this->m_valor_unitario = valor_unitario;
}