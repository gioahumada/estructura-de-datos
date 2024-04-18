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

/* Unica forma de saber es que te lo digan*/

/* Hay que usar do while */

/* */
struct Nodo {
    struct Dato *dat;
    struct Nodo *sig;
};

struct Alumnos *obtenerAlumno(struct NodoAlumnos *lista, int buscarID) {
    struct NodoAlumnos *rec = lista;
    if(lista != NULL) {
        do {
            if(rec->datosAlumnos->id == buscarID)
                return rec->datosAlumnos;
            rec = rec->sig;
        } while(rec != lista); //Evalua desde el segundo, nunca desde el primero <- condicion de finalizacion 
    }

    return NULL;
}

int agregarAlumno(struct NodoAlumnos **head, struct Alumnos *nuevo){
    struct NodoAlumnos *rec, *nuevoNodo;
    if(*head == NULL) {
        (*head) = (struct NodoAlumnos *) malloc(sizeof(struct NodoAlumnos));
        (*head)->datosAlumnos=nuevo;
        /**/(*head)->sig=*head;
        return 1;
    }

    if(obtenerAlumno(*head, nuevo->id) == NULL) {
        rec = *head;
        while(rec->sig != *head) // BUSCAR EL ULTIMO 
            rec = rec->sig;
        
        nuevoNodo = (struct NodoAlumnos *) malloc(sizeof(struct NodoAlumnos));
        nuevoNodo->datosAlumnos = nuevo;
        nuevoNodo->sig = rec->sig;
        rec->sig = nuevoNodo;

        return 1;
    }

    return 0;


}


/* 
TAREA 
Simplemente enlazada


Hacer una funcion para recorrer inversamente la lista para mostrar los datos. 
- sin arreglos. 
void mostrarAlumnosInversamente(struct NodoAlumno *head) {

}

int agregarAlumnoOrdenadoAscendentemente(struct NodoAlumno **head, struct Alumno *nuevo) {
    
}

void ordenarListaDeAlumnosDesc(struct NodoAlumno **head) {
    
}
*/