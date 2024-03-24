#include <stdio.h>
#include <stdlib.h>

struct Evaluacion {
    int id;
    int nota;
};

struct Alumno {
    char *rut;
    char *nombre;
    struct Evaluacion **notas;
};



int main() {

}