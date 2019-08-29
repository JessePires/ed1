#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* vetorAleatorio(int tam);

int* vetorAleatorio(int tam){

    int *v = (int*) calloc(tam, sizeof(int));
    
    srand( (unsigned)time NULL); //garante a geração de aleatório de acordo com o momento em que a função for chamada
    for(int i = 0; i < tam; i++){

        v[i] = rand() % 1000;

    }

    return v;

}

int main(){

    int *v1 = vetorAleatorio(10);
    int *v2 = vetorAleatorio(20);

    printf("Vetor V1:\n");
    for(int i = 0; i < 10; i++){

        printf("%d\t", v1[i]);

    }
    printf("\n");

    printf("Vetor V2:\n");
    for(int i = 0; i < 20; i++){

        printf("%d\t", v2[i]);

    }
    printf("\n");

    return 0;

}