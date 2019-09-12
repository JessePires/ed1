#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//DADOS
typedef struct{

    int *vetor;
    int size; //qtd de elementos armazenados no vetor
    int length; //tamanho alocado

} Vetor;

typedef int DataType;

typedef enum {false, true} Boolean;

#define LENGTH 5


//PROTÓTIPOS DAS FUNÇÕES

Vetor* vetor_new();
void vetor_free(Vetor *v);
void vetor_print(Vetor *v);
Boolean vetor_insert(Vetor *v, DataType element, int index);
Boolean vetor_add(Vetor *v, DataType element);
DataType vetor_remove1(Vetor *v, int index);
Boolean vetor_remove2(Vetor *v, int index, DataType *ptr);
DataType vetor_shift1(Vetor *v);
Boolean vetor_shift2(Vetor *v, DataType *ptr);
DataType vetor_get1(Vetor *v, int index);
DataType vetor_get2(Vetor *v, int index, DataType *ptr);
DataType* vetor_get3(Vetor *v, int index);
Boolean vetor_set(Vetor *v, int index, DataType valor);
void vetor_map(Vetor *v, void (*funcao)(DataType*));
Vetor* vetor_sub1(Vetor *v, int index);
Vetor* vetor_sub2(Vetor *v, int start, int end);
int vetor_size(Vetor *v);


//OPERAÇÕES

Vetor* vetor_new(){

    Vetor *vet = (Vetor*) malloc(sizeof(Vetor));
    vet->vetor = (DataType*) calloc(5, sizeof(DataType));
    vet->size = 0;
    vet->length = 5;

    return vet;

}

void vetor_free(Vetor *v){

    free(v->vetor);
    free(v);

}

void vetor_print(Vetor *v){

    printf("[");

    for(int i = 0; i < v->size; i++){

        printf("%d\t", v->vetor[i]);

        if(i == v->size -1){

            printf("%d]\n", v->vetor[i]);

        }

    }

}

Boolean vetor_insert(Vetor *v, DataType element, int index){}

Boolean vetor_add(Vetor *v, DataType element){}

DataType vetor_remove1(Vetor *v, int index);

Boolean vetor_remove2(Vetor *v, int index, DataType *ptr){}

DataType vetor_shift1(Vetor *v){}

Boolean vetor_shift2(Vetor *v, DataType *ptr){}

DataType vetor_get1(Vetor *v, int index){

    if(index < v->size){

        return v->vetor[index];

    }

    return INT_MIN;

}

Boolean vetor_get2(Vetor *v, int index, DataType *ptr){

    if(index < v->size){

        ptr = &v->vetor[size];
        return true;

    }

    return false;

}

DataType* vetor_get3(Vetor *v, int index){}

Boolean vetor_set(Vetor *v, int index, DataType valor){

    if(index < v->size){

        v->vetor[index] = valor;
        return true;

    }

    return false;

}

void vetor_map(Vetor *v, void (*funcao)(DataType*)){}

Vetor* vetor_sub1(Vetor *v, int index){}

Vetor* vetor_sub2(Vetor *v, int start, int end){}

int vetor_size(Vetor *v){

    return v->size;

}
