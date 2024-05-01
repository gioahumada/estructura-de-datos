#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

int agregarAlFinal(struct Nodo **head, int datoNuevo) {
    struct Nodo *nuevoNodo;
    nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));

    nuevoNodo->dato = datoNuevo;
    nuevoNodo->sig = NULL;

    if (*head == NULL) {
        *head = nuevoNodo;
        return 1;
    }

    struct Nodo *ult = *head;

    while(ult->sig != NULL) {
        ult = ult->sig;
    }

    ult->sig = nuevoNodo;
    return 1;
}

int main() {

}