#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamArreglos 5000

// Definición de estructuras
struct Artista {
    int id;
    char *nombre;
    char *genero;
    char *selloDiscografico;
};

struct Evento {
    int id;
    char *fecha;
    struct Artista *artista;
};

struct Recinto {
    int id;
    char *nombre;
    int capacidad;
    struct Evento **eventos;
    int pLibreEventos;
};

struct NodoRecinto {
    struct Recinto *datosRecinto;
    struct NodoRecinto *ant, *sig;
};

struct Pais {
    char *nombre;
    struct NodoRecinto *recintos;
};

struct NodoPais {
    struct Pais *pais;
    struct NodoPais *sig;
};

struct NodoArtista {
    struct Artista *datosArtista;
    struct NodoArtista *izq, *der;
};

struct ListaArtistas {
    int cantArtistas;
    struct NodoArtista *abbArtistas;
};

struct SistemaEventos {
    struct ListaArtistas *artistas;
    struct NodoPais *paises;
};

int agregarArtista(struct SistemaEventos *sistema, struct Artista *nuevoArtista) {
    struct NodoArtista *nuevoNodo = (struct NodoArtista *)malloc(sizeof(struct NodoArtista));
    if (nuevoNodo == NULL) {
        return 0;
    }
    nuevoNodo->datosArtista = nuevoArtista;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    if (sistema->artistas->abbArtistas == NULL) {
        sistema->artistas->abbArtistas = nuevoNodo;
        sistema->artistas->cantArtistas++;
        return 1;
    }

    struct NodoArtista *aux = sistema->artistas->abbArtistas;
    while (1) {
        if (strcmp(nuevoArtista->nombre, aux->datosArtista->nombre) < 0) {
            if (aux->izq == NULL) {
                aux->izq = nuevoNodo;
                sistema->artistas->cantArtistas++;
                return 1;
            }
            aux = aux->izq;
        } else {
            if (aux->der == NULL) {
                aux->der = nuevoNodo;
                sistema->artistas->cantArtistas++;
                return 1;
            }
            aux = aux->der;
        }
    }
}

int  agendarEvento(struct  SistemaEventos  *SE,  int  idEvento,  id  recinto,  char  *fechaEvento,  int  idArtista) {
    
}
