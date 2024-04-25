#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = ((3 * (pow(l, 2)) * sqrt(3)) / 2);
    *perimetro = (6 * l);
}

int main(void){
    float l, area, perimetro;

    printf("Digite o comprimento do lado: ");
    scanf("%f", &l);

    calcula_hexagono(l, &area, &perimetro);

    printf("Área do hexágono de lado %.2f: %.3f\nPerímetro do hexágono de lado %.2f: %.2f\n", l, area, l, perimetro);

    return 0;
}