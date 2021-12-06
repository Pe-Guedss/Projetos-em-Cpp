#include <iostream>
#include "Nave.hpp"

#define LIM_DANO 30

using namespace std;

Nave::Nave(Ponto2D posicao, double forca, double energia) {
    this->posicao.x = posicao.x;
    this->posicao.y = posicao.y;
    this->forca = forca;
    this->energia = energia;
}

void Nave::mover(double dx, double dy){
    this->posicao.x += dx;
    this->posicao.y += dy;
}

double Nave::calcular_distancia(Nave *nave){
    return this->posicao.calcular_distancia(&nave->posicao);
}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n){
    double maior_dist = 100000;
    int maior_index = 0;

    for (int i = 0; i < n; i++){
        if (this->calcular_distancia(naves[i]) < maior_dist){
            if (this->calcular_distancia(naves[i]) != 0){
                maior_dist = this->calcular_distancia(naves[i]);
                maior_index = i;
            }
        }
    }
    return naves[maior_index];
}

void Nave::atacar(Nave** naves, int n){
    Nave *alvo = this->determinar_nave_mais_proxima(naves, n);
    double d = this->calcular_distancia(alvo);
    double dano = (100/d)*this->forca;

    if (dano < LIM_DANO)
        alvo->energia -= dano;
    else
        alvo->energia -= LIM_DANO;
    
    if (alvo->energia <= 50)
        cout << "Energia baixa!" << endl;
}

void Nave::imprimir_status(){
    cout << this->posicao.x << " " << this->posicao.y << " " << this->energia << endl;
}