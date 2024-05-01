#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ant, *sig;
};

struct Nodo *crearNodo(int nuevoDato) {
    struct Nodo *nuevoNodo = (struct Nodo *) malloc(sizeof(struct Nodo));

    nuevoNodo->dato = nuevoDato;

    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

int insertarAlFinal(struct Nodo **head, int nuevoDato) {
    struct Nodo *nuevoNodo = crearNodo(nuevoDato);

    if(*head == NULL) {
        *head = nuevoNodo;
    }

    struct Nodo *ult = *head;

    while(ult->sig != NULL) {
        ult = ult->sig;
    }

    ult->sig = nuevoNodo;
    nuevoNodo->ant = ult;

    return 1;
}

int main() {

}