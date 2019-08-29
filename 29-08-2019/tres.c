#include <stdio.h>

void incrementaVetor(int *v, int tam);

void incrementaVetor(int *v, int tam){

    for(int i = 0; i < tam; i++){

        v[i] += 1;

    }

}

int main(){

    int v1[5] = {1,2,3,4,5};

    printf("Vetor antes da incrementação:\n");
    for(int i = 0; i < 5; i++){

        printf("%d\t", v1[i]);

    }
    printf("\n");

    incrementaVetor(v1, 5);

    printf("\nVetor depois da incrementação:\n");
    for(int i = 0; i < 5; i++){

        printf("%d\t", v1[i]);

    }
    printf("\n");

    return 0;

}