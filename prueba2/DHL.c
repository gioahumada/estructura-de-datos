#include <stdio.h>
#include <stdlib.h>

struct Paquete {
    int id;
    int peso;
    int precio;
    char *direccion;
};

struct Dhl {
    struct Paquete *package;
    struct Dhl *sig;
    struct Dhl *ant;
};

struct Paquete *crearPaquete(int id, int peso, int precio, char *direccion) {
    struct Paquete *nuevoPaquete;
    nuevoPaquete = (struct Paquete*) malloc(sizeof(struct Paquete));

    nuevoPaquete->id = id;
    nuevoPaquete->peso = peso;
    nuevoPaquete->precio = precio;
    nuevoPaquete->direccion = direccion;

    return nuevoPaquete;
}

struct Dhl *crearNodo(struct Paquete *paquete) {
    struct Dhl *nuevoNodo;
    nuevoNodo = (struct Dhl*) malloc(sizeof(struct Dhl));

    nuevoNodo -> package = paquete;

    nuevoNodo -> sig = NULL;
    nuevoNodo -> ant = NULL;

    return nuevoNodo;
}

int agregarNodoALista(struct Dhl **lista, struct Paquete *paquete) {
    struct Dhl *nuevoNodo = crearNodo(paquete);

    if(*lista == NULL) {
        *lista = nuevoNodo;
        return 1;
    }

    struct Dhl *rec = *lista;

    while(rec->sig != NULL) {
        rec = rec->sig;
    }

    rec->sig = nuevoNodo;
    nuevoNodo->ant = rec;
    return 1;
}

int agregarAListaInicio(struct Dhl **lista, struct Paquete *paquete) {
    struct Dhl *nuevoNodo = crearNodo(paquete);

    if(*lista = NULL) {
        *lista = nuevoNodo;
        return 1;
    }

    (*lista)->ant = nuevoNodo;
    nuevoNodo->sig = *lista;

    lista = &nuevoNodo;
}



int main() {

}