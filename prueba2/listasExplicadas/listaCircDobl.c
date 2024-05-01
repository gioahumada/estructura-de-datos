#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ant, *sig;
};

struct Nodo *crearNodo(int dato) {
    struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));

    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    return nuevoNodo;
}

int insertarAlFinal(struct Nodo **head, struct Nodo *nuevoNodo) {
    struct Nodo *ult = *head;

    if (*head == NULL) {
        *head = nuevoNodo;
        (*head)->sig = *head;
        (*head)->ant = *head;
        return 1;
    }

    do {
        ult = ult->sig;
    } while(ult->sig != *head);

    nuevoNodo->sig = ult->sig;
    nuevoNodo->ant = ult;

    ult->sig = nuevoNodo;
    (*head)->ant = nuevoNodo;
    return 1;
}

int main() {

}