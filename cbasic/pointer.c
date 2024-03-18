#include <stdio.h>

int main() {
    int a = 5;
    int *b = &a;
    int *c = b;

    printf("El valor de 'a' es: %d \n", a);
    printf("El Valor de memoria de 'a' es: %p \n",b);
    printf("El valor del puntero de 'a' es: %d \n\n", *b);

    printf("El valor del puntero de 'c' es: %p \n", c);

    return 0;
}