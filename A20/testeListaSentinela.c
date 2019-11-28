#include <stdio.h>
#include "Lista_sentinela.h"

void teste(){

    //CRIAÇÃO DA LISTA
    Lista* l = lista_criar();

    //INSERÇÃO DE VALORES NA LISTA
    lista_inserir(l, 10, 0);
    lista_inserir(l, 20, 1);
    lista_inserir(l, 40, 2);
    lista_inserir(l, 50, 3);
    lista_inserir(l, 30, 2);

    lista_imprimir(l);

    //INSERÇÃO NO FINAL DA LISTA
    lista_inserir_fim(l, 60);

    lista_imprimir(l);

    //TESTE DE BUSCA
    int elemento;
    int pos = 2;
    if(lista_buscar(l, pos, &elemento)){

        printf("\nElemento encontrado! Elemento: %d\n", elemento);

    }else{

        printf("\nElemento não encontrado!\n");

    }

    //TESTE DE CONTINGÊNCIA
    elemento = 30;
    if(lista_contem(l, elemento)){

        printf("\nA lista contem o elemento %d\n", elemento);

    }else{

        printf("\nA lista não contem o elemento %d\n", elemento);

    }

    //TESTE DE RETORNO DA POSIÇÃO
    int posicao = lista_posicao(l, elemento);
    printf("\nA posição do elemento %d é %d\n", elemento, posicao);

    //TESTE DE RETORNO DO TAMANHO DA LISTA
    printf("\nA lista possui tamanho %d\n", lista_tamanho(l));

    //TESTE DE REMOÇÃO
    int* removido;
    removido = lista_remover1(l, 2);
    printf("\nElemento removido: %d\n", *removido);

    lista_imprimir(l);

    if(lista_remover2(l, 2, removido)){

        printf("\nElemento removido: %d\n", *removido);
    
    }else{

        printf("\nElemento inexistente\n");

    }

    lista_imprimir(l);

    if(lista_remover_elemento(l, 60)){

        printf("\nElemento removido!\n");

    }else{

        printf("\nElemento inexistente\n");

    }

    lista_imprimir(l);

    //TESTE DE DESTRUIÇÃO
    l = lista_destruir(l);
    lista_imprimir(l);

}

int main(){

    teste();

    return 0;

}