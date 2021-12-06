#include "Ponto2D.hpp"

Ponto2D::Ponto2D(double x, double y) {
    this->x = x;
    this->y = y;
}

double Ponto2D::calcular_distancia(Ponto2D *ponto) {
    return sqrt(pow(this->x - ponto->x, 2) + pow(this->y - ponto->y, 2));
}