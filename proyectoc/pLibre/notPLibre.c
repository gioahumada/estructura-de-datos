#include <stdio.h>

struct TV {
    int canal;
    char *nombre;
    int rating;
};

int buscarCanal(struct TV **array, int tam, int buscar) {
    int i;

    for(i = 0;i<tam;i++) {
        
    }
}

int main() {
    int tam;
    struct TV **canales;

    do {
        printf("Cual es el tamaño de tu array?");
        scanf("%d",&tam);
    } while(tam < 0);
}