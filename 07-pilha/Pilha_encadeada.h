#include <stdio.h>
#include <stdlib.h>

//Estratégia de armazenamento: Topo ---------> Base

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
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
    int qtde;
}Pilha;

Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void no_destruir(No* no);
Pilha* pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
Pilha* pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);
void push_recursivo(Pilha* p, No* no);


//IMPLEMENTAÇÕES

/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */
Pilha* pilha_criar(){

    return (Pilha*) malloc(sizeof(Pilha));

}

/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */
Boolean pilha_push(Pilha* p, Tipo elemento){

    if(p != NULL){

        No* no = (No*) malloc(sizeof(No));
        no->dado = elemento;
        
        if(p->topo != NULL){

            no->prox = p->topo;

        }

        p->topo = no;
        p->qtde++;
        return true;

    }

    return false;

}

/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return: Endereço do elemento removido ou NULL caso contrário.
 */
Tipo* pilha_pop1(Pilha* p){

    if(p->topo != NULL){

        No* no = p->topo;
        Tipo* end = (Tipo*) malloc(sizeof(Tipo));
        end = &no->dado;
        p->topo = no->prox;
        p->qtde--;

        return end;

    }

    return NULL;

}

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço 
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */
Boolean pilha_pop2(Pilha* p, Tipo* end){

    if(p->topo != NULL){

        No* no = p->topo;
        end = &no->dado;
        p->topo = no->prox;
        p->qtde--;

        return true;

    }

    return false;

}

/**
 * Desaloca os nós recursivamente
 */
void no_destruir(No* no){

    if(no == NULL){

        return;

    }

    no_destruir(no->prox);
    free(no);

}

/**
 * Desaloca a pilha <p>.
 */
Pilha* pilha_destruir(Pilha* p){

    no_destruir(p->topo);
    free(p);
    return NULL;

}

/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */
void pilha_imprimir(Pilha* p){

    if(p != NULL){

        No* aux = p->topo;

        printf("Topo<-[");
        for(int i = 0; i < p->qtde; i++){

            printf("%d", aux->dado);
            printf("%s", (i == p->qtde - 1? "]->Base\n" : ", "));
            aux = aux->prox;

        }

        free(aux);

    }else{

        printf("Imposível imprimir os elementos de <p>!\n");

    }

}

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */
int pilha_posicao(Pilha* p, Tipo elemento){

    No* aux = p->topo;
    int cont = 0;

    for(int i = 0; i < p->qtde; i++){

        if(aux->dado == elemento){

            return cont;

        }

        aux = aux->prox;
        cont++;

    }

    return -1;

}

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */
int pilha_tamanho(Pilha* p){

    return p->qtde;

}

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){

    for(int i = 0; i < tam; i++){

        pilha_push(p, vetor[i]);

    }

    return tam;

}

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 * @return: Endereço da Pilha invertida.
 */
Pilha* pilha_inverter(Pilha* p){

    No* aux = p->topo;
    Pilha* p2 = pilha_criar();

    for(int i = 0; i < p->qtde; i++){

        pilha_push(p2, aux->dado);
        aux = aux->prox;

    }

    free(aux);
    return p2;

}

/**
* Adiciona de maneira recursiva
* @param no: endereco do nó
*/
void push_recursivo(Pilha* p, No* no){

    if(no == NULL){

        return;

    }

    push_recursivo(p, no->prox);
    pilha_push(p, no->dado);

}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */
Pilha* pilha_clone(Pilha* p){

    Pilha* p2 = pilha_criar();
    push_recursivo(p2, p->topo);
    return p2;

}