#include <stdio.h>
#include <FilaCircular.h>

void teste(){

    //TESTE DE CRIAÇÃO DE UMA FILA
    Fila* f = fila_criar();

    //TESTE DE INSERÇÃO
    fila_inserir(f, 10);
    fila_inserir(f, 20);
    fila_inserir(f, 30);    

}

int main(){

    teste();
    return 0;

}