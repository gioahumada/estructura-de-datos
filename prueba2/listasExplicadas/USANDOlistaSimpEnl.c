#include <stdio.h>
#include <stdlib.h>

struct Casa {
    int id;
    char *direccion;
    char *color;
};

struct NodoCasa {
    struct Casa *dato;
    struct NodoCasa *sig;
};

struct Casa *crearCasa(int id, char *direccion, char *color) {
    struct Casa *nuevaCasa = (struct Casa *) malloc(sizeof(struct Casa));

    nuevaCasa->id = id;
    nuevaCasa->direccion = direccion;
    nuevaCasa->color = color;

    return nuevaCasa;
}

int agregarAlFinal(struct NodoCasa **head, struct Casa *casa) {
    struct NodoCasa *nuevoNodo = (struct NodoCasa *) malloc(sizeof(struct NodoCasa));

    nuevoNodo->dato = casa;
    nuevoNodo->sig = NULL;

    if (*head == NULL) {
        *head = nuevoNodo;
        return 1;
    }

    struct NodoCasa *ult = *head;

    while(ult->sig != NULL) {
        ult = ult->sig;
    }

    ult->sig = nuevoNodo;
    return 1;
}

int eliminarCasa(struct NodoCasa **head, int buscar) {
    struct NodoCasa *temp = *head, *prev;

    if (temp != NULL && temp->dato->id == buscar) {
        *head = temp->sig;
        return 1;
    }

    while(temp != NULL && temp->dato->id != buscar) {
        prev = temp;
        temp = temp->sig;
    }

    if (temp == NULL) return 1;

    prev->sig = temp->sig;
    return 1;
}

void imprimirCasas(struct NodoCasa *head) {
    while (head != NULL) {
        printf("ID: %d, Direccion: %s, Color Casa: %s\n", head->dato->id, head->dato->direccion, head->dato->color);
        head = head->sig;
    }
}

int main() {
    struct NodoCasa *head = NULL;

    agregarAlFinal(&head, crearCasa(1, "Las Codornices", "Verde"));
    agregarAlFinal(&head, crearCasa(2, "Las Codornices", "Azul"));
    agregarAlFinal(&head, crearCasa(3, "Las Acacias", "Amarillo"));

    imprimirCasas(head);
    eliminarCasa(&head, 2);
    imprimirCasas(head);

    return 0;
}