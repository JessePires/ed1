#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NOT_FOUND_ELEMENT INT_MAX;

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim;
    No* ult;
    int qtde;
}Fila;


//PROTÓTIPOS

Fila* fila_criar();
void no_destruir(No* no);
Fila* fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);


//IMPLEMENTAÇÕES

Fila* fila_criar(){

    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->qtde = 0;

    return f;
 
}

void no_destruir(No* no){

    if(no == NULL) return;

    no_destruir(no->prox);
    free(no);

}

Fila* fila_destruir(Fila* f){

    no_destruir(f->prim);
    free(f->ult);
    return NULL;

}

Boolean fila_inserir(Fila* f, Tipo elemento){

    if(f != NULL){
        
        No* no = (No*) malloc(sizeof(No));
        no->dado = elemento;

        if(f->prim == NULL){
            
            f->prim = no;
            f->ult = no;
            f->qtde++;

        }else{

            No* aux = f->ult;
            f->ult = no;
            aux->prox = f->ult;        
            f->qtde++;

        }

        return true;
        
    }

    return false;

}

Tipo* fila_remover1(Fila* f){

    Tipo* endereco = (Tipo*) malloc(sizeof(Tipo));
    endereco = &f->prim->dado;
    f->prim = f->prim->prox;  
    f->qtde--;  
    return endereco;

}

Boolean fila_remover2(Fila* f, Tipo* endereco){

    if(f != NULL){

        *endereco = f->prim->dado;
        f->prim = f->prim->prox;
        f->qtde--;
        return true;
    }
    
    return false;

}

Boolean fila_primeiro(Fila* f, Tipo* endereco){

    if(f != NULL){

        *endereco = f->prim->dado;
        return true;

    }

    return false;

}

int fila_tamanho(Fila* f){

    return f->qtde;

}

int fila_contem(Fila* f, Tipo elemento){

    No* aux = f->prim;

    while(aux != NULL){

        if(aux->dado == elemento){

            return aux->dado;

        }

        aux = aux->prox;

    }

    return NOT_FOUND_ELEMENT;

}

void fila_imprimir(Fila* f){

    if(f != NULL){

        No* aux = f->prim;
        printf("Fila encadeada: [");
        while(aux != NULL){

            printf("%d", aux->dado);
            printf("%s", (aux->prox == NULL ? "]\n" : ", "));
            aux = aux->prox;    

        }

    }else{

        printf("Impossível imprimir a fila!\n");

    }

}