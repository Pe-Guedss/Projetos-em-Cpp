#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
    // TODO: Implemente este metodo
    /**
     * Lembre-se que as credenciais so podem ser inseridas com as seguintes
     * condicoes:
     * Condicao 1: A senha nao pode ter a seguencia '123456'.
     * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
     * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
     * Condicao 4: A senha nao pode ter caracteres em branco ' '.
     *
     * Exemplos de senhas invalidas:
     * 123456
     * test_123456
     * 123456_test
     * test_123456_test
     * senha test
     */
    if (checkPassword(password))
    {
        Usuario user = Usuario(login, password);
        this->m_passwords.insert({url, user});
        return;
    }
    return;
}

void GooglePassword::remove(const std::string& url) {
    // TODO: Implemente este metodo
    this->m_passwords.erase(url);
}

void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
    // TODO: Implemente este metodo
    /**
     * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
     * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
     * do usuario so podem ser atualizadas se a senha antiga for igual a senha
     * atual. Nao esqueca de verificar se o novo password tambem e valido.
     */
    if ( checkPassword(new_password) && 
        this->m_passwords.count(url) && 
        this->m_passwords[url].getPassword() == old_password ) {
        
        this->m_passwords[url].setLogin(login);
        this->m_passwords[url].setPassword(new_password);
        return;
    }
    return;
}

void GooglePassword::printPasswords() {
    // TODO: Implemente este metodo
    /**
     * Exemplo de saida:
     * www.site.com: login and password
     *
     */
    std::cout << this->m_passwords.size() << std::endl;
    for (std::map<std::string, Usuario>::const_iterator it = this->m_passwords.begin();
                                                        it != this->m_passwords.end();
                                                        ++it) {

        std::cout << it->first << ": ";
        std::cout << it->second.getLogin() << " and ";
        std::cout << it->second.getPassword() << std::endl;
    }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  // TODO: Implemente este metodo
  return !((password.find("123456") < password.length()) ||
           (password.length() > 50) ||
           (password.length() < 6) ||
           (password.find(" ") < password.length()));
}
