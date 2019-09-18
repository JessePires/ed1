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
#define OUT_OF_RANGE INT_MIN


//PROTÓTIPOS DAS FUNÇÕES

Vetor* vetor_new();
void vetor_free(Vetor* v);
void vetor_print(Vetor* v);
Boolean vetor_insert(Vetor* v, DataType element, int index);
Boolean vetor_add(Vetor* v, DataType element);
DataType vetor_remove1(Vetor* v, int index);
Boolean vetor_remove2(Vetor* v, int index, DataType *ptr);
DataType vetor_shift1(Vetor* v);
Boolean vetor_shift2(Vetor* v, DataType *ptr);
void vetor_shiftAdd(Vetor* v, int position);
void vetor_shiftRemove(Vetor* v, int position);
DataType vetor_get1(Vetor* v, int index);
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
DataType* vetor_get3(Vetor* v, int index);
Boolean vetor_set(Vetor* v, int index, DataType valor);
void vetor_map(Vetor* v, void (*funcao)(DataType*));
Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);
int vetor_size(Vetor* v);
Boolean vetor_isFull(Vetor* v);
Boolean vetor_haveSpace(Vetor* v);
void vetor_increase(Vetor* v);
void vetor_decrease(Vetor* v);

//OPERAÇÕES

Vetor* vetor_new(){

    Vetor* vet = (Vetor*) malloc(sizeof(Vetor));
    vet->vetor = (DataType*) calloc(5, sizeof(DataType));
    vet->size = 0;
    vet->length = 5;

    return vet;

}

void vetor_free(Vetor* v){

    free(v->vetor);
    free(v);

}

void vetor_print(Vetor* v){

    printf("[\t");

    for(int i = 0; i < v->size; i++){

        printf("%d\t", v->vetor[i]);

    }

    printf("]\n");

}

Boolean vetor_insert(Vetor* v, DataType element, int index){

    if(index < v->size){

        vetor_shiftAdd(v, index);
        v->vetor[index] = element;

        return true;

    }

    return false;

}

Boolean vetor_add(Vetor* v, DataType element){

    if(v != NULL){

        if(vetor_isFull(v)){

            vetor_increase(v);

        }

        if(element != OUT_OF_RANGE){

            v->vetor[v->size] = element;
            v->size++;
            return true;

        }

        return false;

    }

    return false;

}

DataType vetor_remove1(Vetor* v, int index){

    DataType removedElement = OUT_OF_RANGE;

    if(index < v->size){

        removedElement = v->vetor[index];

        if(index > 0){

            vetor_shiftRemove(v, index);
        
            v->size--;

        }else{

            vetor_shift1(v);

        }

        if(vetor_haveSpace(v)){

            vetor_decrease(v);

        }

    }

    return removedElement;

}

Boolean vetor_remove2(Vetor* v, int index, DataType *ptr){

    *ptr = OUT_OF_RANGE;

    if(index < v->size){

        *ptr = v->vetor[index];

        if(index > 0){

            vetor_shiftRemove(v, index);
        
            v->size--;

        }else{

            vetor_shift1(v);

        }

        if(vetor_haveSpace(v)){

            vetor_decrease(v);

        }

        return true;

    }

    return false;

}

DataType vetor_shift1(Vetor* v){

    DataType aux = v->vetor[0];

    for(int i = 1; i < v->size; i++){

        v->vetor[i-1] = v->vetor[i];

    }

    v->size--;

    if(vetor_haveSpace(v)){

        vetor_decrease(v);

    }

    return aux;

}

Boolean vetor_shift2(Vetor* v, int* ptr){

    if(v != NULL){

        *ptr = v->vetor[0];

        for(int i = 1; i < v->size; i++){

            v->vetor[i-1] = v->vetor[i];

        }

        v->size--;

        if(vetor_haveSpace(v)){

            vetor_decrease(v);

        }

        return true;

    }

    return false;

}

void vetor_shiftAdd(Vetor* v, int position){

    DataType aux1, aux2;

    if(vetor_isFull(v)){

        vetor_increase(v);

    }

    aux1 = v->vetor[position];
    aux2 = v->vetor[position+1];

    for(int i = position + 1; i <= v->size + 1; i++){

        v->vetor[i] = aux1;
        aux1 = aux2;
        aux2 = v->vetor[i+1];

    }

    v->size++;

}

void vetor_shiftRemove(Vetor* v, int position){

    if(position > 0){

        for(int i = position -1; i < v->size; i++){

            v->vetor[i] = v->vetor[i+1];

        }   

    }else{

        vetor_shift1(v);

    }

}

DataType vetor_get1(Vetor* v, int index){

    if(index < v->size){

        return v->vetor[index];

    }

    return OUT_OF_RANGE;

}

Boolean vetor_get2(Vetor* v, int index, DataType* ptr){

    if(index < v->size){

        ptr = &v->vetor[index];
        return true;

    }

    return false;
    
}

DataType* vetor_get3(Vetor* v, int index){

    DataType* element = (DataType*) malloc(sizeof(DataType));
    DataType aux;

    if(index < v->size){

        aux = v->vetor[index];

    }else{

        aux = OUT_OF_RANGE;

    }

    element = &aux;
    return element;

}

Boolean vetor_set(Vetor* v, int index, DataType valor){

    if(v->size > 0){

        if(index < v->size){

            v->vetor[index] = valor;
            return true;

        }

        return false;

    }

    return false;

}

void vetor_map(Vetor* v, void (*funcao)(DataType*)){

    for(int i = 0; i < v->size; i++){

       funcao(&v->vetor[i]);

    }

}

Vetor* vetor_sub1(Vetor* v, int index){

    Vetor* newVector = vetor_new(); 

    index = (index < 0 ? v->size + index : index);

    for(int i = index; i <= v->size -1 ; i++){

        vetor_add(newVector, v->vetor[i]);

    }

    return newVector;

}

Vetor* vetor_sub2(Vetor* v, int start, int end){

    Vetor* newVector = vetor_new(); 

    if(start < end){

        start = (start < 0 ? v->size + start : start);

        for(int i = start; i < end; i++){

            vetor_add(newVector, v->vetor[i]);

        }

    }

    return newVector;

}

int vetor_size(Vetor* v){

    return v->size;

}

Boolean vetor_isFull(Vetor* v){

    if(v->size == v->length){

        return true;

    }

    return false;

}

Boolean vetor_haveSpace(Vetor* v){

    if(v->size < v->length * 0.25){

        return true;

    }

    return false;

}

void vetor_increase(Vetor* v){

    DataType* vector = (DataType*) calloc(v->length * 2, sizeof(DataType));

    for(int i = 0; i < v->size; i++){

        vector[i] = v->vetor[i];

    }

    free(v->vetor);
    v->length *= 2;
    v->vetor = vector;

}

void vetor_decrease(Vetor* v){

    DataType* vector = (DataType*) calloc(v->length / 2, sizeof(DataType));

    for(int i = 0; i < v->size; i++){

        vector[i] = v->vetor[i];

    }

    free(v->vetor);
    v->length -= 5;
    v->vetor = vector;

}
