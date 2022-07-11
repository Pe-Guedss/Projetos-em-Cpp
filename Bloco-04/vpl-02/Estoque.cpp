#include <string>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    // TODO
    if (this->estoque.find(mercadoria) != this->estoque.end())
    {
        this->estoque[mercadoria] += qtd;
    }
    else
    {
        this->estoque.insert(std::pair<std::string, unsigned int>(mercadoria, qtd));
    }
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    // TODO
    if (this->estoque.find(mercadoria) != this->estoque.end())
    {
        this->estoque[mercadoria] -= qtd;
    }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    // TODO
    for (std::map<std::string, unsigned int>::const_iterator it = this->estoque.cbegin();
                                                       it != this->estoque.cend();
                                                       ++it)
    {
        if (it->first == mercadoria)
        {
            return it->second;
        }
    }
    return 0;
}

void Estoque::imprime_estoque() const {
    // TODO
    for (std::map<std::string, unsigned int>::const_iterator it = this->estoque.cbegin(); 
                                                       it != this->estoque.cend(); 
                                                       ++it)
    {
        std::cout << it;
    }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
    // TODO
    for (std::map<std::string, unsigned int>::const_iterator it = rhs.estoque.cbegin(); 
                                                       it != rhs.estoque.cend(); 
                                                       ++it)
    {
        this->add_mercadoria(it->first, it->second);
    }
    return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
    // TODO
    for (std::map<std::string, unsigned int>::const_iterator it = rhs.estoque.cbegin(); 
                                                       it != rhs.estoque.cend(); 
                                                       ++it)
    {
        this->sub_mercadoria(it->first, it->second);
    }
    return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
    // TODO
    for (std::map<std::string, unsigned int>::const_iterator it = rhs.estoque.cbegin(); 
                                                       it != rhs.estoque.cend(); 
                                                       ++it)
    {
        if (lhs.estoque.find(it->first) != lhs.estoque.end())
        {
            if (lhs.estoque[it->first] < it->second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    for (std::map<std::string, unsigned int>::const_iterator it = lhs.estoque.cbegin(); 
                                                       it != lhs.estoque.cend(); 
                                                       ++it)
    {
        if (rhs.estoque.find(it->first) == rhs.estoque.end())
        {
            
            return false;
        }
    }
    return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
    // TODO
    for (std::map<std::string, unsigned int>::const_iterator it = rhs.estoque.cbegin(); 
                                                       it != rhs.estoque.cend(); 
                                                       ++it)
    {
        if (lhs.estoque.find(it->first) != lhs.estoque.end())
        {
            if (lhs.estoque[it->first] > it->second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

std::ostream& operator << (std::ostream& out, 
                           std::map<std::string, unsigned int>::const_iterator const& mercadoria) {
    return out << mercadoria->first << ", " << mercadoria->second << std::endl;
}
