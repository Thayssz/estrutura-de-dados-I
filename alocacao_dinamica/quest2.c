#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, i, j;

    printf("Digite o número de questões da prova: ");
    scanf("%d", &N);

    char* gabarito = (char*) malloc(N * sizeof(char));
    if(gabarito == NULL){
        printf("Erro ao alocar memória para o gabarito.\n");
        exit(EXIT_FAILURE);
    }

    printf("Informe o gabarito da prova:\n");
    for(i = 0; i < N; i++){
        printf("Gabarito questão %d: ", i + 1);
        scanf(" %c", &gabarito[i]);
    }

    char** respostas = (char**) malloc(10 * sizeof(char*));
    if(respostas == NULL){
        printf("Erro ao alocar memória para as respostas dos alunos.\n");
        free(gabarito);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 10; i++){
        respostas[i] = (char*) malloc(N * sizeof(char));
        if(respostas[i] == NULL){
            printf("Erro ao alocar memória para as respostas do aluno.\n");
            for(j = 0; j < i; j++){
                free(respostas[j]);
            }
            free(respostas);
            free(gabarito);
            exit(EXIT_FAILURE);
        }
    }

    for(i = 0; i < 10; i++){
        printf("Digite as respostas do aluno %d:\n", i + 1);
        for(j = 0; j < N; j++){
            printf("Digite a respostas da questão %d: ", j + 1);
            scanf(" %c", &respostas[i][j]);
        }
    }

    float* notas = (float*) malloc(10 * sizeof(float));
    if(notas == NULL){
        printf("Erro ao alocar memória para notas dos alunos.\n");
        for(i = 0; i < 10; i++){
            free(respostas[i]);
        }
        free(respostas);
        free(gabarito);
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 10; i++){
        notas[i] = 0.0;
        for(j = 0; j < N; j++){
            if(respostas[i][j] == gabarito[j]){
                notas[i] += (float)10/N;
            }
        }
    }

    printf("Notas dos alunos:\n");
    for(i = 0; i < 10; i++){
        printf("Aluno %d: %.2lf\n", i + 1, notas[i]);
    }

    for(i = 0; i < 10; i++){
        free(respostas[i]);
    }
    free(respostas);
    free(gabarito);
    free(notas);

    return 0;
}