#ifndef FILA_H
#define FILA_H

struct No {
    int chave;
    No* proximo;

    No();
    No(int chave);
};

// Fila de números inteiros.
class Fila {
    public:
        // Representa uma exceção que ocorre quando a fila está vazia.
        // Ela não tem estado, já que toda fila vazia é igual.
        // Consequetemente, sua implementação é vazia.
        class ExcecaoFilaVazia {};
    
        // Constrói uma fila vazia.
        Fila();
        
        // Insere um elemento no fim da fila.
        void Inserir(int k);
        
        // Retorna o elemento no início da fila.
        // Lança uma exceção do tipo EmptyException caso a fila esteja vazia.
        int primeiro() const;

        // Retorna o elemento no fim da fila.
        // Lança uma exceção do tipo EmptyException caso a fila esteja vazia.
        int ultimo() const;

        // Remove o elemento no início da fila.
        // Lança uma exceção do tipo EmptyException caso a fila esteja vazia.
        void RemoverPrimeiro(); 
        
        // Retorna o número de elementos na fila.
        int tamanho() const;

        void insertHelp (No* current_node, No* insertion_node);
    private:
        No* primeiro_;    
        No* ultimo_;

        int size;
};

#endif  // FILA_H