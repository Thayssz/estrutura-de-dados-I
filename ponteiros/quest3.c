#include <stdio.h>

int main(void){
    int a, b, c, d; //declaração de variáveis inteiras
    int *p1; //declaração de ponteiro 1
    int *p2 = &a; //declaração e atribuição do endereço de a ao ponteiro 2
    int *p3 = &c; //declaração e atribuição do endereço de c ao ponteiro 3
    p1 = p2; //ponteiro 1 recebe o mesmo endereço que ponteiro 2 armazena
    *p2 = 10; //conteúdo do ponteiro 2 recebe o valor 10
    b = 20; //b recebe 20
    int **pp; //declaração de ponteiro de ponteiro
    pp = &p1; //ponteiro de ponteiro recebe o endereço do ponteiro 1
    *p3 = **pp; //o conteúdo do ponteiro 3 recebe o conteúdo do conteúdo que o ponteiro de ponteiro guarda
    int *p4 = &d; //declaração e atribuição do endereço de d ao ponteiro 4
    *p4 = b + (*p1)++; //o conteúdo do ponteiro 4 recebe o valor de b mais o conteúdo do ponteiro 1 e depois o conteúdo do ponteiro 1 é incrementado uma vez

    printf("Valor de a: %d\nValor de b: %d\nValor de c: %d\nValor de d: %d\n", a, b, c, d);

    return 0;

    //ao final da execução, a terá o valor 11, b terá o valor 20, c terá o valor 10 e d terá o valor 30
}