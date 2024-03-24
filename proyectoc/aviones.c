#include <stdio.h>

struct Avion {
    int id;
    char *marca;
    char *modelo;
    int capacidad;
};

/* Buscar item */

int buscarAvion(struct Avion **array, int *pLibre, int buscar) {
    int i;
    for(i=0;i<*pLibre;i++) {
        if (array[i]->id == buscar) {
            return 1;
        }
    }
    return 0;
}

/* crear struct con informacion */

struct Avion *crearAvion(int id, char *marca, char *modelo, int capacidad) {
    struct Avion *nuevoAvion = (struct Avion *) malloc(sizeof(struct Avion));

    nuevoAvion->id = id;
    nuevoAvion->marca = marca;
    nuevoAvion->modelo = modelo;
    nuevoAvion->capacidad = capacidad;

    return nuevoAvion;
}

/* Agregar struct en struct con pLibre*/

int agregarAvion(struct Avion **array, int *pLibre, int tam, int id, char *marca, char *modelo, int capacidad) {
    struct Avion *avionNuevo = NULL;

    if (buscarAvion(array, pLibre, id)==0 && *pLibre < tam){
        avionNuevo = crearAvion(id, marca, modelo, capacidad);

        array[*pLibre] = avionNuevo;
        (*pLibre)++;
        return 1;
    }
    return 0;
}

/* Promedio de something */
float promedioCapacidad(struct Avion **array, int *pLibre) {
    int i, cant=0;
    float suma=0;

    if (*pLibre > 0) {
        for (i=0;i<*pLibre;i++) {
            suma += array[i]->capacidad;
            cant +=1;
        }
        return suma/cant;
    }
    return 0;
}

int contAvionesBajaCapacidad(struct Avion **array, int *pLibre) {
    float promedio = promedioCapacidad(array, *pLibre);
    int i, cont=0;

    if(promedio > 0) {
        for(i=0;i<*pLibre;i++){
            if(array[i]->capacidad < promedio)
                cont++;
        }
        return cont;
    }
    return 0;
}

void quitarAviones(struct Avion **array, int *pLibre, int id) {
    int i, j;

    for (i =0;i<*pLibre;i++) {
        if(array[i]->id == id) {
            array[i] = NULL;
        
            /* Compactacion */
            for(j=i;j<(*pLibre)-1;j++) {
                array[j] = array[j+1]; 
            }
            array[*pLibre-1] = NULL;
            (*pLibre)--;
        }
    }
}

struct Avion **quitarAvionesPocaCapacidad(struct Avion **array, int *pLibre) {
    struct Avion **eliminados = NULL;
    float promedio;
    int i, pos=0;
    promedio = promedioCapacidad(array, *pLibre);

    if (contAvionesBajaCapacidad(array, *pLibre) == 0) {
        eliminados = (struct Avion **) malloc(sizeof(struct Avion*) * contAvionesBajaCapacidad(array, *pLibre));
        for (i=0;i<*pLibre;i++) {
            if (array[i]->capacidad < promedio) {
                eliminados[pos] = array[i];
                pos++;
                quitarAviones(array, pLibre, array[i]->id);
            }
        }
    }
    return eliminados;


}




int main() {
    struct Avion **aviones, **eliminados;
    int pLibre=0;


}