#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

main() {
    int numero, resultado; 

    numero = obtenerValor();
    printf("%d sumando dos es: %d",numero,sumarDos(numero));
}
