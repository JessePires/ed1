
#include <stdio.h>
#include <stdlib.h>


//TIPOS DE DADOS
typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;

//FILA É VAZIA SE INÍCIO == FIM


//PROTÓTIPOS

Fila* fila_criar();
Fila* fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, Tipo elemento); //TENTAR IMPLEMENTAR OLHANDO SÓ PARA O INÍCIO E O FIM
                                              //USAR MOD DE 5 PARA ATUALIZAR O FIM

                                              //0%5 = 0     5%5 = 0
                                              //1%5 = 1     6%5 = 1
                                              //2%5 = 2     7%5 = 2
                                              //3%5 = 3     8%5 = 3
                                              //4%5 = 4     9%5 = 4
                                              //            10%5 = 5  

Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
Boolean fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);


//IMPLEMENTAÇÕES

Fila* fila_criar(){

    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->tam = 0;
    f->vetor = (Tipo*) calloc(5, sizeof(Tipo));
    f->inicio = 0;
    f->fim = 0;

    return f;

}

Fila* fila_destruir(Fila* f){

    free(f->vetor);
    free(f);
    return NULL;

}

void fila_garanteEspaco(Fila* f){

    

}

Boolean fila_inserir(Fila* f, Tipo elemento){



}

Tipo* fila_remover1(Fila* f){

    if(f->inicio == 0 && f->fim == 0){

        return NULL;

    }

    Tipo* endereco = (Tipo*) malloc(sizeof(Tipo));
    endereco = &f->vetor[f->inicio];
    f->inicio++;
    return endereco;

}

Boolean fila_remover2(Fila* f, Tipo* endereco){

    if(f->inicio == 0 && f->fim == 0){

        return false;

    }

    endereco = &f->vetor[f->inicio];
    f->inicio++;
    return true;

}

Boolean fila_primeiro(Fila* f, Tipo* endereco){

    if(f != NULL){

        endereco = &f->vetor[f->inicio];
        return true;

    }

    return false;

}

int fila_tamanho(Fila* f){

    if(f != NULL){

        return f->tam;

    }

    return -1;

}

Boolean fila_contem(Fila* f, Tipo elemento){

    for(int i = 0; i < f->tam - 1; i++){

        if(f->vetor[i] == elemento){

            return true;

        }

    }

    return false;

}

void fila_imprimir(Fila* f){

    printf("Fila circular <f>: [");
    for(int i = 0; i < f->tam; i++){

        printf("%d", f->vetor[i]);
        
        if(i == f->inicio){

            printf("(início");

        }else if(i == f->fim){

            printf("(fim)");

        }
        
        printf("%s", (i < f->tam - 1 ? ", " : "]\n"));

    }

}