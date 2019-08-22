#include <stdio.h>

int inversao(int numero);
void inversaoPonteiro(int numero, int *inverso);

int inversao(int numero){

  int inverso = 0;
  int digito = 0;

  if(numero < 0){

    return -1;

  }else{

    while(numero > 0){

      digito = numero % 10;
      inverso = (inverso * 10) + digito;
      numero /= 10;

    }

    return inverso;

  }

}

void inversaoPonteiro(int numero, int *inverso){

  int digito = 0;
  int aux = 0;

  if(numero < 0){

    *inverso = -1;

  }else{

    while(numero > 0){

      digito = numero % 10;
      aux = (aux * 10) + digito;
      numero /= 10;

    }

    *inverso = aux;

  }

}

int main(){

  int inverso = 0;
  int numero;

  printf("TESTES ESTRATÉGIA RETURN\n");
  printf("Inverso de 1: %d\n", inversao(1));
  printf("Inverso de 12: %d\n", inversao(12));
  printf("Inverso de 123: %d\n", inversao(123));
  printf("Inverso de 1234: %d\n", inversao(1234));
  printf("Inversao de -1234: %d\n", inversao(-1234));


  printf("\nTESTES ESTRATÉGIA SCANF\n");
  inversaoPonteiro(1, &inverso);
  printf("Inverso de 1: %d\n", inverso);

  inversaoPonteiro(12, &inverso);
  printf("Inverso de 12: %d\n", inverso);

  inversaoPonteiro(123, &inverso);
  printf("Inverso de 123: %d\n", inverso);

  inversaoPonteiro(1234, &inverso);
  printf("Inverso de 1234: %d\n", inverso);

  inversaoPonteiro(-1234, &inverso);
  printf("Inversao de -1234: %d\n", inverso);

  printf("\nOBS: -1 SIGNIFICA ERRO EM RAZÃO DE PASSAGEM DE NÚMEROS NEGATIVOS PARA A FUNÇÃO\n");

  return 0;

}
