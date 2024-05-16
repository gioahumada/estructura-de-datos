#include <stdio.h>
#include <stdlib.h>

#define cantViajes 1000

struct Bus{
    char *patente;
    char *marca;
    char *modelo;
    int capacidadTotal;
};

struct NodoBus {
    struct Bus *datosBus;
    struct NodoBus *sig;
};

struct Pasajero {
    int id;
    char *nombre;
    struct Bus **viajes;
    int pLibre;
};

struct NodoPasajero {
    struct Pasajero *datosPasajero;
    struct NodoPasajero *ant, *sig;
};

struct SistemaTransporte {
    struct NodoBus *headBuses;
    struct NodoPasajero *headPasajero;
};



int main() {

}