#include <stdio.h>
#include "FilaEncadeada.h"

void teste(){

    //TESTE DE CRIAÇÃO DA FILA
    Fila* f = fila_criar();

    //TESTE DE INSERÇÃO
    fila_inserir(f, 10);
    fila_inserir(f, 20);
    fila_inserir(f, 30);    
    fila_inserir(f, 40);    
    fila_inserir(f, 25);

    fila_imprimir(f);

    //TESTE DE REMOÇÃO
    int* removido = fila_remover1(f);
    printf("Elemento removido: %d\n", *removido);
    int removido2;
    fila_remover2(f, &removido2);
    printf("Segundo elemento removido: %d\n", removido2);

    fila_imprimir(f);

    int primeiro;
    fila_primeiro(f, &primeiro);
    printf("O primeiro elemento da fila é %d\n", primeiro);

    //TESTE DA FUNÇÃO fila_tamanho()
    printf("A fila possui o tamanho = %d\n", fila_tamanho(f));

    //TESTE DA FUNÇÃO fila_contem()
    int valorTeste = 30;
    if(fila_contem(f, valorTeste)){

        printf("A fila contem o elemento %d!\n", valorTeste);

    }else{

        printf("A fila não contem o elemento %d!\n", valorTeste);

    }

    //TESTE DE DESTRUIÇÃO
    f = fila_destruir(f);
    fila_imprimir(f);

}

int main(){

    teste();
    return 0;

}