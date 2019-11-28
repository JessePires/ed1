#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//CONVENCOES

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;
#define INDEX_OUT_OF_RANGE INT_MAX


//TIPOS DE DADOS

typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* sentinela;
    int qtde;
}Lista;


//PROTOTIPOS

Lista* lista_criar();

void no_destruir(No* n, No* ref);
Lista* lista_destruir(Lista* l);

No* getNo(Lista* l, int posicao);
void insere(No* ref, No* n);
Boolean lista_inserir(Lista* l, Tipo elemento, int posicao);
Boolean lista_inserir_fim(Lista* l, Tipo elemento);

int* lista_remover1(Lista* l, int posicao);
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);
Boolean lista_remover_elemento(Lista* l, Tipo elemento);


Boolean lista_buscar(Lista* l, int posicao, int* endereco);
Boolean lista_contem(Lista* l, Tipo elemento);
int lista_posicao(Lista* l, Tipo elemento);

int lista_tamanho(Lista* l);
void lista_imprimir(Lista* l);


//IMPLEMENTAÇÕES

Lista* lista_criar(){

    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->sentinela = (No*) malloc(sizeof(No));
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
    l->qtde = 0;

    return l;

}

void no_destruir(No* n, No* ref){

    if(n->prox == ref) return;

    no_destruir(n->prox, ref);
    free(n);

}

Lista* lista_destruir(Lista* l){

    if(l != NULL){

        no_destruir(l->sentinela->prox, l->sentinela);
        free(l->sentinela);
        free(l);

    }

    return NULL;

}

No* getNo(Lista* l, int posicao){

    No* aux = l->sentinela;
    for(int i = 0; i <= posicao; i++) aux = aux->prox;

    return aux;

}

void insere(No* ref, No* n){

    n->prox = ref;
    n->ant = ref->ant;
    ref->ant->prox = n;
    ref->ant = n;

}

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao){

    if(l != NULL && posicao <= l->qtde && elemento < INDEX_OUT_OF_RANGE){

        No* n = (No*) malloc(sizeof(No));
        n->dado = elemento;
        No* aux = (posicao < 0 ? l->sentinela : getNo(l, posicao));
        insere(aux, n);
        l->qtde++;

        return true;

    }

    return false;

}

Boolean lista_inserir_fim(Lista* l, Tipo elemento){

    if(l != NULL && elemento != INDEX_OUT_OF_RANGE){

        lista_inserir(l, elemento, l->qtde);

        return true;

    }

    return false;

}

int* lista_remover1(Lista* l, int posicao){

    if(l != NULL && posicao < l->qtde){

        No* aux = getNo(l, posicao);
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        l->qtde--;

        return &aux->dado;

    }

    int* retorno = (int*) malloc(sizeof(int));
    *retorno = INDEX_OUT_OF_RANGE;
    return retorno;

}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){

    if(l != NULL && posicao < l->qtde){

        No* aux = getNo(l, posicao);
        *endereco = aux->dado;
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        l->qtde--;

        return true;

    }

    return false;

}

Boolean lista_remover_elemento(Lista* l, Tipo elemento){

    if(l != NULL && elemento < INDEX_OUT_OF_RANGE){

        No* aux = l->sentinela->prox;

        for(int i = 0; i < l->qtde; i++){

            if(aux->dado == elemento){

                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                l->qtde--;

                return true;

            }

            aux = aux->prox;

        }

    }

    return false;

}


Boolean lista_buscar(Lista* l, int posicao, int* endereco){

    if(l != NULL && posicao < l->qtde){

        No* aux = getNo(l, posicao);
        *endereco = aux->dado;

        return true;

    }

    return false;

}

Boolean lista_contem(Lista* l, Tipo elemento){

    if(l != NULL && elemento < INDEX_OUT_OF_RANGE){

        No* aux = l->sentinela->prox;
        for(int i = 0; i < l->qtde; i++){

            if(aux->dado == elemento){

                return true;

            }

            aux = aux->prox;

        }

    }

    return false;

}

int lista_posicao(Lista* l, Tipo elemento){

    if(l != NULL && elemento < INDEX_OUT_OF_RANGE){

        int cont = 0;
        No* aux = l->sentinela->prox;
        for(int i = 0; i < l->qtde; i++){

            if(aux->dado == elemento){

                return cont;

            }

            aux = aux->prox;
            cont++;

        }

    }

    return INDEX_OUT_OF_RANGE;

}

int lista_tamanho(Lista* l){

    return l->qtde;

}

void lista_imprimir(Lista* l){

    if(l != NULL){

        No* aux = l->sentinela->prox;
        printf("Lista: [");
        for(int i = 0; i < l->qtde; i++){

            printf("%d", aux->dado);
            printf("%s", (aux->dado == l->sentinela->ant->dado ? "]\n" : ", "));
            aux = aux->prox;

        }

    }else{

        printf("\nLista Inexistente\n");

    }

}