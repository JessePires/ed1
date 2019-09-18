#include <stdio.h>
#include "TAD-vetor.h"

void dobraValores(int* elem){

    *elem *= 2;

}

int main(){

    //STATEMENTS

    Vetor* v1 = vetor_new();
    Vetor* subV1;
    Vetor* sub2V1;
    int excludedElement;
    int excludedElementPtr;
    int removedElement;
    int removedElementptr;
    int elem1;

    //MANIPULATIONS

    //adições
    vetor_add(v1, 1);
    vetor_add(v1, 2);
    vetor_add(v1, 3);
    vetor_add(v1, 4);
    vetor_add(v1, 5);
    vetor_add(v1, 6);
    vetor_add(v1, 7);

    printf("Vetor 1: ");
    vetor_print(v1);
    printf("Size: %d\n", vetor_size(v1));

    //inserção
    if(vetor_insert(v1, 10, 2)){

        printf("Vetor 1 com valor inserido: ");
        vetor_print(v1);
        printf("Size: %d\n", vetor_size(v1));

    }else{

        printf("Impossível realizar inserção!\n");

    }


    //shift
    excludedElement = vetor_shift1(v1);
    printf("Elemento excluído: %d\n", excludedElement);
    excludedElement = vetor_shift1(v1);
    printf("Elemento excluído: %d\n", excludedElement);
    excludedElement = vetor_shift1(v1);
    printf("Elemento excluído: %d\n", excludedElement);

    printf("Vetor V1 após o shift: ");
    vetor_print(v1);
    printf("Size: %d\n", vetor_size(v1));

    vetor_shift2(v1, &excludedElementPtr);
    printf("Elemento excluído: %d\n", excludedElementPtr);
    vetor_shift2(v1, &excludedElementPtr);
    printf("Elemento excluído: %d\n", excludedElementPtr);

    printf("Vetor após o shift: ");
    vetor_print(v1);

    //remoção
    removedElement = vetor_remove1(v1, 0);
    printf("Elemento removido: %d\n", removedElement);
    vetor_print(v1);

    //criação de subvetores
    subV1 = vetor_sub1(v1, -1);
    printf("Sub-vetor de V1: ");
    vetor_print(subV1);

    sub2V1 = vetor_sub2(v1, 0, 1);
    printf("Sub-vetor 2 de V1: ");
    vetor_print(sub2V1);

    //get
    elem1 = vetor_get1(subV1, 0);
    printf("elemeno obtido com vetor_get1(): %d\n", elem1);

    printf("elemento obtico com vetor_get2(): %d\n", vetor_get2(v1, 0, &elem1));

    //teste função map
    vetor_map(subV1, dobraValores);
    printf("Sub-vetor1 após a aplicação da função dobraValores(): ");
    vetor_print(subV1);
    
    return 0;

}