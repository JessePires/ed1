#include <stdio.h>

void dobraVetor(int *v, int tam);

void dobraVetor(int *v, int tam){

    for(int i = 0; i < tam; i++){

        v[i] *= 2;

    }

}

int main(){

    int v1[5] = {10,20,30,40,50};

    printf("Vetor antes da dobra de valores:\n");
    for(int i = 0; i < 5; i++){

        printf("%d\t", v1[i]);

    }
    printf("\n");

    dobraVetor(v1, 5);

    printf("\nVetor depois da dobra de valores:\n");
    for(int i = 0; i < 5; i++){

        printf("%d\t", v1[i]);

    }
    printf("\n");

    return 0;

}