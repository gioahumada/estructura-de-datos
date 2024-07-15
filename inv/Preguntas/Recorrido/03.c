#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pLibre = 0;
    int *array;

    array = (int *)malloc(sizeof(int) * 20);

    rellenarArray(array, &pLibre);
}

void rellenarArray(int *array, int *pLibre) {
    int i;
    for(i = 0; i < 20; i++) {
        array[*pLibre] = i;
        *pLibre += 1;
    }
}
