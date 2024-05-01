#include <stdio.h>
#include <stdlib.h>

struct Casa {
    int id;
    char *direccion;
    char *color;
};

struct NodoCasa {
    struct Casa *datos;
    struct NodoCasa *ant, *sig;
};

struct Casa *crearCasa(int id, char *direccion, char *color) {
    struct Casa *nuevaCasa = (struct Casa *) malloc(sizeof(struct Casa));

    nuevaCasa->id = id;
    nuevaCasa->direccion = direccion;
    nuevaCasa->color = color;

    return nuevaCasa;
}

int agregarAlUltimo(struct NodoCasa **head, struct Casa *casa) {
    struct NodoCasa *nuevoNodo = (struct NodoCasa*)malloc(sizeof(struct NodoCasa));

    nuevoNodo->datos = casa;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    if (*head == NULL) {
        *head = nuevoNodo;
        return 1;
    }

    struct NodoCasa *ult = *head;

    while(ult->sig != NULL) {
        ult = ult->sig;
    }

    ult->sig = nuevoNodo;
    nuevoNodo->ant = ult;
    return 1;
}

int eliminarNodo(struct NodoCasa **head, int buscar) {
    struct NodoCasa *temp = *head;

    while(temp != NULL && temp->datos->id != buscar) {
        temp = temp->sig;
    }

    if(temp == NULL) {
        return 0;
    }

    if(temp->ant = NULL) {
        *head = temp->sig;
    } else temp->ant->sig = temp->sig;

    if(temp->sig != NULL) {
        temp->sig->ant = temp->ant;
    }
}

void leerDatos(struct NodoCasa *head) {
    while(head != NULL) {
        printf("ID: %d, Direccion: %s, Color Casa %s\n", head->datos->id, head->datos->direccion, head->datos->color);
        head = head->sig;
    }
}

int main() {
    struct NodoCasa *head = NULL;

    agregarAlUltimo(&head, crearCasa(1, "Las Codornices", "Blanco"));
    agregarAlUltimo(&head, crearCasa(2, "Copiapo", "Negro"));
    agregarAlUltimo(&head, crearCasa(3, "Calle Falsa", "Rojo"));

    leerDatos(head);

    return 0;

}