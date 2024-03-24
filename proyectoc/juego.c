#include <stdio.h>
#include <string.h>

struct Juego {
    int codigo;
    char *nombre;
    char *categoria;
    int valor;
};

int buscarJuego(struct Juego **array, int size, int search) {
    int i;
    for (i=0;i<size;i++) {
        if(array[i] != NULL && array[i]->codigo == search) {
            return 1;
        }
    }
    return 0;
}

struct Juego *crearJuegoNuevo(int codigo, char *nombre, char *categoria, int valor) {
    struct Juego *juegoNuevo = (struct Juego *) malloc(sizeof(struct Juego));

    juegoNuevo->codigo = codigo;
    juegoNuevo->nombre = nombre;
    juegoNuevo->categoria = categoria;
    juegoNuevo->valor = valor;

    return juegoNuevo;
}

int agregarJuegoNuevo(struct Juego **array, int size, int codigo, char *nombre, char *categoria, int valor) {
    int i;

    /* Verificar si es que codigo no esta repetido*/ 
    struct Juego *nuevoJuego = NULL;
    if (buscarJuego(array, size, codigo) == 0) {
        /* Crear y agregar nuevo juego*/
        nuevoJuego = crearJuegoNuevo(codigo, nombre, categoria, valor);

        for (i = 0;i<size;i++) {
            if (array[i] == NULL) {
                array[i] = nuevoJuego;
                return 1;
            }
        }

    }
    return 0;
}

// Con array compacta 

int buscarJuegoCom(struct Juego **array, int pLibre, int search) {
    int i;

    for (i = 0;i<pLibre;i++) {
        if(array[i]->codigo == search) {
            return 1;
        }
    }
    return 0;
}

int agregarJuegoCom(struct Juegos **array, int *pLibre, int tam, int codigo, char *nombre, char *categoria, int valor) {
    struct Juegos **nuevoJuego = NULL;
    int i;

    if (buscarJuego(array, *pLibre, codigo) == 0 && pLibre < tam) {
        /* Crear nuevo juego*/
        nuevoJuego = crearJuegoNuevo(codigo, nombre, categoria, valor);

        /* agregar juego Compacto*/
        array[*pLibre] = nuevoJuego;
        (*pLibre)++;
        return 1;

    }

}

int main() {
    struct Juego **juegos;

    int plibre = 0;


}