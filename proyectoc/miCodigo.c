#include <stdio.h>
#include <stdlib.h>

struct Juego {
    int codigo;
    char *nombre;
    char *categoria;
    int valor;
};

unsigned short preguntarOpcion() {
    unsigned short dato;
    scanf("%hd", &dato);
    return dato;
}

int juegoExiste(struct Juego **array, int size) {
    int i;

    for (int i = 0; i<size;i++) {

    }
}





void menuJuegos() {
    unsigned short dato = 0;

    do {
    printf("\n");
    printf("***** ***** ***** *****\n");
    printf("¿Que desea hacer?\n");
    printf("1. Buscar Juegos\n");
    printf("2. Agregar juegos\n");
    printf("3. Salir del programa\n");

    dato = preguntarOpcion();
    if (dato == 1) {
       agregarJuegos();
    } else if (dato == 2) {
        buscarJuegos();
    } else if (dato == 3) {
        exit(1);
    }

    } while (dato < 0 && dato > 3);
}

// MAIN MAIN MAIN MAIN MAIN

int main() {

    struct Juego **juegos;
    int tam = 0, tamCaros = 0, promValores = 0;

    do {
        printf("Ingrese la cantidad de juegos máxima a registrar: ");
        scanf("%d", &tam);
    } while (tam <= 0);

    
    menuJuegos();

    return 0;

}