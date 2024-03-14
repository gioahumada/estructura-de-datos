/*
Ejemplo vector dinamico
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;
    int talla = 0;


    printf("Ingrese numeros, 0 para terminar\n");

    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;

        talla++;

        array = realloc(array, talla * sizeof(int));
        if (array == NULL) return EXIT_SUCCESS;

        array[talla - 1] = n;
    }

    printf("Los numeros que ingresaste fueron; \n");

    for (int i = 0;i<talla;i++) {
        printf("%d\n", array[i]);
    }
}

