#include <iostream>

using namespace std;

int main(){
    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int var = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *int_ptr = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int int_vet[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &var << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << var << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &int_ptr << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << int_ptr << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &int_vet << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &int_vet[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << int_vet[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    int_ptr = &var;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << int_ptr << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *int_ptr << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    bool result = &var == int_ptr;
    cout << result << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *int_ptr = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << var << endl;

    // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
    int_ptr = int_vet;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << int_ptr << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *int_ptr << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    int_ptr = &int_vet[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << int_ptr << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *int_ptr << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < sizeof(int_vet)/sizeof(int_vet[0]); i++)
        int_ptr[i] = 10 * int_ptr[i];

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < sizeof(int_vet)/sizeof(int_vet[0]); i++){
        if (i < 9)
            cout << int_vet[i] << " ";
        else
            cout << int_vet[i];
    }
    cout << endl;
    
    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for (int i = 0; i < sizeof(int_vet)/sizeof(int_vet[0]); i++){
        if (i < 9)
            cout << *(int_vet + i) << " ";
        else
            cout << *(int_vet + i);
    }
    cout << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    for (int i = 0; i < sizeof(int_vet)/sizeof(int_vet[0]); i++){
        if (i < 9)
            cout << *(int_ptr + i) << " ";
        else
            cout << *(int_ptr + i);
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    int_ptr = &int_vet[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << int_ptr << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *int_ptr << endl;

    // 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4
    cout << *(int_ptr - 4) << endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **ptr_to_ptr = &int_ptr;

    // 32) Imprima o VALOR da variável declarada em (31)
    cout << ptr_to_ptr << endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    cout << &ptr_to_ptr << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    cout << *ptr_to_ptr << endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    cout << **ptr_to_ptr << endl;
    
    return 0;
}