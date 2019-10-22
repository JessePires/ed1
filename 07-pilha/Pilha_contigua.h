#include <stdio.h>
#include <stdlib.h>

//Estratégia de armazenamento: Base ------> Topo

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;
}Pilha;

Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
Pilha* pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
void pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);

//IMPLEMENTAÇÕES

Pilha* pilha_criar(){

    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->tam = 0;
    p->qtde = 0;

    return p;

}

Boolean pilha_push(Pilha* p, Tipo elemento){

    if(p != NULL){

        Tipo* v = (Tipo*) calloc(p->qtde + 1, sizeof(Tipo));
        v[p->qtde] = elemento;

        if(p->vetor != NULL){

            for(int i = 0; i < p->qtde; i++){

                v[i] = p->vetor[i];

            }

        }

        p->qtde++;
        p->tam++;
        p->vetor = v;

        return true;

    }

    return false;

}

Tipo* pilha_pop1(Pilha* p){

    Tipo* end = (Tipo*) malloc(sizeof(Tipo));
    end = &p->vetor[p->qtde - 1];
    p->qtde--;
    p->tam--;
    Tipo* v = (Tipo*) calloc(p->qtde, sizeof(Tipo));

    for(int i = 0; i < p->qtde; i++){

        v[i] = p->vetor[i];

    }

    free(p->vetor);
    p->vetor = v;
    return end;

}

Boolean pilha_pop2(Pilha* p, Tipo* end){

    if(p != NULL){

        Tipo* end = (Tipo*) malloc(sizeof(Tipo));
        end = &p->vetor[p->qtde - 1];
        p->qtde--;
        p->tam--;
        Tipo* v = (Tipo*) calloc(p->qtde, sizeof(Tipo));

        for(int i = 0; i < p->qtde; i++){

            v[i] = p->vetor[i];

        }

        free(p->vetor);
        p->vetor = v;
        return true;

    }

    return false;

}

Pilha* pilha_destruir(Pilha* p){

    free(p->vetor);
    free(p);
    return NULL;

}

void pilha_imprimir(Pilha* p){

    if(p != NULL){

        printf("Base ->[");
        for(int i = 0; i < p->qtde; i++){

            printf("%d", p->vetor[i]);
            printf("%s", (i == p->qtde -1 ? "]<- Topo\n" : ", "));

        }

    }else{

        printf("Impossível imprimir os valores da pilha!\n");

    }
    

}

int pilha_posicao(Pilha* p, Tipo elemento){
    
    for(int i = 0; i < p->qtde; i++){

        if(p->vetor[i] == elemento){
            
            return i;

        }

    }

    return -1;

}

int pilha_tamanho(Pilha* p){

    return p->tam;

}

//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){

    for(int i = 0; i < tam; i++){

        pilha_push(p, vetor[i]);

    }

    return tam;

}

void pilha_inverter(Pilha* p){

    int aux = p->qtde-1;
    Tipo* v = (Tipo*) calloc(p->qtde, sizeof(Tipo));
    
    for(int i = 0; i < p->qtde; i++){

        v[i] = p->vetor[aux];
        aux--;

    }

    free(p->vetor);
    p->vetor = v;

}

Pilha* pilha_clone(Pilha* p){

    Pilha* p2 = pilha_criar();

    for(int i = 0; i < p->qtde; i++){

        pilha_push(p2, p->vetor[i]);

    }

    return p2;

}