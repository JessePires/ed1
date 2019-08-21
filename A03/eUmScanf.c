#include <stdio.h>

void potencia(float base, int expoente, float *resultado);

void potencia(float base, int expoente, float *resultado){

  float aux = 1;
  int iteracoes = (expoente > 0 ? expoente : expoente * -1);

  for(int i = 0; i < iteracoes; i++){

    aux *= base;

  }

  *resultado = (expoente > 0 ? aux : 1 / aux);

}

int main(){

  float resultado = 1;

  potencia(2, 4, &resultado);
  printf("2 ^ 4 = %.2f\n", resultado);

  potencia(2, 0, &resultado);
  printf("2 ^ 0 = %.2f\n", resultado);

  potencia(2.5, 2, &resultado);
  printf("2.5 ^ 2 = %.2f\n", resultado);

  potencia(2, 1, &resultado);
  printf("2 ^ 1 = %.2f\n", resultado);

  potencia(-2, 2, &resultado);
  printf("-2 ^ 2 = %.2f\n", resultado);

  potencia(2, -2, &resultado);
  printf("2 ^ -2 = %.2f\n", resultado);

  return 0;

}
