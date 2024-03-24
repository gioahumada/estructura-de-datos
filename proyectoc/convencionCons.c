#include <stdio.h>
#define MAXarreglo 5000

struct Distrito {
    int id;
    char *nombre;
    float cantPoblacion;
};

struct Convencional {
    char *rut;
    char *nombre;
    char *comuna;
    struct Distrito *distritoRepresentado;
};

struct ConverncionConstitucional {
    char *fechaDeIncio;
    char *fechaFin;
    char *nombrePresidente;
    struct Convencional **convencionales;
    struct Distrito **distritos;
};

int contarConvencionales(struct Convencional **array, int id) {
    int i, cont;
    for (i = 0;i<MAXarreglo;i++) {
        if (array[i] != NULL && array[i]->distritoRepresentado->id == id) {
            cont ++;
        }
    }
    return cont;
}

int main() {
    struct ConvencionConstitucional **constituyente;
}