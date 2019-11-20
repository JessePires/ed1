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
    No* primeiro;
    No* ultimo;
    int qtde;
}Lista;


//PROTOTIPOS

Lista* lista_criar();

void no_destruir(No* n);
Lista* lista_destruir(Lista* l);

No* getNo(Lista* l, int posicao);
void insereEsquerda(No* ref, No* n);
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
    l->qtde = 0;
    return l;

}

void no_destruir(No* n){

    if(n->prox == NULL) return;

    no_destruir(n->prox);
    free(n);

}

Lista* lista_destruir(Lista* l){

    no_destruir(l->primeiro);
    free(l);
    return NULL;

}

No* getNo(Lista* l, int posicao){

    No* aux;
    if(posicao >= (l->qtde / 2)){

        aux = l->ultimo;
        for(int i = l->qtde-1; i > posicao; i--){

            aux = aux->ant;

        }
        
        return aux;

    }else{

        aux = l->primeiro;
        for(int i = 0; i < posicao; i++){

            aux = aux->prox;

        }

        return aux;

    }

}

void insereEsquerda(No* ref, No* n){

    n->prox = ref;
    n->ant = ref->ant;
    ref->ant->prox = n;
    ref->ant = n;

}

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao){

    if(l != NULL){

        if(posicao <= l->qtde && posicao >= 0){

            if(elemento < INDEX_OUT_OF_RANGE){

                if(l->primeiro == NULL && l->ultimo == NULL){

                    No* n = (No*) malloc(sizeof(No));
                    n->dado = elemento;
                    l->primeiro = l->ultimo = n;
                    l->qtde++;
                    
                    return true;

                }else if(posicao == 0){

                    No* n = (No*) malloc(sizeof(No));
                    n->prox = l->primeiro;
                    l->primeiro->ant = n;
                    l->primeiro = n;
                    l->qtde++;
                    
                    return true;

                }else if(posicao == l->qtde){

                    lista_inserir_fim(l, elemento);                  

                    return true;

                }else{
    
                    No* aux = getNo(l, posicao);
                    No* n = (No*) malloc(sizeof(No));
                    n->dado = elemento;
                    insereEsquerda(aux, n);
                    l->qtde++;
                        
                    return true;

                }

            }

            return false;

        }

        return false;

    }

    return false;

}

Boolean lista_inserir_fim(Lista* l, Tipo elemento){

    if(l != NULL){

        if(elemento < INDEX_OUT_OF_RANGE){

            No* n = (No*) malloc(sizeof(No));
            n->dado = elemento;
            l->ultimo->prox = n;
            n->ant = l->ultimo;
            l->ultimo = n;
            l->qtde++;

            return true;

        }

        return false;
    }

    return false;

}

int* lista_remover1(Lista* l, int posicao){

    int* retorno = (int*) malloc(sizeof(int));

    if(l != NULL){

        if(posicao < l->qtde){

            No* aux = getNo(l, posicao);
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            l->qtde--;

            return &aux->dado;

        }

        *retorno = INDEX_OUT_OF_RANGE;
    
    }

    *retorno = INDEX_OUT_OF_RANGE;

    return retorno;

}

Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){

    if(l != NULL){

        if(posicao < l->qtde){

            No* aux = getNo(l, posicao);
            *endereco = aux->dado;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            l->qtde--;

            return true;

        }

        return false;
    
    }

    return false;

}

Boolean lista_remover_elemento(Lista* l, Tipo elemento){

    if(l != NULL){

        No* aux = l->primeiro;
        for(int i = 0; i < l->qtde; i++){

            if(aux->dado == elemento){

                if(aux->dado == l->ultimo->dado){

                    aux->ant->prox = NULL;
                    l->ultimo = aux->ant;
                    l->qtde--;

                    return true;

                }

                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                l->qtde--;
                
                return true;

            }

            aux = aux->prox;

        }

        return false;

    }

    return false;

}


Boolean lista_buscar(Lista* l, int posicao, int* endereco){

    if(l != NULL){

        if(posicao < l->qtde){

            No* n = getNo(l, posicao);
            *endereco = n->dado;
            
            return true;

        }

        return false;

    }
    
    return false;

}

Boolean lista_contem(Lista* l, Tipo elemento){

    No* aux = l->primeiro;

    for(int i = 0; i < l->qtde; i++){

        if(aux->dado == elemento) return true;
        aux = aux->prox;

    }

    return false;

}

int lista_posicao(Lista* l, Tipo elemento){

    No* aux = l->primeiro;
    int cont = 0;

    while(aux->prox != NULL){

        if(aux->dado == elemento) return cont;

        aux = aux->prox;
        cont++;

    }

    return cont;

}

int lista_tamanho(Lista* l){

    return l->qtde;

}

void lista_imprimir(Lista* l){

    if(l != NULL){

        No* aux = l->primeiro;

        printf("\nLista: [");
        for(int i = 0; i < l->qtde; i++){

            printf("%d", aux->dado);
            printf("%s", (aux->dado == l->ultimo->dado ? "]\n" : ", "));
            aux = aux->prox;

        }

    }else{

        printf("\nLista inexistente!\n");

    }

}