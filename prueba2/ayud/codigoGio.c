#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Agregar listas circulares doblemente -;
// Doblemente enlazadas-;

struct Jugador {
    int id;
    char *nombre;
    int media;
    char *calidad;
};

struct NodoJugadores {
    struct Jugador *jugadores;
    struct NodoJugadores *sig;
    struct NodoJugadores *ant;
};

struct Jugador *crearJugador(int id, char *nombre, int media, char *calidad) {
    struct Jugador *nuevoJugador;
    nuevoJugador = (struct Jugador*)malloc(sizeof(struct Jugador));

    nuevoJugador->id = id;
    nuevoJugador->nombre = nombre;
    nuevoJugador->media = media;
    nuevoJugador->calidad = calidad;

    return nuevoJugador;
}

struct NodoJugadores *crearNodoJugadores(struct Jugador *jugador) {
    struct NodoJugadores *nuevoNodo;
    nuevoNodo = (struct NodoJugadores *) malloc(sizeof(struct NodoJugadores));

    nuevoNodo->jugadores = jugador;

    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    return nuevoNodo;
}

int agregarNodoALista(struct NodoJugadores **lista, struct Jugador *jugador) {
    struct NodoJugadores *nuevoNodo = crearNodoJugadores(jugador);

    if(*lista == NULL) {
        *lista = nuevoNodo;
        return 1;
    }

    struct NodoJugadores *rec = *lista;

    while(rec->sig != NULL) {
        rec = rec->sig;
    }

    rec->sig = nuevoNodo;
    nuevoNodo->ant = rec;
    return 1;
}

int agregarAListaInicio(struct NodoJugadores **lista, struct Jugador *jugador) {
    struct NodoJugadores *nuevoNodo = crearNodoJugadores(jugador);

    if (*lista == NULL) {
        *lista = nuevoNodo;
        return 1;
    }

    (*lista)->ant = nuevoNodo;
    nuevoNodo->sig = *lista;

    lista = &nuevoNodo;
}

struct NodoJugadores *buscarID(struct NodoJugadores *lista, int buscar) {
    struct NodoJugadores *rec;

    if (lista != NULL) {
        rec = lista;

        while(rec != NULL) { 
            if(rec->jugadores->id == buscar) {
                return rec;
            }

            rec = rec->sig;
        }

    }
    return NULL;
}

void recorrerListaInversa(struct NodoJugadores *lista) {
    struct NodoJugadores *rec = lista;

    // Primero, vamos al final de la lista
    while (rec->sig != NULL) {
        rec = rec->sig;
    }

    // Ahora, recorremos la lista en orden inverso
    while (rec != NULL) {
        printf("ID: %d, Nombre: %s, Media: %d, Calidad: %s\n", rec->jugadores->id, rec->jugadores->nombre, rec->jugadores->media, rec->jugadores->calidad);
        rec = rec->ant;
    }
}

void ordenarListaAlfabeticamente(struct NodoJugadores **lista) {
    int intercambio;
    struct NodoJugadores *ptr;
    struct Jugador *temp;

    if (*lista == NULL)
        return;

    do {
        intercambio = 0;
        ptr = *lista;

        while (ptr->sig != NULL) {
            if (strcmp(ptr->jugadores->nombre, ptr->sig->jugadores->nombre) > 0) {
                temp = ptr->jugadores;
                ptr->jugadores = ptr->sig->jugadores;
                ptr->sig->jugadores = temp;
                intercambio = 1;
            }
            ptr = ptr->sig;
        }
    }
    while (intercambio);
}

int agregarNodoOrdenado(struct NodoJugadores **lista, struct Jugador *jugador) {
    struct NodoJugadores *nuevoNodo = crearNodoJugadores(jugador);

    if (*lista == NULL) {
        *lista = nuevoNodo;
        return 1;
    }

    struct NodoJugadores *rec = *lista;

    // Buscar la posición correcta en la lista
    while (rec->sig != NULL && strcmp(rec->jugadores->nombre, jugador->nombre) < 0) {
        rec = rec->sig;
    }

    // Insertar el nuevo nodo en la posición correcta
    if (rec->ant == NULL) {
        (*lista)->ant = nuevoNodo;
        nuevoNodo->sig = *lista;
        *lista = nuevoNodo;
    } else if (rec->sig == NULL && strcmp(rec->jugadores->nombre, jugador->nombre) < 0) {
        rec->sig = nuevoNodo;
        nuevoNodo->ant = rec;
    } else {
        nuevoNodo->sig = rec;
        nuevoNodo->ant = rec->ant;
        rec->ant->sig = nuevoNodo;
        rec->ant = nuevoNodo;
    }

    return 1;
}

int main() {
    struct NodoJugadores *lista = NULL;
m
    // Crear algunos jugadores
    struct Jugador *jugador1 = crearJugador(1, "Carlos", 85, "Excelente");
    struct Jugador *jugador2 = crearJugador(2, "Ana", 90, "Excelente");
    struct Jugador *jugador3 = crearJugador(3, "Pedro", 80, "Bueno");
    struct Jugador *jugador4 = crearJugador(4, "Maria", 95, "Excelente");

    // Agregar los jugadores a la lista
    agregarNodoOrdenado(&lista, jugador1);
    agregarNodoOrdenado(&lista, jugador2);
    agregarNodoOrdenado(&lista, jugador3);
    agregarNodoOrdenado(&lista, jugador4);

    // Ordenar la lista alfabéticamente por nombre
    ordenarListaAlfabeticamente(&lista);

    // Recorrer la lista en orden inverso
    recorrerListaInversa(lista);

    return 0;
}
