#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number_peoples;
    int contador_b = 0;
    int contador_c = 0;

    printf("Digite a quantidade de pessoas a serem entrevistadas: ");
    scanf("%d", &number_peoples);

    char* vetor_sexo = (char*) malloc(number_peoples * sizeof(char));
    if(vetor_sexo == NULL){
        printf("Erro ao alocar memória para vetor.\n");
        exit(EXIT_FAILURE);
    }

    int* vetor_opiniao = (int*) malloc(number_peoples * sizeof(int));
    if(vetor_opiniao == NULL){
        printf("Erro ao alocar memória para vetor.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < number_peoples; i++){
        printf("Digite o sexo da pessoa entrevistada:\nF - Feminino\nM - Masculino\n- ");
        scanf(" %c", &vetor_sexo[i]);

        printf("Digite a opinião da pessoa entrevistada:\n1 - Gostou\n2 - Não gostou\n- ");
        scanf("%d", &vetor_opiniao[i]);

        if(vetor_sexo[i] == 'F' && vetor_opiniao[i] == 1){
            contador_b++;
        }

        if(vetor_sexo[i] == 'M' && vetor_opiniao[i] == 2){
            contador_c++;
        }
    }

    double porcentagem_b = ((double)contador_b/number_peoples) * 100;
    double porcentagem_c = ((double)contador_c/number_peoples) * 100;

    printf("Mulheres que gostaram: %.2lf\nHomens que não gostaram: %.2lf\n", porcentagem_b, porcentagem_c);

    return 0;
}