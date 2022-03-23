#include "celular.hpp"

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.
int Celular::codigo = 0;

// ================================= JUSTIFICATIVA ===================================
// Função construtora da classe Celular, ela inicializa os atributos e faz o incremento da variável código que, segundo instruções do VPL, deveria ser incrementada sempre que um novo tipo de celular fosse inserido.
Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
  // TODO: Implemente este metodo
    codigo++;
    this->modelo = modelo;
    this->fabricante = fabricante;
    this->armazenamento = armazenamento;
    this->memoria = memoria;
    this->peso = peso;
    this->cor = cor;
    this->qtd = qtd;
    this->valor = valor;
    this->cod = codigo;
}

// ================================= JUSTIFICATIVA ===================================
// A função operator tem por objetivo auxiliar na ordenação de estruturas que não tem contrato de tipo (um dos assuntos do BLOCO-04) bem definido. Nesse caso, desejamos realizar a ordenação por ordem alfabética dos fabridantes. Caso um celular diferente possua o mesmo fabricante, devemos ordená-lo de acordo com o modelo.
// Uma explicação mais aprofundada será dada próxima aos loops de fabricante e modelo.
bool Celular::operator<(const Celular& other) {
    // TODO: Implemente este metodo. 
    // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
    // a fabricante antes do modelo do celular
    int i = 0;
    
    // ============================= LOOP FABRICANTE - JUSTIFICATIVA ================================
    // O iterador i é inicializado em 0 antes de começar este processo. Basicamente a função "operator <" recebe como ponteiro o elemento que está à sua esquerda (por exemplo, a < b, "a" seria recebido como o ponteiro) e realiza uma operação de comparação com o elemento da direita, que é recebido como parâmetro.
    // Este laço se aproveita do fato que as strings em C++ são elementos iteráveis, itera sobre cada um dos caracteres da string fazendo a comparação entre eles. Utilizando o fato de que caracteres podem ser comparados pela Tabela ASCII implicitamente no código, os caracteres são transformados para suas versões caixa baixa para não haver conflitos.
    // Os retornos são verdadeiro para o caso de o ponteiro recebido (no exemplo antes dado sendo "a") ser, de fato, menor que o valor recebido como parâmetro. Falso caso contrário. Caso as letras sejam simplesmente iguais, o iterador tem seu valor acrescido para encontrar o caractere seguinte.
    while ( (i < this->fabricante.length()) && (i < other.fabricante.length()) )
    {
        if ( tolower(this->fabricante[i]) < tolower (other.fabricante[i]) ) return true;

        else if ( tolower(this->fabricante[i]) > tolower(other.fabricante[i]) ) return false;

        ++i;
    }

    i = 0;

    // ============================= LOOP MODELO - JUSTIFICATIVA ================================
    // Para poupar espaço, este loop não será explicado tão detalhadamente, mas ele realiza basicamente as mesmas operações e segue o mesmo princípio do loop acima.
    while ( (i < this->modelo.length()) && (i < other.modelo.length()) )
    {
        if (tolower(this->modelo[i]) < tolower(other.modelo[i])) return true;

        else if ( tolower(this->modelo[i]) > tolower(other.modelo[i]) ) return false;

        ++i;
    }

    return false;
}