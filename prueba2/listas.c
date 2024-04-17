/* 
Listas -> Importante punteros 
    No existe nada unico.

        head
    Si lista = NULL ; vacia.
    Primer elemento Null -> Lista vacia.


ES LA B CREOO si era:c


Actividad talller aula -> Opcional 
1semana para realizarla. 5 Decimas. 

Que tan efectivo 
*/

#include <string.h>
#include <stdio.h>

struct NodoAlumno {
    char *nombre;
    int edad;
    struct NodoAlumno *next;
};

struct NodoAlumnos *crearAlumno(char *nombre, int edad) {
    struct NodoAlumno *nuevo;
    nuevo = (struct NodoAlumno*) malloc(sizeof(struct NodoAlumno));
    nuevo->nombre = nombre;
    nuevo->edad = edad;
    nuevo->next = NULL;
    return nuevo;

}

int agregarAlumno(struct NodoAlumno** lista, struct NodoAlumno *nuevo) {
    struct NodoAlumno *rec;

}

int main() {
    struct NodoAlumno *head = NULL;

}