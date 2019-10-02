#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int cod;
    char nome[30];
    double preco;
}Produto;

//PROTÓTIPOS

void troca(void* a, void* b, int tamElemento);
int comparaInt(void* a, void* b);
int comparaChar(void* a, void* b);
int comparaProdutoPreco(void* a, void* b);
void bubble_generico(void* v, int n, int tamElemento, int (*funcao)(void* a, void* b));
void print(void* v, int n, int tamElemento, void(*print)(void*));

//IMPLEMENTAÇÃO DAS FUNÇÕES 

void troca(void* a, void* b, int tamElemento){

    void* temp = malloc(tamElemento);

    memcpy(temp, a, tamElemento);
    memcpy(a, b, tamElemento);
    memcpy(b, temp, tamElemento);

    free(temp);

}

int comparaInt(void* a, void* b){

    int* x = (int*)a;
    int* y = (int*)b;

    if(*x > *y){
    
        return 1;
    
    }else if(*x < *y){
    
        return -1;
    
    }else{
    
        return 0;
    
    }

}

int comparaChar(void* a, void* b){

    char* x = (char*)a;
    char* y = (char*)b;
    
    if(*x > *y){
    
        return 1;
    
    }else if(*x < *y){
    
        return -1;
    
    }else{
    
        return 0;
    
    }

}

int comparaProdutoPreco(void* a, void* b){
   
    Produto* x = (Produto*)a;
    Produto* y = (Produto*)b;
   
    if(x->preco > y->preco){
    
        return 1;
    
    }else if(x->preco < y->preco){
        
        return -1;
    
    }else{
        
        return 0;
    }

}

void bubble_generico(void* v, int n, int tamElemento, int (*funcao)(void* a, void* b)){
    
    int i, fim;

    for (fim = n; fim > 0; fim--) {
    
        int houve_troca = 0;
    
        for (i = 0; i < fim; i++){
    
            void* a = v + i * tamElemento; // &v[i] ou (v + i)
            void* b = a + tamElemento; // &v[i + 1] ou (v + (i + 1))

            if(funcao(a, b) > 0){

                troca(a, b, tamElemento);
                houve_troca = 1;

            }

        }
    
        if (houve_troca == 0){
            
            return;
            
        }
    
    }

}

void printInt(void* elemento){

    int* p = (int*) elemento;
    printf("%d", *p);

}

void printStruct(void* elemento){

    Produto* p = (Produto*) elemento;
    printf("(%d - %s - %.2f)", p->cod, p->nome, p->preco);

}

void printChar(void* elemento){

    char* p = (char*) elemento;
    printf("%c", *p);

}

void print(void* v, int n, int tamElemento, void(*print)(void*)){

    printf("[");
    for(int i = 0; i < n; i++){

        void* elemento = v + i * tamElemento;

        print(elemento);

        if(i < i - 1){

            printf(", ");

        }

    }
    printf("\n");

}

int main(){

    int v1[8] = {25,48,37,12,57,86,33,92};
    
    Produto vp[5] = {
        {5,"555",5.5},
        {1,"111",1.1},
        {4,"444",4.4},
        {3,"333",3.3},
        {2,"222",2.2}
    };

    char vet_char[5] = {'x','d', 'e', 'a', 'r'};

    bubble_generico(v1, 8, sizeof(int), &comparaInt);
    bubble_generico(vp, 5, sizeof(Produto), &comparaProdutoPreco);
    bubble_generico(vet_char, 5, sizeof(char), &comparaChar);

    print(v1, 8, sizeof(int), &printInt);
    print(vp, 5, sizeof(Produto), &printStruct);
    print(vet_char, 5, sizeof(char), &printChar);

    return 0;

}