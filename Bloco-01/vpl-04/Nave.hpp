#ifndef NAVE_H
#define NAVE_H

#include <cmath>
#include "Ponto2D.hpp"

struct Nave{
    Ponto2D posicao;
    double forca;
    double energia;
    Nave(Ponto2D posicao, double forca = 1, double energia = 100);
    void mover(double dx, double dy);
    double calcular_distancia(Nave *nave);
    Nave* determinar_nave_mais_proxima(Nave** naves, int n);
    void atacar(Nave** naves, int n);
    void imprimir_status();
};
#endif