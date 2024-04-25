#include <stdio.h>

int main(void){
    int x, y, *p; //declaração de variáveis inteiras x e y, e um ponteiro p

    y = 0; //y recebe o valor 0
    p = &y; //p recebe o endereço de y
    x = *p; //x recebe o conteúdo de p
    x = 4; //x recebe 4
    (*p)++; //o conteúdo de p é incrementado uma vez
    --x; //o conteúdo de x é decrementado
    (*p) += x; //o conteúdo de p é incremento com o valor de x

    printf("Valor de x: %d\nValor de y: %d\nValor de p: %p\nEndereço de y: %p", x, y, p, &y);

    //ao final do programa, x terá o valor 3, y terá o valor 4 e p terá o endereço de y

    return 0;
}