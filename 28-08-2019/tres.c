#include <stdio.h>
#include <stdlib.h>

int indiceMaior(int *vetor, int tam);

int indiceMaior(int *vetor, int tam){

    int indiceMaior = 0;

    for(int i = 0; i < tam; i++){

        if(vetor[i] > vetor[indiceMaior]){

            indiceMaior = i;

        }

    }

    return indiceMaior;

}

int main(){

    int v1 = 1;
    int v2[] = {1,2,3};
    int v3[] = {1,3,4,2,5,10,0}; 

    printf("Índice do maior valor de V1: %d\n", indiceMaior(&v1, 1));
    printf("Índice do maior valor de V2: %d\n", indiceMaior(v2, 3));
    printf("Índice do maior valor de V2: %d\n", indiceMaior(v3, 7));

    return 0;

}