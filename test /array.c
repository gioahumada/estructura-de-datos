/* 
Probando malloc
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;
    int size = 0;

    printf("Cuantos items en el vector necesitas?\n");
    scanf("%d",&size);

    array = (int*) malloc(size * sizeof(int));
    if(array == NULL) return 1;

    for (int i = 0; i<size;i++) {
        printf("¿Que deseas agregar en la posicion [%d]",i+1);
        scanf("%d",&array[i]);
    }

    for (int i = 0;i<size;i++) {
        printf("[%d] se guardo: %d\n",i+1,array[i]);
    }

    free(array);
    return 0;
}