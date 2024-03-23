#include <stdio.h>
#include <stdlib.h>

/*
ENTRADA DE DATOS
*/ 

struct Juego {
    int codigo;
    char *nombre;
    char *categoria;
    int valor;
};

int buscarJuego(struct Juego **array, int tam, int buscar) {
    int i;
    for (i = 0; i<tam;i++) {
        if (array[i] != NULL && array[i]->codigo==buscar)
            return 1;
    }
    return 0;
}

struct Juego *crearJuegoNuevo(int codigo, char *nombre, char *categoria, int valor) {
    struct Juego *juegoNuevo;

    juegoNuevo = (struct Juego *) malloc(sizeof(struct Juego));

    juegoNuevo->codigo = codigo;
    juegoNuevo->nombre = nombre;
    juegoNuevo->categoria = categoria;
    juegoNuevo->valor = valor;

    return juegoNuevo;
}

int agregarJuegoNuevo(struct Juego **array, int tam, int codigo, char *nombre, char *categoria, int valor) {
    struct Juego *nuevoJuego = NULL;
    int i;

    /* Buscar que no este repetido*/

    if(buscarJuego(array, tam, codigo) == 0) {
        for (i = 0;i<tam;i++) {
            if (array[i] == NULL) {
                array[i] = crearJuegoNuevo(codigo, nombre, categoria, valor);
                return 1;
            }
        }
    }
    return 0;
}



int main() {
    struct Juego **juegos;

    int tam;
    do {
        printf("Ingrese el n° maximo de juegos a registrar\n");
        scanf("%d",&tam);
    } while (tam <= 0);

    // Asignacion de memoria
    juegos = (struct Juego **) malloc(sizeof(struct Juego *) * tam);
}