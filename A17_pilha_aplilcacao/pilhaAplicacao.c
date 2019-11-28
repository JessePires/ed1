#include <stdio.h>
#include <string.h>

char verificaExpressao(char A[]){

    char pilha[strlen(A)];
    int cont = 0;

    if(strlen(A) == 1){

        return 'N';

    }else if(A[strlen(A)] == '(' || A[strlen(A)] == '[' || A[strlen(A)] == '{'){

        return 'N';

    }
    
    for(int i = 0; i < strlen(A); i++){

        if(A[i] == '(' || A[i] == '[' || A[i] == '{'){

            strcpy(&pilha[cont], &A[i]);
            cont++;

        }

        if(A[i] == ')' && pilha[cont -1] == '('){

            cont--;

        }else if(A[i] == ']' && pilha[cont -1] == '['){

            cont--;

        }else if(A[i] == '}' && pilha[cont -1] == '{'){

            cont--;

        }else if(cont == 0){

            return 'N';

        }

    }   

    return (cont == 0) ? 'S' : 'N';

}

int main(){

    int T;
    char A[100001];
    clock_t inicio, fim;

    scanf("%d", &T);

    inicio = clock();
    for(int i = 0; i < T; i++){

        scanf("%s", A);
        char resultado = verificaExpressao(A);
        printf("%c\n", resultado);

    }

    return 0;

}