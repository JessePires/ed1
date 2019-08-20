#include <stdio.h>
#include <string.h>

void formataDia(int dia, char diaVetor[]){

  switch(dia){

    case 1:

      strcpy(diaVetor, "Um");
      break;

    case 2:

      strcpy(diaVetor, "Dois");
      break;

    case 3:

      strcpy(diaVetor, "Três");
      break;

    case 4:

      strcpy(diaVetor, "Quatro");
      break;

    case 5:

      strcpy(diaVetor, "Cinco");
      break;

    case 6:

      strcpy(diaVetor, "Seis");
      break;

    case 7:

      strcpy(diaVetor, "Sete");
      break;

    case 8:

      strcpy(diaVetor, "Oito");
      break;

    case 9:

      strcpy(diaVetor, "Nove");
      break;

    case 10:

      strcpy(diaVetor, "Dez");
      break;

    case 11:

      strcpy(diaVetor, "Onze");
      break;

    case 12:

      strcpy(diaVetor, "Doze");
      break;

    case 13:

      strcpy(diaVetor, "Treze");
      break;

    case 14:

      strcpy(diaVetor, "Quatorze");
      break;

    case 15:

      strcpy(diaVetor, "Quinze");
      break;

    case 16:

      strcpy(diaVetor, "Dezesseis");
      break;

    case 17:

      strcpy(diaVetor, "Dezessete");
      break;

    case 18:

      strcpy(diaVetor, "Dezoito");
      break;

    case 19:

      strcpy(diaVetor, "Dezenove");
      break;

    case 20:

      strcpy(diaVetor, "Vinte");
      break;

    case 21:

      strcpy(diaVetor, "Vinte e Um");
      break;

    case 22:

      strcpy(diaVetor, "Vinte e Dois");
      break;

    case 23:

      strcpy(diaVetor, "Vinte e Três");
      break;

    case 24:

      strcpy(diaVetor, "Vinte e Quatro");
      break;

    case 25:

      strcpy(diaVetor, "Vinte e Cinco");
      break;

    case 26:

      strcpy(diaVetor, "Vinte e Seis");
      break;

    case 27:

      strcpy(diaVetor, "Vinte e Sete");
      break;

    case 28:

      strcpy(diaVetor, "Vinte e Oito");
      break;

    case 29:

      strcpy(diaVetor, "Vinte e Nove");
      break;

    case 30:

      strcpy(diaVetor, "Trinta");
      break;

    case 31:

      strcpy(diaVetor, "Trinta e Um");
      break;

    default:

      strcpy(diaVetor, "Erro");

  }

}

void formataMes(int mes, char diaVetor[], char mesVetor[]){

    switch(mes){

      case 1:

        strcpy(mesVetor, "Janeiro");
        break;

      case 2:

        strcpy(mesVetor, "Fevereiro");
        break;

      case 3:

        strcpy(mesVetor, "Março");
        break;

      case 4:

        strcpy(mesVetor, "Abril");
        break;

      case 5:

        strcpy(mesVetor, "Maio");
        break;

      case 6:

        strcpy(mesVetor, "Junho");
        break;

      case 7:

        strcpy(mesVetor, "Julho");
        break;

      case 8:

        strcpy(mesVetor, "Agosto");
        break;

      case 9:

        strcpy(mesVetor, "Setembro");
        break;

      case 10:

        strcpy(mesVetor, "Outubro");
        break;

      case 11:

        strcpy(mesVetor, "Novembro");
        break;

      case 12:

        strcpy(mesVetor, "Dezembro");
        break;

      default:

        strcpy(mesVetor, "Erro");

    }

}

int main(){

  int dia = 12;
  int mes = 8;
  int ano = 2019;
  char diaVetor[12];
  char mesVetor[10];

  formataDia(dia, diaVetor);
  formataMes(mes, diaVetor, mesVetor);

  printf("%s de %s de %d\n", diaVetor, mesVetor, ano);

  return 0;

}
