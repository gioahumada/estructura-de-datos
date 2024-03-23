#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct Compra {
    char *nombreCliente;
    int montoCompra;
    char *fecha;
};

int contarFechasAQuitar(struct Compra **compras, char *fecha, int max) {
    int i, cont=0;
    for (i = 0; i<max;i++) {
        if (compras[i] != NULL) {
            if (strcmp(compras[i]->fecha, fecha) == 0) {
                cont++;
            }
        }
    }
    return cont;
}

struct Compra **quitarComprasDeUnaFecha(struct Compra **compras, int max, char *fecha) {
    int i;
    struct Compra **eliminados = NULL;

    int tam = contarFechasAQuitar(compras, fecha, MAX);
        if (tam <= 0) return eliminados;

    /* Variable para saber el indice de donde enviar el contenido*/
    int pos=0;

    /* Uso de TAM para asignar tamaño al array*/
    eliminados = (struct Compra**) malloc(sizeof(struct Compra *) * tam);

    for (i = 0; i<max; i++) {
        if (compras[i] != NULL && strcmp(compras[i]->fecha, fecha) == 0) {
            eliminados[pos] = compras[i];

            pos++;

            compras[i] = NULL;
        }
    }

    return eliminados;

}

int main () {
    int tam;

    struct Compra **compras;

}


