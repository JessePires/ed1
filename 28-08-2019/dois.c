#include <stdio.h>
#include <stdlib.h>

int* criaVetorConvencional(int tam, int valor);
void criaVetorScanf(int tam, int valor, int** vetor);

int* criaVetorConvencional(int tam, int valor){

    int *vetor = (int*) calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){

        vetor[i] = valor;

    }

    return vetor;

}

void criaVetorScanf(int tam, int valor, int** vetor){

    *vetor = (int*) calloc(tam, sizeof(int));
    
    for(int i = 0; i < tam; i++){

        *(*vetor + i) = valor;

    }

}

int main(){

    int *v1 = criaVetorConvencional(3, 0);
    int *v2 = criaVetorConvencional(10, 2);
    int *v3 = criaVetorConvencional(4, -2);

    int *v4;
    criaVetorScanf(5, -2, &v4);

    for(int i = 0; i < 5; i++){

        printf("%d\n", v4[i]);

    }

    return 0;

}