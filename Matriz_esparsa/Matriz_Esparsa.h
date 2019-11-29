#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//CONVEÇÕES

#define INDEX_OUT_OF_RANGE INT_MAX
typedef int Tipo;
typedef enum boolean{false = 0, true = 1} Boolean;

//TIPOS DE DADOS

typedef struct no{

    int linha;
    int coluna;
    Tipo valor;
    struct no* direita;
    struct no* baixo;
    struct no* esquerda;
    struct no* cima;

}No;

typedef struct{

    No** linhas;    //ponteiro para o vetor cujas células são ponteiros de nós
    No** colunas;   //ponteiro para o vetor cujas células são ponteiros de nós
    int numLinhas;  //quantidade de linhas da matriz
    int numColunas; //quantidade de colunas da matriz

}Matriz;


// PROTÓTIPOS

/*
*cria uma matriz vazia e retorna seu endereço
*/
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);

/*
*Insere o <valor> na matriz na linha e coluna.
*Caso a posição já exista, apenas substitui o valor.
*/
Boolean matriz_atribuir(Matriz* m, int linha, int coluna, int valor);

/*
*Devolve o valor correspondente a linha e coluna solicitada.
*Caso a posição solicitada esteja fora do intervalo INDEX_OUT_OF_RANGE.
*/
int matriz_acessar(Matriz* m, int linha, int coluna);

/*
*Imprime os valores da matriz na tela. 
*Cada linha deve ser impressa em uma linha diferente e os elementos 
*separados por espaço ou tabulação. 
*Os elementos não representados na matriz (valor zero), também devem ser impressos.
*/
void matriz_imprimir(Matriz* m);

/*
*Libera toda memória alocada dinamicamente para a matriz.
*/
Matriz* matriz_desalocar(Matriz* m);


//IMPLEMENTAÇÕES

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){

    Matriz* m = (Matriz*) malloc(sizeof(Matriz));
    m->numLinhas = qtdeLinhas;
    m->numColunas = qtdeColunas;
    m->linhas = (No**) calloc(qtdeLinhas, sizeof(No*));
    
    for(int i = 0; i < m->numLinhas; i++){

        No* sentinela = (No*) malloc(sizeof(No));
        sentinela->direita = sentinela;
        sentinela->esquerda = sentinela;
        m->linhas[i] = sentinela;

    }
    
    m->colunas = (No**) calloc(qtdeColunas, sizeof(No*));

    for(int i = 0; i < m->numColunas; i++){

        No* sentinela = (No*) malloc(sizeof(No));
        sentinela->cima = sentinela;
        sentinela->baixo = sentinela;
        m->linhas[i] = sentinela;

    }

    return m;

}


Boolean matriz_atribuir(Matriz* m, int linha, int coluna, int valor){

    if(m != NULL){

        if(linha >= 0 && linha < m->numLinhas){

            if(coluna >= 0 && coluna < m->numColunas){

                if(valor < INDEX_OUT_OF_RANGE){

                    No* aux1 = m->linhas[linha];
                    
                    if(aux1 != NULL){

                        

                    }

                    return true;

                }


            }


        }


    }

    return false;

}


// int matriz_acessar(Matriz* m, int linha, int coluna){

//     if(m != NULL){

//          if(linha >= 0 && linha < m->numLinhas){

//              if(coluna >= 0 && coluna < m->numColunas){



//              }

//          }

//     }

// }


// void matriz_imprimir(Matriz* m);
// Matriz* matriz_desalocar(Matriz* m);
