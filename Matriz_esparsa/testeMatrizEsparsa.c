#include <stdio.h>
#include "Matriz_Esparsa.h"

void teste(){

    //TESTE DE CRIAÇÃO DA MATRIZ ESPARSA
    Matriz * m1 = matriz_criar(4, 4);

    //TESTE DE INSERÇÃO
    matriz_atribuir(m1, 2, 1, 2);
    //matriz_atribuir(m1, 2, 1, 3);
    matriz_atribuir(m1, 0, 0, 5);

    //TESTE DE IMPRESSÃO
    //matriz_imprimir(m1);

}

int main(){

    teste();
    
    return 0;

}