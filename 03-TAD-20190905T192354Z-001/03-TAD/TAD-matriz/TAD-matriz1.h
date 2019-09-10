#include <stdio.h>
#include <stdlib.h>

// DADOS
typedef struct{
    int **matriz;
    int linhas;
    int colunas;

} Matriz;

typedef struct{

    int *vetor;
    int qtdElementos;

} Vetor;

//OPERAÇÕES (PROTÓTIPOS)

Matriz *matriz_cria(int linhas, int colunas);
int matriz_atribui(Matriz *m, int lin, int col, int valor);
int matriz_acessa1(Matriz *m, int lin, int col);
int matriz_acessa2(Matriz *m, int lin, int col, int *end);
int matriz_imprime(Matriz *m);
int matriz_linhas(Matriz *m);
int matriz_colunas(Matriz *m);
int matriz_map1(Matriz *m, int(*funcao)(int));
int matriz_destroi(Matriz *m);
Vetor *matriz_obtemLinha(Matriz *m, int linha);
Vetor *matriz_obtemColuna(Matriz *m, int coluna);
Matriz *matriz_multiplica(Matriz *a, Matriz *b);
int matriz_ehQuadrada(Matriz *m);
int matriz_ehDiagonal(Matriz *m);
int matriz_ehIdentidade(Matriz *m);
Matriz *matriz_transposta(Matriz *m);
Matriz *matriz_oposta(Matriz *m);

//OPERAÇÕES (IMPLEMENTAÇÃO)

Matriz *matriz_cria(int linhas, int colunas){

    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    mat->matriz = (int **)calloc(linhas, sizeof(int *));
    int i;
    
    for (i = 0; i < linhas; i++){

        mat->matriz[i] = (int *)calloc(colunas, sizeof(int));
    
    }
    
    mat->linhas = linhas;
    (*mat).colunas = colunas;

    return mat;
}

int matriz_atribui(Matriz *m, int lin, int col, int valor){
    
    if(lin < m->linhas && col < m->linhas){

        m->matriz[lin][col] = valor;
        return 1;

    }

    return NULL; 

}

int matriz_acessa1(Matriz *m, int lin, int col){

    if(m != NULL){

        if(lin < m->linhas && col < m->colunas){

            return m->matriz[lin][col];

        }

        return NULL;

    }

    return NULL;

}

int matriz_acessa2(Matriz *m, int lin, int col, int *end){

    if(m != NULL){

        if(lin < m->linhas && col < m->colunas){

            end = &m->matriz[lin][col];
            return 1;

        }

        return 0;

    }

    return 0;

}

int matriz_imprime(Matriz *m){

    if(m != NULL){

        for(int i = 0; i < m->linhas; i++){

            printf("[");

            for(int j = 0; j < m->colunas; i++){

                printf("%d\t|", m->matriz[i][j]);
            
                if(j == m->colunas - 1){

                    printf("%d]\n", m->matriz[i][j]);

                }

            }
        }

        return 1;

    }

    return NULL;

}

int matriz_linhas(Matriz *m){

    if(m != NULL){

        return m->linhas;

    }

    return NULL;

}

int matriz_colunas(Matriz *m){

    if(m != NULL){

        return m->colunas;

    }

    return NULL;

}

int matriz_map1(Matriz *m, int(*funcao)(int)){

    if(m != NULL){

        for(int i = 0; i < m->linhas; i++){

            for(int j = 0; j < m->colunas; j++){

                m->matriz[i][j] = funcao(m->matriz[i][j]);
                return 1;
            }

        }

        return NULL;

    }

    return NULL;

}

int matriz_destroi(Matriz *m){

    if(m != NULL){

        for(int i = 0; i < m->linhas; i++){

            free(m->matriz[i]);

        }

        free(m->matriz);
        free(m);

        return 1;

    }

    return NULL;

}

Vetor *matriz_obtemLinha(Matriz *m, int linha){

    if(m != NULL){

        Vetor *vet = (Vetor *) malloc(sizeof(Vetor));
        vet->vetor = (int *) calloc(m->colunas, sizeof(int));
        vet->qtdElementos = m->colunas;

        for(int j = 0; j < m->colunas; j++){

            vet->vetor[j] = m->matriz[linha][j];

        }

        return vet;

    }

    return NULL;
    
}

Vetor *matriz_obtemColuna(Matriz *m, int coluna){

    if(m != NULL){

        Vetor *vet = (Vetor *) malloc(sizeof(Vetor));
        vet->vetor = (int *) calloc(m->linhas, sizeof(int));
        vet->qtdElementos = m->linhas;

        for(int i = 0; i < m->linhas; i++){

            vet->vetor[i] = m->matriz[i][coluna];

        }

        return vet;

    }

    return NULL;

}

Matriz *matriz_multiplica(Matriz *a, Matriz *b){

    int produto;

    if(a != NULL && b != NULL){

        if(a->linhas == b->colunas){

            Matriz *multiplicada = matriz_cria(a->linhas, b->colunas);

            for(int i = 0; i < multiplicada->linhas; i++){

                for(int j = 0; j < multiplicada->colunas; j++){

                    for(int x = 0; x < b->linhas; x++){

                        produto += a->matriz[i][x] * b->matriz[x][j];

                    }

                    multiplicada->matriz[i][j] = produto;
                    produto = 0;

                }

            }
            
            return multiplicada;

        }

        return NULL;

    }

    return NULL;

}

int matriz_ehQuadrada(Matriz *m){

    if(m != NULL){

        if(m->linhas == m->colunas){

            return 1;

        }

        return 0;

    }

    return -1;

}

int matriz_ehDiagonal(Matriz *m){

    if(m != NULL){

        for(int i = 0; i < m->linhas; i++){

            for(int j = 0; j < m->colunas; j++){

                if(i != j){

                    if(m->matriz[i][j] != 0){

                        return 0;

                    }

                }

            }

        }

        return 1;

    }

    return -1;

}

int matriz_ehIdentidade(Matriz *m){

    if(m != NULL){

        if(matriz_ehDiagonal(m)){

            for(int i = 0; i < m->linhas; i++){

                for(int j = 0; j < m->colunas; j++){

                    if(i == j){

                        if(m->matriz[i][j] != 1){

                            return 0;

                        }

                    }

                }

            }

            return 1;

        }

    }

    return -1;

}

Matriz *matriz_transposta(Matriz *m){

    if(m != NULL){

        Matriz *transposta = matriz_cria(m->colunas, m->linhas);
        
        for(int i = 0; i < m->linhas; i++){

            for(int j = 0; j < m->colunas; j++){

                transposta->matriz[j][i] = m->matriz[i][j];

            }

        }

        return transposta;

    }

    return NULL;

}

Matriz *matriz_oposta(Matriz *m){

    if(m != NULL){

        Matriz *oposta = matriz_cria(m->linhas, m->colunas);

        for(int i = 0; i < m->linhas; i++){

            for(int j = 0; j < m->colunas; j++){

                oposta->matriz[i][j] = m->matriz[i][j] * -1;

            }

        }

        return oposta;

    }

    return NULL;

}