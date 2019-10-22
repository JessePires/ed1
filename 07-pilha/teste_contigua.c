#include<stdio.h>
#include "Pilha_contigua.h"


void teste1(){

    //TESTE DE CRIAÇÃO DE PILHA
    Pilha* p = pilha_criar();

    Pilha* p2;

    //TESTE DE ADIÇÃO DE VALORES
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_push(p, 40);

    //TESTE DE IMPRESSÃO
    printf("Pilha <p>: ");
    pilha_imprimir(p); // [10,20,30] (base -> topo)

    //TESTES DE REMOÇÃO DE VALORES
    int* valorRemovido = pilha_pop1(p);
    printf("Pilha <p>: ");
    pilha_imprimir(p);
    printf("Valor removido: %d\n", *valorRemovido);

    pilha_pop2(p, valorRemovido);
    printf("Pilha p: ");
    pilha_imprimir(p);
    printf("Valor removido: %d\n", *valorRemovido);

    //TESTE DE LOCALIZAÇÃO DA POSIÇÃO DE UM ELEMENTO
    printf("Posicao do elemento %d: %d\n", 10, pilha_posicao(p, 10));

    //TESTE DE RETORNO DO TAMANHO DA PILHA
    printf("Tamanho da pilha: %d\n", pilha_tamanho(p));

    //TESTE DE ADIÇÃO DOS VALORES DE UM VETOR NA PILHA
    int v[3] = {50, 60, 70};
    pilha_pushAll(p, v, 3);
    printf("Pilha p: ");
    pilha_imprimir(p);

    //TESTE DE INVERSÃO DA PILHA
    pilha_inverter(p);
    printf("Pilha p invertida: ");
    pilha_imprimir(p);

    //TESTE DE CLONAGEM DA PILHA
    p2 = pilha_clone(p);
    printf("Pilha p2 (clone de p): ");
    pilha_imprimir(p2);

    //TESTE DE DESTRUIÇÃO DA PILHA
    p = pilha_destruir(p);
    pilha_imprimir(p);

}

int main(){
    teste1();
}