#include <stdio.h>
#include <stdlib.h>

struct RGB {
    int r;
    int g;
    int b;
};

struct RGB *crearNuevoColor(int r, int g, int b) {
    /* Nuevo array */
    struct RGB *colNuevo;

    /* Creamos memoria para el nuevo array */
    colNuevo = (struct RGB *) malloc(sizeof(struct RGB));
    
    colNuevo->r = r;
    colNuevo->g = g;
    colNuevo->b = b;

    /* Retorna un array de tipo struct listo para usarse :p*/
    return colNuevo;
}

int agregarColorNuevo(struct RGB **array, int tam, int r, int g, int b) {
    int i;

    for (i = 0; i<tam; i++) {
        /* Si el array esta vacio, agrega el nuevo color 🥳*/
        if(array[i] == NULL)
            array[i] = crearNuevoColor(r, g ,b);
            return 1;
    }

    return 0;
}

int comprobarColores(struct RGB **array, int tam) {
    int i; 
    
}



int main() {
    struct RGB **pixeles;

    int tam; 
    do {
        printf("¿Cuantos pixeles vas a analizar?\n");
        scanf("%d", &tam);

    } while(tam <= 0);

    pixeles = (struct RGB **) malloc(sizeof(struct RGB*) * tam);



}