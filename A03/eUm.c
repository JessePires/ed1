#include <stdio.h>

float potencia(float base, int expoente);
void potenciaPonteiro(float base, int expoente, float *resultado);

float potencia(float base, int expoente){

  int iteracoes;
  float resultado = 1;

  iteracoes = (expoente > 0 ? expoente : expoente * -1);

  for(int i = 0; i < iteracoes; i++){

    resultado *= base;

  }

  return (expoente > 0 ? resultado : 1 / resultado);

}

void potenciaPonteiro(float base, int expoente, float *resultado){

  float aux = 1;
  int iteracoes = (expoente > 0 ? expoente : expoente * -1);

  for(int i = 0; i < iteracoes; i++){

    aux *= base;

  }

  *resultado = (expoente > 0 ? aux : 1 / aux);

}

int main(){

  float resultado = 1;

  //testes estratégia Return
  printf("2 ^ 4 = %.2f\n", potencia(2, 4));
  printf("2 ^ 0 = %.2f\n", potencia(2, 0));
  printf("2.5 ^ 2 = %.2f\n", potencia(2.5, 2));
  printf("2 ^ 1 = %.2f\n", potencia(2, 1));
  printf("-2 ^ 2 = %.2f\n", potencia(-2, 2));
  printf("2 ^ -2 = %.2f\n", potencia(2, -2));

  //testes estratégia Scanf
  potenciaPonteiro(2, 4, &resultado);
  printf("2 ^ 4 = %.2f\n", resultado);

  potenciaPonteiro(2, 0, &resultado);
  printf("2 ^ 0 = %.2f\n", resultado);

  potenciaPonteiro(2.5, 2, &resultado);
  printf("2.5 ^ 2 = %.2f\n", resultado);

  potenciaPonteiro(2, 1, &resultado);
  printf("2 ^ 1 = %.2f\n", resultado);

  potenciaPonteiro(-2, 2, &resultado);
  printf("-2 ^ 2 = %.2f\n", resultado);

  potenciaPonteiro(2, -2, &resultado);
  printf("2 ^ -2 = %.2f\n", resultado);

  return 0;

}
