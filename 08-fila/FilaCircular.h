
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
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
Boolean fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);


//IMPLEMENTAÇÕES

Fila* fila_criar(){

    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->tam = 5;
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

//auxiliar de fila_inserir()
void fila_garanteEspaco(Fila* f){

    if(f->inicio != (f->fim + 1) % f->tam) return;
    
    Tipo* v = (Tipo*) calloc(f->tam * 2, sizeof(Tipo));
    for(int i = f->inicio; i < f->fim; i++){

        printf("aqui\n");
        v[i % f->tam] = f->vetor[i % f->tam];

    }

    f->vetor = v;
    f->tam += 5;

}

Boolean fila_inserir(Fila* f, Tipo elemento){

    fila_garanteEspaco(f);

    if(f != NULL){
        
        f->vetor[f->fim] = elemento;
        f->fim++;
        return true;

    }

    return false;

}

Tipo* fila_remover1(Fila* f){

    if(f->inicio == f->fim){

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

    *endereco = f->vetor[f->inicio];
    f->inicio++;
    return true;

}

Boolean fila_primeiro(Fila* f, Tipo* endereco){

    if(f != NULL){

        *endereco = f->vetor[f->inicio];
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

    for(int i = f->inicio; i < f->fim; i++){

        if(f->vetor[i % f->tam] == elemento){

            return true;

        }

    }

    return false;

}

void fila_imprimir(Fila* f){

    if(f != NULL){

        printf("Fila circular <f>: [");
        for(int i = f->inicio; i < f->fim; i++){

            printf("%d", f->vetor[i % f->tam]);
            printf("%s", (i < f->fim % f->tam - 1 ? ", " : "]\n"));

        }

    }else{

        printf("Impossível imprimir a fila!\n");

    }

}