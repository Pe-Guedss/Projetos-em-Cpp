#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
    std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
    // Neste exemplo usaremos expressoes regulares para verificar se uma linha
    // eh valida ou nao.
    //
    // Esta expressao regular eh formada por cinco partes. Cada uma dessas
    // partes eh um dos tres tipos de padrao regular abaixo:
    //
    // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
    // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
    // \\d+ eh qualquer sequencia de um ou mais digitos
    std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

    // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
    // a expressao regular que acabamos de criar:
    return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
    //
    // Em geral eh mais facil ler dados de uma string se a string eh transformada
    // em um objeto do tipo stringstream:
    std::stringstream ss(str);
    //
    // Iremos ler os dados da string nestas tres variaveis abaixo:
    std::string nomePais;
    unsigned populacao, percUrbana;
    //
    // Como sabemos que a linha contem string int int, podemos fazer a leitura
    // facilmente usando o operador de streaming:
    ss >> nomePais >> populacao >> percUrbana;
    //
    // Note que precisamos arredondar o valor que serah impresso. O arredondamento
    // serah feito via a funcao floor. Ou seja, decimais serao sempre
    // arredondados para baixo:
    unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
    //
    // Uma vez encontrados os valores que precisam ser impressos, seguimos o
    // modelo do enunciado do exercicio:
    std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
        std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
    // TODO: Implemente este metodo
    std::regex regularExpr("[0-9\\s*]+");

    return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
    // TODO: Implemente este metodo:
    std::stringstream ss(str);
    int num, soma;
    soma = 0;

    while (ss >> num)
    {
        soma += num;
    }

    std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
    // TODO: Implemente este metodo
    std::string time1, gols1, time2, gols2, teste;
    std::stringstream ss(str);

    ss >> time1 >> gols1 >> time2 >> gols2;

    std::regex regExpStr("[A-Za-z]+");
    std::regex regExpNum("[0-9]+");

    if (!(ss >> teste))
    {
        return (std::regex_match(time1, regExpStr) &&
                std::regex_match(gols1, regExpNum) &&
                std::regex_match(time2, regExpStr) &&
                std::regex_match(gols2, regExpNum));
    }

    return false;
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
    // TODO: Implemente este metodo:
    std::string time1, gols1, time2, gols2;
    std::stringstream ss(str);

    ss >> time1 >> gols1 >> time2 >> gols2;

    if (gols1 > gols2)
    {
        std::cout << "Vencedor: " << time1 << std::endl;
    } 
    else if (gols2 > gols1)
    {
        std::cout << "Vencedor: " << time2 << std::endl;
    }
    else
    {
        std::cout << "Empate" << std::endl;
    }

}

void ContadorDePalavras::processaLinha(const std::string &str) {
    // TODO: Implemente este metodo:
    unsigned int contador = 0;
    std::stringstream ss(str);
    std::string palavra = "";

    while (ss >> palavra)
    {
        contador++;
    }

    std::cout << contador << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
    // TODO: Implemente este metodo
    std::regex regularExpr("[A-Za-z\\s*]+");

    return std::regex_match(str, regularExpr);
}

void InversorDeFrases::processaLinha(const std::string &str) {
    // TODO: Implemente este metodo:
    std::stringstream ss(str);
    std::string palavra, fraseInvertida;
    std::vector<std::string> aux;
    fraseInvertida = "";
    int cont = 0;

    while (ss >> palavra)
    {
        if (cont == 0)
        {
            aux.push_back(palavra);
            cont++;
            continue;
        }

        aux.push_back(palavra + " ");
    }
    
    for (int i = aux.size() - 1; i >= 0; i--)
    {
        fraseInvertida += aux[i];
    }
    

    std::cout << fraseInvertida << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
    std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
    // TODO: Implemente este metodo
    // Note que você pode usar uma expressao regular como:
    // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
    std::regex regularExpr (dateFormat);

    return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
    // TODO: Implemente este metodo:
    // Lembre-se que as iniciais dos meses sao:
    // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
    // "Nov", e "Dez".
    std::stringstream ss(str);
    int dia, mes, ano;
    char barra;
    std::vector<std::string> meses {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};

    ss >> dia >> barra >> mes >> barra >> ano;
    
    std::cout << meses[mes - 1] << std::endl;
}