#include <stdio.h>
#include <stdlib.h>
#define cantViajes 1000

struct Bus {
    char *patente;
    char *marca;
    char *modelo;
    int capacidadTotal;
};

struct NodoBus {
    struct Bus *datosBus;
    struct NodoBus *sig;
};

struct Pasajero{
    int id;
    char *nombre;
    struct Bus **viajes; //array con los viajes programados
    int pLibre; //pos libre
};

struct NodoPasajero {
    struct Pasajero *datosPasajero;
    struct NodoPasajero *ant, *sig;
};

struct SistemaTransporte {
    struct NodoBus *headBuses; // Simpl Enlazada
    struct NodoPasajero *headPasajeros; //doblmente enlazada circular
};

/* 
Esta función recibe una referencia al sistema de Transporte y la patente de un bus que debe ser quitado por desperfecto técnico. El procedimiento para reparar un bus se debe reparar a través de la compañía de seguros, lo cual demora aproximadamente 10 días; en caso contrario el mismo sistema puede repararlo en cuestión de hora, pero debe asumir el costo de dicha reparación, por lo cual no es la opción seleccionada siempre. Para quitar el bus debe reasignar todos los pasajeros que tienen viajes programados en dicho bus a otros buses que tengan el mismo destino y tengan capacidad disponible. En caso de no encontrar buses para todos los pasajeros del bus a eliminar entonces los pasajeros no se deberán reasignar y el bus no se quita. Para determinar si un bus tiene capacidad disponible deberá comparar la variable capacidadTotal del bus con la cantidad de referencias existentes desde los pasajeros a dicho bus.
*/

struct Bus *quitarBusAveriado(struct SistemaTransporte *tmv, char *patenteBus) {

}

int main() {

}