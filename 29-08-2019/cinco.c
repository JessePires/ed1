#include <stdio.h>
#include <stdlib.h>

int dobraTamanhoVetor(int **v, int tam);

int dobraTamanhoVetor(int **v, int tam){

    int *novoVetor = (int*) calloc(tam*2, sizeof(int));

    for(int i = 0; i < tam; i++){

        novoVetor[i] = *(*v + i);

    }

    free(*v);
    *v = novoVetor;

    return tam * 2;

}

int main(){

    int *v = (int*) calloc(3, sizeof(int));
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    int novoTamanho = dobraTamanhoVetor(&v, 3);

    printf("Vetor com novo tamanho:\n");
    for(int i = 0; i < novoTamanho; i++){

        printf("%d\t", v[i]);

    }
    printf("\n");

    int *v1 = (int*) calloc(4, sizeof(int));
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;

    int novoTamanho1 = dobraTamanhoVetor(&v1, 4);

    printf("Vetor com novo tamanho:\n");
    for(int i = 0; i < novoTamanho1; i++){

        printf("%d\t", v1[i]);

    }
    printf("\n");

    return 0;
}