#include <stdio.h>
#include <stdlib.h>

struct DHL {
    char *nombreGerente;
    struct Region **regiones;
    struct NodoCliente *clientes;
};

struct Region {
    int numero;
    struct NodoCliente *clientes; 
};