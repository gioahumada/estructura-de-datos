#include <stdio.h>
#include <stdlib.h>

/* https://github.com/RafaelMellado/INF2240-EstructuraDeDatos/blob/master/AyudaMunicipal/main.c */

struct Ayudado {
    char *rut;
    char *nombre;
    int ingresos;
    int montoAyuda;
};

struct NodoAyuadado {
    struct Ayudado *familia;
    struct NodoAyudado *sig;
};

struct RepartidorAyuda {
    int id;
    struct NodoAyudado *sig;
}

struct Ciudad {
    char *nombreAlcalde;
    char *nombreCiudad;
    struct RepartidorAyuda **repartidores;
};



int main() {

}