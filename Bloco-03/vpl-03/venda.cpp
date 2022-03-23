#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
    // TODO: Implemente este metodo
    /**
     * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
     */
    for (auto it : this->m_pedidos)
    {
        delete it;
    }
}

void Venda::adicionaPedido(Pedido* p) {
    // TODO: Implemente este metodo
    this->m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
    // TODO: Implemente este metodo
    /**
     * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
     * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
     * de pedidos processados.
     */
    float totalVendas = 0;
    int totalPedidos = 0;

    for (auto it : this->m_pedidos)
    {
        totalPedidos++;
        std::cout << "Pedido " << totalPedidos << std::endl;
        std::cout << it->resumo() << std::endl;
        totalVendas += it->calculaTotal();
    }
    
    std::cout << "Relatorio de Vendas" << std::endl;
    std::cout << std::setprecision(2);
    std::cout << std::fixed;
    std::cout << "Total de vendas R$ " << totalVendas << std::endl;
    std::cout << "Total de pedidos: " << totalPedidos << std::endl;
}