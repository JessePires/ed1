#include <stdio.h>

int verificaValor(int valor);
void qtdCedulas(int valor, int *qtdCem, int *qtdCinquenta, int *qtdVinte, int *qtdDez, int *qtdCinco, int *qtdDois);

int verificaValor(int valor){

  if(valor % 2 == 0){

    return 1;

  }

  return 0;

}

void qtdCedulas(int valor, int *qtdCem, int *qtdCinquenta, int *qtdVinte, int *qtdDez, int *qtdCinco, int *qtdDois){

  if(verificaValor(valor) == 1){

    *qtdCem = valor / 100;
    valor = valor % 100;

    *qtdCinquenta = valor / 50;
    valor = valor % 50;

    *qtdVinte = valor / 20;
    valor = valor % 20;

    *qtdDez = valor / 10;
    valor = valor % 10;

    *qtdCinco = valor / 5;
    valor = valor % 5;

    *qtdDois = valor / 2;
    valor = valor % 2;

  }

}

int main(){

  int valor = 2;
  int qtdCem = 0;
  int qtdCinquenta = 0;
  int qtdVinte = 0;
  int qtdDez = 0;
  int qtdCinco = 0;
  int qtdDois = 0;

  qtdCedulas(valor, &qtdCem, &qtdCinquenta, &qtdVinte, &qtdDez, &qtdCinco, &qtdDois);

  printf("Qtd de cédulas de 100: %d\n", qtdCem);
  printf("Qtd de cédulas de 50: %d\n", qtdCinquenta);
  printf("Qtd de cédulas de 20: %d\n", qtdVinte);
  printf("Qtd de cédulas de 10: %d\n", qtdDez);
  printf("Qtd de cédulas de 5: %d\n", qtdCinco);
  printf("Qtd de cédulas de 2: %d\n", qtdDois);
  printf("\nCaso todos valores estejam zerados, significa que a quantia que você deseja é impossível de ser sacada em razão das cédulas disponíveis.\n");
  printf("Exemplos de quantias que não podem ser sacadas: 1, 21, 251, 301, 433\n");
  return 0;

}
