#include <stdio.h>

int main(void){
    int x, *p;

    x = 100;
    p = &x; //antes da mod: p = x;
    printf("Valor de p: %p\nValor do conteúdo de p: %d\n", p, *p);

    /*a) advertência
    * b) na linha 7 estamos tentando atribuir um valor inteiro a um ponteiro, ao invés de um endereço
    * c) não
    * d) 
    * e) sim
    */

   return 0;
}