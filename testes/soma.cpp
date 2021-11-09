#include "soma.h"

int soma (int n, int v[]){
    int s = 0;
    for (int i = 0; i < n; i++){
        s += v[i];
    }
    return s;
}