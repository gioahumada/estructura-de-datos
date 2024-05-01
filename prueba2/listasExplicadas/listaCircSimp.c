#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

struct Nodo *crearNodo(int dato) {
    struct Nodo *nuevoNodo = (struct Nodo *) malloc(sizeof(struct Nodo));

    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

int insertarAlfinal(struct Nodo **head, struct Nodo *nuevoNodo) {
    struct Nodo *ult = *head;

    if (*head == NULL) {
        *head = nuevoNodo;
        (*head)->sig = *head;
        return 1;
    }

    do {
        ult = ult->sig;
    } while(ult->sig != *head);

    nuevoNodo->sig = ult->sig;
    ult->sig = nuevoNodo;
    return 1;
}

void leerDatos(struct Nodo *head) {
    struct Nodo *ult = head;
    if (ult) {
        do {
            printf("%d\n", ult->dato);
            ult = ult->sig;
        } while(ult != head);
    }
    return;
}

int main() {
    struct Nodo *head = NULL;

    insertarAlfinal(&head, crearNodo(37));
    insertarAlfinal(&head, crearNodo(45));
    insertarAlfinal(&head, crearNodo(23));

    leerDatos(head);

}