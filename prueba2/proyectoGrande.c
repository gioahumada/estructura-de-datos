#include <stdio.h>
#include <stdlib.h>

/* Struct */
struct Fifa {
    int year;
    struct NodoEquipos *equipo;
};

struct Equipos {
    char *nombre;
    char *entrenador;
    struct NodoJugadores *jugadores;
};

struct Jugadores {
    char *nombre;
    int media;
    char *pais;
};

struct NodoEquipos {
    struct Equipos *datos;
    struct NodoEquipos *ant, *sig;
};


struct NodoJugadores {
    struct Jugadores *datos;
    struct NodoJugadores *ant, *sig;
};

struct Jugadores *crearJugador(char *nombre, int media, char *pais) {
    struct Jugadores *nuevoItem;
    nuevoItem = (struct Jugadores *) malloc(sizeof(struct Jugadores));

    nuevoItem->nombre = nombre;
    nuevoItem->media = media;
    nuevoItem->pais = pais;

    return nuevoItem;
}

struct NodoJugadores *crearNodoJugador(struct Jugadores *item) {
    struct NodoJugadores *nuevoNodo;
    nuevoNodo = (struct NodoJugadores *) malloc(sizeof(struct NodoJugadores));

    nuevoNodo->datos = item;

    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    return nuevoNodo;
}

int agregarNodoJugador(struct NodoJugadores **head, struct NodoJugadores *nodo) {
    if (*head == NULL) {
        nodo->sig = nodo->ant = nodo;
        *head = nodo;
        
        return 1;
    }

    /* - - - */

    struct NodoJugadores *rec = *head; // Rec busca al ultimo.

    while(rec->sig != NULL) {
        rec = rec->sig;
    }

    rec->sig = nodo;
    nodo->ant = rec;
    return 1;
}



int main() {

}