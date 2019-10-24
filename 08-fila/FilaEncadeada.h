#include <stdio.h>
#include <stdlib.h>



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
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);


//IMPLEMENTAÇÕES

Fila* fila_criar(){

    return (Fila*) malloc(sizeof(Fila));
 
}

void fila_destruir(Fila* f){



}

Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);