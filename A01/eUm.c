#include <stdio.h>

void potenciacao(double base, double expoente, double *resultado);

void potenciacao(double base, double expoente, double *resultado){

  double aux = 1;

  if(expoente == 1){

    *resultado = base;

  }else if(expoente == 0){

    *resultado = 1;

  }else{

    if(expoente > 0){

      for(double i = 0; i < expoente; i++){

        aux *= base;

      }

      *resultado = aux;

    }else{

      for(double i = expoente; i < 0; i++){

        aux *= base;

      }

      *resultado = 1/aux;

    }

  }

}

int main(){

  double resultado;

  potenciacao(3, -2, &resultado);

  printf("%f\n", resultado);

}
