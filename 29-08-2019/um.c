#include <stdio.h>
#include <stdlib.h>

int* vetorCloneA(int *v, int tam);
void vetorCloneB(int *v, int tam, int **copia);

int* vetorCloneA(int *v, int tam){

    int *copia = (int*) calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){

        copia[i] = v[i];

    }

    return copia;

}

void vetorCloneB(int *v, int tam, int **copia){

    *copia = (int*) calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){

        *(*copia + i) = v[i];

    }

}

int main(){

    int v1[4] = {1,2,3,4};
    int v2[3] = {5,6,7};

    int *copia1, *copia2;

    copia1 = vetorCloneA(v1, 4);
    vetorCloneB(v2, 3, &copia2);

    printf("Cópia do vetor V1:\n");
    for(int i = 0; i < 4; i++){

        printf("%d\n", copia1[i]);

    }

    printf("Cópia do vetor V2:\n");
    for(int i = 0; i < 3; i++){

         printf("%d\n", copia2[i]);

    }

    return 0;

}