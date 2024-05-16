#include <stdio.h>
#include <stdlib.h>

struct SysTransportes {
    struct NodoPasajeros *pasajeros;
    struct NodoTrenes *trenes;
};

struct Pasajeros {
    char *nombre;
    char *ciudad;
    struct NodoTrenes *trenes;
};

struct Trenes {
    int id;
    int tipoTren;
    int cantMaxPasajeros;
};

struct NodoTrenes {
    struct Trenes *datos;
    struct NodoTrenes *sig;
};

struct NodoPasajeros {
    struct Pasajeros *clientes;
    struct NodoPasajeros *ant, *sig;
};

// Se verifica si algun pasajero se a subido al tren que se pide, si nadie se subio, se elimina el tren. 
void eliminarTrenOlvidado(struct SysTransportes *head, int codigoTren) {
    struct NodoPasajeros *recPasajeros = head->pasajeros;

    do {
        if(verSiSubio(recPasajeros, codigoTren) == 1) return; 
        
        recPasajeros = recPasajeros->sig;
    } while(recPasajeros != head->pasajeros);

    eliminarTren(&(head->trenes), codigoTren);
}

int verSiSubio(struct NodoPasajeros *head, int codigo) {
    struct NodoTrenes *recTren = head->clientes->trenes;

    while (recTren != NULL) {
        if(recTren->datos->id == codigo) return 1;

        recTren = recTren->sig;
    }

    return 0;
}

void eliminarTren(struct NodoTrenes **head, int codigo) {
    struct NodoTrenes *temp = *head;
    struct NodoTrenes *prev;

    if(temp != NULL && temp->datos->id == codigo) {
        *head = temp->sig;
        return;
    }

    while(temp != NULL && temp->datos->id != codigo) {
        prev = temp;
        temp = temp->sig;
    }

    if (temp == NULL) return;

    prev->sig = temp->sig;
}

struct Pasajero *pasajeroMasViajes(struct SysTransportes *head) {
    struct NodoPasajeros *recPasajero = head->pasajeros;
    struct Pasajero *pasajeroMaxViajes = NULL;
    int contMasViajes, viajes;

    do {
        viajes = contarTrenes(recPasajero);
        if (viajes > contMasViajes) {
            contMasViajes = viajes;
            pasajeroMaxViajes = recPasajero->clientes;
        }

        recPasajero = recPasajero->sig;
    } while(recPasajero != head->pasajeros);

    return pasajeroMaxViajes;
}

int contarTrenes(struct NodoPasajeros *pasajero) {
    struct NodoTrenes *recTren = pasajero->clientes->trenes;
    int cont = 0;

    while(recTren != NULL) {
        cont++;
        recTren = recTren->sig;
    }

    return cont;
}

int main() {

}