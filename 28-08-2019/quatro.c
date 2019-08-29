#include <stdio.h>
#include <stdlib.h>

int* intercalaA(int *v1, int tam1, int *v2, int tam2);
void intercalaB(int *v1, int tam1, int *v2, int tam2, int *v3);

int* intercalaA(int *v1, int tam1, int *v2, int tam2){

    int *v = (int*) calloc(tam1+tam2, sizeof(int));
    int indice = 0;


    if(tam1 > tam2){

        for(int i = 0; i < tam1 + tam2; i+=2){

            v[i] = v1[indice];
            v[i+1] = v2[indice];
            indice++;

        }    

    }else{

        for(int i = 0; i < tam1 + tam2; i+=2){

            v[i] = v2[indice];
            v[i+1] = v1[indice];
            indice++;

        }    

    }


    return v;

}

void intercalaB(int *v1, int tam1, int *v2, int tam2, int *v3){

    int indice = 0;

    if(tam1 > tam2){

        for(int i = 0; i < tam1 + tam2; i+=2){

            v3[i] = v1[indice];
            v3[i+1] = v2[indice];
            indice++;

        }    

    }else{

        for(int i = 0; i < tam1 + tam2; i+=2){

            v3[i] = v2[indice];
            v3[i+1] = v1[indice];
            indice++;

        }    

    }

}

int main(){

    int v1[3] = {1,2,3};
    int v2[4] = {5,6,7,8};

    int *v3;
    int v4[7];

    v3 = intercalaA(v2, 4, v1, 3);
    intercalaB(v2, 4, v1, 3, v4);

    printf("Vetor V3: ");
    for(int i = 0; i < 7; i++){

        printf("%d\t", v3[i]);

    }
    printf("\n");

    printf("Vetor v4: ");
    for(int i = 0; i < 7; i++){

        printf("%d\t", v4[i]);

    }
    printf("\n");

    return 0;

}