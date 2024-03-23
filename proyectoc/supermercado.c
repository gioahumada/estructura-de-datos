#include <stdio.h>
#include <stdlib.h>

struct Cliente{
    int numeroCliente;
    char *rut;
    char *nombre;
    int cupo;
};

struct Sucursal {
    int id;
    char *nombre;
    char *direccion;
    struct Cliente **clientes;
};

struct Supermercado {
    char *nombreGerente;
    char *rut;
    struct Sucursal **sucursales;
};

float promedioCuposClientes(struct Cliente **array) {
    int contador = 0;
    float promedio = 0;
    int i;

    for (i = 0; i<1000 && array[i] != NULL;i++) {
        promedio += array[i]->cupo;
        contador++;
    }

    if (contador > 0)
        return promedio / contador;
    return 0;

}

float promedioCupoSucursales(struct Sucursal **array) {
    int contador = 0;
    int i;
    float promedio = 0;

    for (i = 0; i<1000 && array[i]!=NULL;i++) {
        promedio += promedioCuposClientes(array[i]->clientes);
        contador++;
    }

    if (contador > 0)
        return promedio/contador;
    return 0;
}

/* Quitar Sucursales */
struct Sucursal *quitarSucursalCupoMasBajo(struct Sucursal **array) {
    int i;
    int posicionAEliminar = -1;

    struct Sucursal *sucursalEliminada = NULL;

    /* Sucursal a eliminar*/
    for(i=0; i<1000;i++) {
        if(posicionAEliminar == -1 || promedioCupoSucursales(array[i]->clientes) < promedioCuposClientes(array[posicionAEliminar]->clientes))
            posicionAEliminar = i;
    }

}

/* Comrpobar si cliente YA EXISTE*/
struct Cliente *crearCliente(int num, char *rut, char *nombre, int n) {
    struct Cliente *cliente;

    cliente = (struct Cliente *) malloc(sizeof(struct Cliente));

    cliente->numeroCliente = num;
    cliente->rut = rut;
    cliente->nombre = nombre;
    cliente->cupo = n;

    return cliente;


}

int main() {
}