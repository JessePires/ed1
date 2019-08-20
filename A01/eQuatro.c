#include <stdio.h>
#include <string.h>

void formataDia(int dia, char diaString[]);
void formataMes(int mes, char diaString[], char mesString[]);

void formataDia(int dia, char diaString[]){

  switch(dia){

    case 1:

      strcpy(diaString, "Um");
      break;

    case 2:

      strcpy(diaString, "Dois");
      break;

    case 3:

      strcpy(diaString, "Três");
      break;

    case 4:

      strcpy(diaString, "Quatro");
      break;

    case 5:

      strcpy(diaString, "Cinco");
      break;

    case 6:

      strcpy(diaString, "Seis");
      break;

    case 7:

      strcpy(diaString, "Sete");
      break;

    case 8:

      strcpy(diaString, "Oito");
      break;

    case 9:

      strcpy(diaString, "Nove");
      break;

    case 10:

      strcpy(diaString, "Dez");
      break;

    case 11:

      strcpy(diaString, "Onze");
      break;

    case 12:

      strcpy(diaString, "Doze");
      break;

    case 13:

      strcpy(diaString, "Treze");
      break;

    case 14:

      strcpy(diaString, "Quatorze");
      break;

    case 15:

      strcpy(diaString, "Quinze");
      break;

    case 16:

      strcpy(diaString, "Dezesseis");
      break;

    case 17:

      strcpy(diaString, "Dezessete");
      break;

    case 18:

      strcpy(diaString, "Dezoito");
      break;

    case 19:

      strcpy(diaString, "Dezenove");
      break;

    case 20:

      strcpy(diaString, "Vinte");
      break;

    case 21:

      strcpy(diaString, "Vinte e Um");
      break;

    case 22:

      strcpy(diaString, "Vinte e Dois");
      break;

    case 23:

      strcpy(diaString, "Vinte e Três");
      break;

    case 24:

      strcpy(diaString, "Vinte e Quatro");
      break;

    case 25:

      strcpy(diaString, "Vinte e Cinco");
      break;

    case 26:

      strcpy(diaString, "Vinte e Seis");
      break;

    case 27:

      strcpy(diaString, "Vinte e Sete");
      break;

    case 28:

      strcpy(diaString, "Vinte e Oito");
      break;

    case 29:

      strcpy(diaString, "Vinte e Nove");
      break;

    case 30:

      strcpy(diaString, "Trinta");
      break;

    case 31:

      strcpy(diaString, "Trinta e Um");
      break;

    default:

      strcpy(diaString, "Erro");

  }

}

void formataMes(int mes, char diaString[], char mesString[]){

    switch(mes){

      case 1:

        strcpy(mesString, "Janeiro");
        break;

      case 2:

        strcpy(mesString, "Fevereiro");
        break;

      case 3:

        strcpy(mesString, "Março");
        break;

      case 4:

        strcpy(mesString, "Abril");
        break;

      case 5:

        strcpy(mesString, "Maio");
        break;

      case 6:

        strcpy(mesString, "Junho");
        break;

      case 7:

        strcpy(mesString, "Julho");
        break;

      case 8:

        strcpy(mesString, "Agosto");
        break;

      case 9:

        strcpy(mesString, "Setembro");
        break;

      case 10:

        strcpy(mesString, "Outubro");
        break;

      case 11:

        strcpy(mesString, "Novembro");
        break;

      case 12:

        strcpy(mesString, "Dezembro");
        break;

      default:

        strcpy(mesString, "Erro");

    }

}

int main(){

  int dia = 12;
  int mes = 8;
  int ano = 2019;
  char diaString[12];
  char mesString[10];

  formataDia(dia, diaString);
  formataMes(mes, diaString, mesString);

  printf("%s de %s de %d\n", diaString, mesString, ano);

  return 0;

}
