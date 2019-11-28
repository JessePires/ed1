#include <stdio.h>
#include "TAD-vetor.h"

void doubleValues(int* elem){

    *elem *= 2;

}

Boolean isPair(int* elem){

    return (*elem % 2 == 0 ? true : false);

}

Boolean isUnpair(int* elem){

    return (*elem % 2 == 0 ? false : true);

}

int compair(int* a, int* b){

    if(*a > *b){

        return 1;

    }else if(*b > *a){

        return -1;

    }else{

        return 0;

    }

}

int main(){

    //STATEMENTS

    Vetor* v1 = vetor_new();
    Vetor* v2;
    Vetor* v3;        
    Vetor* subV1;
    Vetor* sub2V1;
    int excludedElement;
    int excludedElementPtr;
    int removedElement;
    int removedElementptr;
    int elem1;

    //MANIPULATIONS

    //addition
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

    //insertion
    if(vetor_insert(v1, 10, 2)){

        printf("Vetor 1 com valor inserido: ");
        vetor_print(v1);
        printf("Size: %d\n", vetor_size(v1));

    }else{

        printf("Impossível realizar inserção!\n");

    }

    //vector ordering
    vetor_sort(v1);
    //ou
    //vetor_genericSort(v1, compair);
    printf("Ordenação do vetor v1: ");
    vetor_print(v1);

    //vector filtering
    v2 = vetor_filter(v1, isPair);
    printf("Vetor formado pelos elementos pares de v1: ");
    vetor_print(v2);

    v3 = vetor_filter(v1, isUnpair);
    printf("Vetor formado pelos elementos ímpares de v1: ");
    vetor_print(v3);

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

    //removal
    removedElement = vetor_remove1(v1, 0);
    printf("Elemento removido: %d\n", removedElement);
    vetor_print(v1);

    //subvectors creation
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

    //map function test
    vetor_map(subV1, doubleValues);
    printf("Sub-vetor1 após a aplicação da função doubleValues(): ");
    vetor_print(subV1);

    //import function 
    int qtdValores = vetor_import(v1, "valores.txt");
    printf("Vetor após importação de valores do arquivo valores.txt: ");
    vetor_print(v1);

    return 0;

}