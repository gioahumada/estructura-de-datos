#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cantMaxima 1000

/* Hacer codigo de Rappi*/

struct Alumnos {
    char *rut;
    char *nombre;
    float promedio;
};

int buscarAlumnos(struct Alumnos **alumnos, char *buscar, int *plibre) {
    int i;

    for (i = 0; i<plibre;i++) {
        if(strcmp(alumnos[i]->rut, buscar) == 0) {
            return 1;
        }
    }
    return 0;
}

int agregarAlumno(struct Alumnos **alumnos, int *plibre, char *rut, char *nombre, float promedio) {
    struct Alumnos *nuevoAlumno;

    if (plibre < cantMaxima && buscarAlumnos(alumnos, rut, *plibre) == 0) {
        nuevoAlumno = (struct Alumnos *) malloc(sizeof(struct Alumnos));
        strcpy(nuevoAlumno->rut, rut);
        strcpy(nuevoAlumno->nombre, nombre);
        nuevoAlumno->promedio = promedio;

        alumnos[*plibre] = nuevoAlumno;
        (*plibre)++;
        return 1;
    }
    return 0;
    
}

char *getAlumnoMejorPromedio(struct Alumnos **alumnos, int *plibre) {
    int i;

    for (i = 0;i<plibre;i++) {
        
    }
}

int main() {
    struct Alumnos **alumnos;


}