#include <stdio.h>

char retornaConceito(float nota);
void conceitoPonteiro(float nota, char *conceito);

char retornaConceito(float nota){

  if(nota > 10){

    return 'X';

  }

  if(nota < 0){

    return 'X';

  }

  if(nota >= 9){

    return 'A';

  }else if(nota >= 7){

    return 'B';

  }else if(nota >= 6){

    return 'C';

  }else{

    return 'I';

  }

}

void conceitoPonteiro(float nota, char *conceito){

  if(nota < 0 || nota > 10){

    *conceito = 'X';

  }else if(nota >= 9){

    *conceito = 'A';

  }else if(nota >= 7){

    *conceito = 'B';

  }else if(nota >= 6){

    *conceito = 'C';

  }else{

    *conceito = 'I';

  }

}

int main(){

  char conceito;

  //testes estratégia Return
  printf("Conceito: %c\n", retornaConceito(9));
  printf("Conceito: %c\n", retornaConceito(8));
  printf("Conceito: %c\n", retornaConceito(6.5));
  printf("Conceito: %c\n", retornaConceito(5.9));
  printf("Conceito: %c\n", retornaConceito(-1));
  printf("Conceito: %c\n", retornaConceito(10.1));

  //testes estratégia Scanf
  conceitoPonteiro(9, &conceito);
  printf("\nConceito: %c\n", conceito);

  conceitoPonteiro(8, &conceito);
  printf("Conceito: %c\n", conceito);

  conceitoPonteiro(6.5, &conceito);
  printf("Conceito: %c\n", conceito);

  conceitoPonteiro(5.9, &conceito);
  printf("Conceito: %c\n", conceito);

  conceitoPonteiro(-1, &conceito);
  printf("Conceito: %c\n", conceito);

  conceitoPonteiro(10.1, &conceito);
  printf("Conceito: %c\n", conceito);

  return 0;

}
