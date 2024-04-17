#include <stdio.h>
#include <stdlib.h>

struct Alumnos {
    int id;
    char *nombre;
    int edad;
};

struct NodoAlumnos {
    struct Alumnos *datosAlumnos;
    struct NodoAlumnos *sig;
};

struct Alumnos *crearAlumno(int id, char *nombre, int edad) {
    struct Alumnos *nuevo;
    /* Asigno memoria*/
    nuevo = (struct Alumnos*) malloc(sizeof(struct Alumnos));

    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->edad = edad;

    return nuevo;
}

struct Alumno *obtenerAlumno(struct NodoAlumno *head, int buscarID) {
    struct NodoAlumnos *peo;

    peo = head;
    while(peo != NULL) {
        if(peo->datosAlumnos->id == buscarID) 
            return peo->datosAlumnos;
        peo = peo->sig;
    }
}

int agregarAlumno(struct NodoAlumnos **lista, struct Alumnos *nuevo) {
    struct NodoAlumnos *aux, *rec;

    if(*lista == NULL) {
        *lista=(struct NodoAlumnos *)malloc(sizeof(struct NodoAlumnos));
        (*lista)->datosAlumnos=nuevo;
        (*lista)->sig=NULL;

        return 1;
    }

    if(obtenerAlumno(*lista, nuevo->id) == NULL) {
        rec = *lista;
        while(rec->sig != NULL)
            rec = rec->sig;

        rec->sig = (struct NodoAlumnos *) malloc(sizeof(struct NodoAlumnos));
        rec->sig->datosAlumnos=nuevo;
        rec->sig->sig=NULL;

        return 1;
    }

    return 0;
}


int main() {
    struct NodoAlumno *head = NULL, *nuevoAlumno;
    int resultado;

    nuevoAlumno = crearAlumno(1, "Giovanni", 20);
    resultado = agregarAlumno(&head, nuevoAlumno);

    if(resultado == 1)
        printf("Felicidades");
    else
        printf("Pesimo, retirate de la carrera");
}