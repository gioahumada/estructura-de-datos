#include <stdio.h>
#include <stdlib.h>

struct Libro {
    int codigo;
    char *titulo;
    char *autor;
    int estante;
};

struct NodoLibro {
    struct Libro *libro;
    struct NodoLibro *ant, *sig;
};

struct Libro *crearLibro(int codigo, char *titulo, char *autor, int estante) {
    struct Libro *nuevoLibro = (struct Libro*) malloc(sizeof(struct Libro));

    nuevoLibro->codigo = codigo;
    nuevoLibro->titulo = titulo;
    nuevoLibro->autor = autor;
    nuevoLibro->estante = estante;

    return nuevoLibro;
}

int buscarID(struct NodoLibro *head, int id) {
    struct NodoLibro *ult = head;

    if(head == NULL) {
        return 0;
    }

    while(ult != NULL) {
        if(ult->libro->codigo == id) return 1;
        ult = ult->sig;
    }
    return 0;
}

int agregarAlFinal(struct NodoLibro **head, struct Libro *nuevoLibro) {
    struct NodoLibro *nuevoNodo = (struct NodoLibro *) malloc(sizeof(struct NodoLibro));

    nuevoNodo->libro = nuevoLibro;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    if(*head == NULL) {
        *head = nuevoNodo;
        return 1;
    }

    if(buscarID(*head, nuevoLibro->codigo)) return 0;

    struct NodoLibro *ult = *head;

    while(ult->sig != NULL) {
        ult = ult->sig;
    }

    ult->sig = nuevoNodo;
    nuevoNodo->ant = ult;
    return 1;
}

void leerLista(struct NodoLibro *head) {
    struct NodoLibro *ult = head;

    while(ult != NULL) {
        printf("ID: %d, Titulo: %s\n", ult->libro->codigo, ult->libro->titulo);
        ult = ult->sig;
    }

}


int main() {
    struct NodoLibro *head = NULL;

    agregarAlFinal(&head, crearLibro(1,"Crepusculo", "Giovanni", 3));
    agregarAlFinal(&head, crearLibro(1,"Papelucho", "Melado", 7));
    agregarAlFinal(&head, crearLibro(2,"Minions", "Sergio", 3));

    leerLista(head);
}