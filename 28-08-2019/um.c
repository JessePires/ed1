#include <stdio.h>

void imprimeVetor(int *vetor, int tam);

void imprimeVetor(int *vetor, int tam){

    printf("[");

    for(int i = 0; i < tam; i++){

        if(i == (tam-1)){

            printf("%d]\n", *vetor + i);

        }else{

            printf("%d, ", *vetor + i);

        }
    }

}

int main(){

    int v[3] = {1,2,3};
    int v1[4] = {1,2,3,4};
    int v2 = 1;
    int v3[10] = {1,2,3,4,5,6,7,8,9,10};

    imprimeVetor(v, 3);
    imprimeVetor(v1, 4);
    imprimeVetor(&v2, 1);
    imprimeVetor(v3, 10);

    return 0;

}