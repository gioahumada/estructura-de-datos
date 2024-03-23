#include<stdio.h>

// 1) Entregar un arreglo con referencias al producto mas caro de cada sucursal;

//Contar sucursales que tengo (Struct Sucursal **sucursales, int max)
//

struct Producto {
    int codigo;
    char *nombre;
    int valor;
    int cant;
};

struct Sucursal {
    int numero;
    struct Producto **productos;
    int cantProductos;
};

int contarSucrusales (struct Sucursal **sucursales, int max) {
    int cont = 0, i;
    for (i = 0; i<max;i++) {
        if (sucursales[i] != NULL && sucursales[i]->productos[0] != NULL) cont++;
    }
    return cont;
}

struct Producto *getProductoMasCaro(struct Producto **productos, int max) {
    int mayor, i;
    struct Producto *may = NULL;
    for (i = 0;i<max && productos[i] != NULL;i++) {
        if (may == NULL || mayor < productos[i]->valor) {
            mayor = productos[i]->valor;
            may = productos[i];
        }
    }   
    return may; //es may pq mayor ya estaba usado 
}

struct Producto **obtenerProductosCaros(struct Sucursal **sucursales, int max, int *tamNuevo) {
    struct Producto **arregloProductos = NULL;
    int i, tam, pos=0;

    tam = *tamNuevo = contarSucursales(sucursales, max);
        if (tam > 0) {
            arregloProductos = (struct Producto **) malloc(tam * sizeof(struct Producto *));

 
            /* Llenado */
            for (i = 0; i<max;i++) {
                if(sucursales[i] != NULL && sucursales[i]->productos[i] != NULL) {
                    arregloProductos[pos] = getProductoMasCaro(sucursales[i]->productos, sucursales[i]->cantProductos);
                    pos++;
                }
                
            }
        }

        return arregloProductos;
}

void compactarSucursales(struct Sucursal **Sucursales, int max);
int moverProductosSucursal(struct Sucursal **sucursales, int max, int codigoProducto, int origen, int destino);
struct Sucursal *getSucursalMasCara(struct Sucursal **sucursales, int max);

// borrar arreglo[i] = NULL; 

main() {
    struct Producto **productosMayores;
    struct Sucursal **sucursales;
    int maxSuc = 1000;

    int cant, i;

    productosMayores = obtenerProductosCaros(sucursales, maxSuc, &cant);

    if(productosMayores != NULL)
        for (i = 0;i<cant;i++) {
            printf("%d", productosMayores[i]->codigo);
        }
    return 0;


    //struct Producto **obtenerProductosCaros(struct Sucursal**sucursales, int max);
    //Haga una funcion 

}

