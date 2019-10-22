#include<stdio.h>
#include "Pilha_encadeada.h"


void teste1(){

    //TESTE DE CRIAÇÃO
    Pilha* p = pilha_criar();

    Pilha* p2;

    //TESTE DE ADIÇÃO DE VALORES
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);

    //TESTE DE IMPRESSÃO
    printf("Pilha <p>: ");
    pilha_imprimir(p); // [30,20,10] (topo -> base)
    
    //TESTE DE POSIÇÃO DOS ELEMENTOS
    printf("Posição do elemento %d na pilha: %d\n", 10, pilha_posicao(p, 30));

    //TESTE DE ADIÇÃO DE VALORES DE UM VETOR
    int v[3] = {40, 50, 60};
    int qtdeAdicionados = pilha_pushAll(p, v, 3);
    printf("Pilha <p>: ");
    pilha_imprimir(p);
    printf("Qtde de elementos adicionados a pilha: %d\n", qtdeAdicionados);

    //TESTE DE INVERSÃO DA PILHA
    p = pilha_inverter(p);
    pilha_imprimir(p);

    //TESTE DE CRIAÇÃO DE UM CLONE DA PILHA <p>
    p2 = pilha_clone(p);
    printf("Pilha <p2>: ");
    pilha_imprimir(p2);

    //TESTE DE REMOÇÃO DE ELEMENTOS COM A FUNÇÃO pilha_pop1()
    int* valorRemovido = pilha_pop1(p2);
    printf("Pilha <p2>: ");
    pilha_imprimir(p2);
    printf("Elemento removido: %d\n", *valorRemovido);

    //TESTE DE REMOÇÃO DE ELEMENTOS COM A FUNÇÃO pilha_pop1()
    int* valorRemovido2;
    pilha_pop2(p2, valorRemovido);
    printf("Pilha <p2>: ");
    pilha_imprimir(p2);
    printf("Elemento removido: %d\n", *valorRemovido);

    //TESTE DE DESTRUIÇÃO DA PILHA
    p = pilha_destruir(p);
    pilha_imprimir(p);

}

int main(){

    teste1();

}