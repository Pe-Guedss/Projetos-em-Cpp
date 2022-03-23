#include "fila.h"

No::No() {
    this->chave = 0;
    this->proximo = nullptr;
}
No::No(int chave) {
    this->chave = chave;
    this->proximo = nullptr;
}

Fila::Fila() {
    // TODO
    this->size = 0;

    this->primeiro_ = new No ();
    this->ultimo_ = new No ();
}

void Fila::insertHelp (No* currentNode, No* insertionNode) {
    if (currentNode->proximo == nullptr)
    {
        currentNode->proximo = insertionNode;
    }
    else
    {
        insertHelp(currentNode->proximo, insertionNode);
    }
}

void Fila::Inserir(int k) {
    // TODO
    No* insertionNode;
    insertionNode = new No(k);
    
    if (size == 0)
    {
        this->primeiro_ = insertionNode;

        this->size++;
    }
    else
    {
        insertHelp (this->primeiro_, insertionNode);

        this->size++;
    }

    this->ultimo_ = insertionNode;
}

void Fila::RemoverPrimeiro() {
    // TODO
    if (this->size == 0)
    {
        throw ExcecaoFilaVazia();
    }
    else
    {
        No* removeThisNode;
        removeThisNode = this->primeiro_;
        this->primeiro_ = this->primeiro_->proximo;
        delete removeThisNode;

        this->size--;
    }
}

int Fila::primeiro() const {
    if (this->size > 0)
    {
        return this->primeiro_->chave; // TODO
    }
    else
    {
        throw ExcecaoFilaVazia ();
    }
}

int Fila::ultimo() const {
    if (this->size > 0)
    {
        return this->ultimo_->chave; // TODO
    }
    else
    {
        throw ExcecaoFilaVazia ();
    }
}

int Fila::tamanho() const {
    return this->size; // TODO
}