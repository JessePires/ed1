#include <stdio.h>

float potencia(float base, int expoente);

float potencia(float base, int expoente){

  int iteracoes;
  float resultado = 1;

  iteracoes = (expoente > 0 ? expoente : expoente * -1);

  for(int i = 0; i < iteracoes; i++){

    resultado *= base;

  }

  return (expoente > 0 ? resultado : 1 / resultado);

}

int main(){

  printf("2 ^ 4 = %.2f\n", potencia(2, 4));
  printf("2 ^ 0 = %.2f\n", potencia(2, 0));
  printf("2.5 ^ 2 = %.2f\n", potencia(2.5, 2));
  printf("2 ^ 1 = %.2f\n", potencia(2, 1));
  printf("-2 ^ 2 = %.2f\n", potencia(-2, 2));
  printf("2 ^ -2 = %.2f\n", potencia(2, -2));

}
