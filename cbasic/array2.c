#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int talla = 8;

    int *array = malloc(talla * sizeof(int)); // int = 4 bytes -- 4 * 8 = 32 bytes reservados
    for (i = 0; i<talla;i++) {
        array[i] = i+1;
    }

    for (i = 0;i<talla;i++) {
        printf("Valor del array [%i]: %d\n",i,array[i]);
    }

    free(array);
    return 0;

}