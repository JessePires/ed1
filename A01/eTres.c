#include <stdio.h>

char retornaConceito(float nota);

char retornaConceito(float nota){

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

int main(){

  float nota = 11;
  char conceito;

  conceito = retornaConceito(nota);

  printf("Seu conceito é %c\n", conceito);

  return 0;

}
