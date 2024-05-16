#include <stdio.h>
#include <stdlib.h>

struct Lord {
    char *nombre;
    char *apellido;
    int batallasGanadas;
    float oroInvertido;
};

struct NodoLord {
    struct Lord *datosLord;
    struct NodoLord *sig, *ant;
};

struct Casa {
    char *nombre;
    int cantidadMilitares;
    int oroAlmacenado;
    struct NodoLord *headLores;
};

struct NodoCasa {
    struct Casa *datosCasa;
    struct NodoCasa *sig;
};

struct TronoDeHierro {
    struct Lord *rey;
    int deuda;
    struct NodoCasa *casas;
};

int main() {

}

void eliminarReyActual(struct TronoDeHierro *corona) {
    if (corona->rey != NULL) {
        struct NodoCasa *recCasa = corona->casas;
        while (recCasa != NULL) {
            struct NodoLord *recLord = recCasa->datosCasa->headLores;
            while (recLord != NULL) {
                if (recLord->datosLord == corona->rey) {
                    if (recLord->ant != NULL) {
                        recLord->ant->sig = recLord->sig;
                    } else {
                        recCasa->datosCasa->headLores = recLord->sig;
                    }
                    if (recLord->sig != NULL) {
                        recLord->sig->ant = recLord->ant;
                    }
                    free(recLord);
                    break;
                }
                recLord = recLord->sig;
            }
            if (recLord != NULL) {
                break;
            }
            recCasa = recCasa->sig;
        }
        free(corona->rey);
        corona->rey = NULL;
    }
}
