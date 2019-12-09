#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//CONVEÇÕES

#define ERRO INT_MAX
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
*cria e retorna um sentinela
*/
No* criaSentinela();

/*
*cria uma matriz vazia e retorna seu endereço
*/
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);

/*
*Retorna o nó (referente a linha) desejado de acordo com a linha e coluna passadas por parâmetro.
*/
No* getNoLinha(Matriz* m, int linha, int coluna);

/*
*Retorna o nó (referente a coluna) desejado de acordo com a linha e coluna passadas por parâmetro.
*/
No* getNoColuna(Matriz* m, int linha, int coluna);

/*
*retorna um novo nó com valor inserido no mesmo
*/
No* criaNovoNo(int valor, int linha, int coluna);

/*
*insere um nó na linha
*/
void insereNaLinha(No* ref, No* no);

/*
*insere um nó na coluna
*/
void insereNaColuna(No* ref, No* no);

/*
*Insere o <valor> na matriz na linha e coluna.
*Caso a posição já exista, apenas substitui o valor.
*/
Boolean matriz_atribuir(Matriz* m, int linha, int coluna, int valor);

/*
*Devolve o valor correspondente a linha e coluna solicitada.
*Caso a posição solicitada esteja fora do intervalo ERRO.
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
*Libera um nó alocado
*/
void no_destruir(No* no, No* sentinela);

/*
*Libera toda memória alocada dinamicamente para a matriz.
*/
void matriz_desalocar(Matriz** m);


//IMPLEMENTAÇÕES

No* criaSentinela(){

    No* sentinela = (No*) malloc(sizeof(No));
    sentinela->direita = sentinela;
    sentinela->esquerda = sentinela;
    sentinela->cima = sentinela;
    sentinela->baixo = sentinela;

    return sentinela;

}

Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){

    Matriz* m = (Matriz*) malloc(sizeof(Matriz));
    m->numLinhas = qtdeLinhas;
    m->numColunas = qtdeColunas;
    m->linhas = (No**) calloc(qtdeLinhas, sizeof(No*));
    
    //INSERÇÃO DOS SENTINELAS NO VETOR REPONSÁVEL PELAS LINHAS
    for(int i = 0; i < m->numLinhas; i++){
        
        m->linhas[i] = criaSentinela();

    }
    
    m->colunas = (No**) calloc(qtdeColunas, sizeof(No*));

    //INSERÇÃO DOS SENTINELAS NO VETOR RESPONSÁVEL PELAS COLUNAS
    for(int i = 0; i < m->numColunas; i++){

        m->colunas[i] = criaSentinela();

    }

    return m;

}

No* getNoLinha(Matriz* m, int linha, int coluna){

    No* sentinela = m->linhas[linha];
    No* aux = sentinela->direita;
    while(aux != sentinela && coluna > aux->coluna) aux = aux->direita;
    
    return aux;

}

No* getNoColuna(Matriz* m, int linha, int coluna){

    No* sentinela = m->colunas[coluna];
    No* aux = sentinela->baixo;
    while(aux != sentinela && linha > aux->linha) aux = aux->baixo;

    return aux;

}

No* criaNovoNo(int valor, int linha, int coluna){

    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->linha = linha;
    novoNo->coluna = coluna;


    return novoNo;

}

void insereNaLinha(No* ref, No* no){

    no->direita = ref;
    no->esquerda = ref->esquerda;
    ref->esquerda->direita = no;
    ref->esquerda = no;

}

void insereNaColuna(No* ref, No* no){

    no->baixo = ref;
    no->cima = ref->cima;
    ref->cima->baixo = ref->cima;
    ref->cima = no;

}

Boolean matriz_atribuir(Matriz* m, int linha, int coluna, int valor){

    if(m == NULL) return false;
    if(linha >= m->numLinhas) return false;
    if(coluna >= m->numColunas) return false;
    if(valor >= ERRO) return false;
                    
    No* auxLinha = getNoLinha(m, linha, coluna);
    if(auxLinha->coluna == coluna){

        auxLinha->valor = valor;

    }else{

        No* novoNo = criaNovoNo(valor, linha, coluna);
        No* auxColuna = getNoColuna(m, linha, coluna);
        insereNaLinha(auxLinha, novoNo);
        insereNaColuna(auxColuna, novoNo);

    }

    return true;

}


int matriz_acessar(Matriz* m, int linha, int coluna){

    if(m == NULL) return ERRO;
    if(linha >= m->numLinhas) return ERRO;
    if(coluna >= m->numLinhas) return ERRO;

    No* no = getNoLinha(m, linha, coluna);

    return no->valor;

}


void matriz_imprimir(Matriz* m){

    if(m == NULL){
        
        printf("Matriz inexistente!\n");
        return;
    
    }

    printf("Matriz:\n");
    for(int i = 0; i < m->numLinhas; i++){

        No* sentinela = m->linhas[i];
        No* aux = sentinela->direita;

        for(int j = 0; j < m->numColunas; j++){

            if(aux->coluna == j){

                printf("%d\t", aux->valor);
                aux = aux->direita;

            }else printf("0\t");

        }

        printf("\n");

    }

    printf("\n");

}

void no_destruir(No* no, No* sentinela){

    if(no == sentinela) return;

    no_destruir(no->direita, sentinela);
    free(no);

}

void matriz_desalocar(Matriz** matriz){

    Matriz* m = *matriz;

    for(int i = 0; i < m->numLinhas; i++){

        No* sentinela = m->linhas[i];
        No* aux = sentinela->direita;
        no_destruir(aux, sentinela);
        free(m->linhas[i]);

    }

    free(m->linhas);
    free(m->colunas);
    free(m);
    *matriz = NULL;

}
