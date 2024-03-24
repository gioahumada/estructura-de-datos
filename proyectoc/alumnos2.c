#include <stdio.h>
#include <string.h>
#define cantMax 1000

struct Alumno {
    char *rut;
    char *nombre;
    float promedio;
};

int buscarAlumno(struct Alumno **array, int *pLibre, char *buscar) {
    int i;

    for (i=0;i<*pLibre;i++) {
        if(strcmp(array[i]->rut,buscar) == 0){
            return 1;
        }
    }
    return 0;
}

struct Alumno *crearAlumno(char *rut, char *nombre, float promedio) {
    struct Alumno *nuevoAlumno = (struct Alumno *) malloc(sizeof(struct Alumno));

    nuevoAlumno->rut = rut;
    nuevoAlumno->nombre = nombre;
    nuevoAlumno->promedio = promedio;

    return nuevoAlumno;
}

int agregarAlumno(struct Alumno **array, int *pLibre, char *rut, char *nombre, float promedio) {
    struct Alumno *alumnoNuevo;

    if (*pLibre < cantMax && buscarAlumno(array, *pLibre, rut)==0) {
        alumnoNuevo = crearAlumno(rut, nombre, promedio);
        array[*pLibre] = alumnoNuevo;
        (*pLibre)++;
        return 1;
    }
    return 0;
}

char *getAlumnoMejorPromedio(struct Alumno **Array, int *pLibre) {
    int 
}



int main() {
    int *pLibre = 0;
    /* Doble puntero por tratarse de una array*/
    struct Alumno **alumnos = (struct Alumno **) malloc(sizeof(struct Alumno *) * cantMax); /* Asigne memoria al array*/

    
}