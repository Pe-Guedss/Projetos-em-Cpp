#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
    // TODO: Implemente este metodo.
    /*
    * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
    *
    * Exemplos:
    * 1X Hamburguer X-tudo artesanal.
    * 1X Hamburguer X-tudo simples.
    */
    char aux1[20];
    std::string str = "";

    std::sprintf(aux1, "%dX Hamburguer ", this->getQtd());
    str += std::string(aux1);
    str += this->tipo;

    if (this->artesanal)
    {
        str += " artesanal.";
    } else
    {
        str += " simples.";
    }
    
    return str;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
    // TODO: Implemente este metodo.
    this->tipo = tipo;
    this->artesanal = artesanal;
    this->m_qtd = qtd;
    this->m_valor_unitario = valor_unitario;
}