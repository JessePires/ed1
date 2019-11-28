#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DADOS
typedef struct{

    char cod[6];
    char* nome;
    float* preco;
    int qtde; //qtde de produtos no estoque
    int qtdePrecos; //qtde de preços

}Produto;

typedef struct{

    char* nome;
    Produto** produtos;
    int qtde; //qtde de produtos
    int tam; //tamanho do vetor

}Empresa;

//PROTÓTIPOS
Produto* novoProduto(char* cod, char* desc, float preco, int qtde);
float mediaPreco(Empresa* e);
void shiftLeft(Produto** produtos, int posicao);
int buscaRemoveDuplicados(Empresa* e, char* cod); //retorna a quantidade de ocorrências removidas


//IMPLEMENTAÇÕES
Produto* novoProduto(char* cod, char* desc, float preco, int qtde){

    if(strlen(cod) > 6){

        return NULL;

    }

    Produto* novoProduto = (Produto*) malloc(sizeof(Produto));
    novoProduto->nome = (char*) calloc(strlen(desc), sizeof(char));
    novoProduto->preco = (float*) calloc(1, sizeof(float));

    strcpy(novoProduto->cod, cod);
    strcpy(novoProduto->nome, desc);
    novoProduto->preco[0] = preco;
    novoProduto->qtde = qtde;
    novoProduto->qtdePrecos = 1;

    return novoProduto;

}

float mediaPreco(Empresa* e){

    float somaPrecos = 0;
    int qtdTotalPrecos = 0;

    for(int i = 0; i < e->qtde; i++){

        for(int j = 0; j < *(e->produtos[i])->qtdePrecos; j++){

            somaPrecos += *(e->produtos[i])->preco[j];
            qtdTotalPrecos++;

        }

    }

    return somaPrecos/qtdTotalPrecos;

}

void shiftLeft(Empresa* e, int posicao){

    for(int i = posicao; i < e->qtde; i++){

        e->produtos[i] = e->produtos[i+1];

    }

    e->qtde--;

} 

int buscaRemoveDuplicados(Empresa* e, char* cod){

    int qtdOcorrencias = 0;

    for(int i = 0; i < e->qtde; i++){

        if(strcmp(*(e->produtos[i])->cod, cod)){

            qtdOcorrencias++;
            if(qtdOcorrencias > 1){

                free(*(e->produtos[i]));
                shiftLeft(e, i);

            }

        }

    }

    return qtdOcorrencias--;

}

int main(){

    Produto* p1 = novoProduto("i1", "memória Ram", 259.90, 10);
    Produto* p2 = novoProduto("i2", "HD", 280.00, 8);

    return 0;

}