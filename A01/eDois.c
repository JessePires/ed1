#include <stdio.h>

void inversao(int numero, int *milhares, int *centenas, int *dezenas, int *unidades);

void inversao(int numero, int *milhares, int *centenas, int *dezenas, int *unidades){

  *milhares = numero / 1000;
  numero = numero % 1000;

  *centenas = numero/100;
  numero = numero % 100;

  *dezenas = numero / 10;
  numero = numero % 10;

  *unidades = numero % 10;

}

int main(){

  int numero = 1234;
  int milhares = 0;
  int centenas = 0;
  int dezenas = 0;
  int unidades = 0;

  inversao(numero, &milhares, &centenas, &dezenas, &unidades);

  printf("%d invertido é %d%d%d%d\n", numero, unidades, dezenas, centenas, milhares);

  return 0;

}
