#include <stdio.h>
#include "Matriz_Esparsa.h"

void teste(){

    //TESTE DE CRIAÇÃO DA MATRIZ ESPARSA
    Matriz * m1 = matriz_criar(4, 4);

    //TESTE DE INSERÇÃO
    matriz_atribuir(m1, 0, 0, 5);
    matriz_atribuir(m1, 2, 3, 6);
    matriz_atribuir(m1, 1, 0, 7);

    //TESTE DE IMPRESSÃO
    matriz_imprimir(m1);

    //TESTE DE SOBRESCRITA DE VALORES
    matriz_atribuir(m1, 1, 0, 8);
    matriz_imprimir(m1);

    //TESTE DE BUSCA
    printf("Valor encontrado: %d\n", matriz_acessar(m1, 2, 3));

    //TESTE DE DESALOCAÇÃO
    matriz_desalocar(&m1);
    matriz_imprimir(m1);        

}

int main(){

    teste();
    
    return 0;

}