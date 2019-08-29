#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copiaString(char *str);

char* copiaString(char *str){

    char *copia = (char*) calloc(strlen(str) + 1, sizeof(char));

    strcpy(copia, str);

    return copia;

}

int main(){

    char str[20] = "ABC";

    char *copia = copiaString(str);
    printf("Cópia da string: %s\n", copia);

    return 0;

}