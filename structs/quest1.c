#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char nome[50];
    double salario;
    int identificador;
    char cargo[50];
}Funcionario;

void preencher_funcionario(Funcionario* funcionario){
    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]", funcionario->nome);

    printf("Digite o salário do funcionário: ");
    scanf("%lf", &funcionario->salario);

    printf("Digite o id do funcionario: ");
    scanf("%d", &funcionario->identificador);

    printf("Digite o cargo do funcionário: ");
    scanf(" %[^\n]", funcionario->cargo);
}

void imprimir_funcionario(Funcionario* funcionario){
    printf("Dados do funcionário:\n");
    printf("Nome: %s\n", funcionario->nome);
    printf("Salário: %.2lf\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("\n");
}

void alterar_salario(Funcionario* funcionario, double novo_salario){
    funcionario->salario = novo_salario;
}

void maior_menor_salario(Funcionario** funcionarios){
    double maior = (*funcionarios)[0].salario;
    double menor = (*funcionarios)[0].salario;    
    char cargo_maior[50];
    char cargo_menor[50];
    for(int i = 0; i < 5; i++){
        if((*funcionarios)[i].salario > maior){
            strcpy(cargo_maior, (*funcionarios)[i].cargo);
            maior = (*funcionarios)[i].salario;
        }

        if((*funcionarios)[i].salario < menor){
            strcpy(cargo_menor, (*funcionarios)[i].cargo);
            menor = (*funcionarios)[i].salario;
        } 
    }

    printf("Cargo do maior salário: %s\n", cargo_maior);
    printf("Salário: %.2lf\n", maior);

    printf("Cargo do menor salário: %s\n", cargo_menor);
    printf("Salário: %.2lf\n", menor);
}

int main(void){
    int i;
    double novo_salario;

    Funcionario* vetor_funcionarios = (Funcionario*) malloc(5 * sizeof(Funcionario));
    if(vetor_funcionarios == NULL){
        printf("Erro ao alocar memória para vetor de funcionários.\n");
        exit(EXIT_FAILURE);
    }

    
    printf("Preencha os dados dos funcionários:\n");
    for(i = 0; i < 5; i++){
        printf("Funcionário %d:\n", i + 1);
        preencher_funcionario(&vetor_funcionarios[i]);
    }



    printf("Teste da função de alterar salário:\n");
    printf("Digite um novo salário para alteração do funcionário 1.\n");
    scanf("%lf", &novo_salario);
    alterar_salario(&vetor_funcionarios[0], novo_salario);

    imprimir_funcionario(&vetor_funcionarios[0]);

    maior_menor_salario(&vetor_funcionarios);

    free(vetor_funcionarios);

    return 0;
}