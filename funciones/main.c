#include <stdio.h>
#include <stdlib.h>

int obtenerValor() {
    int numero;

    do {
    printf("Ingrese un valor positivo y entero");
    scanf("%d", &numero);
    } while(numero<=0);

    return numero;
}

int determinarNumeroPar(int numero) {
    if (numero % 2 == 0) 
        return 1;

    return 0;
}

main() {
    int numero, resultado; 

    numero = obtenerValor();
    resultado = determinarNumeroPar(numero);

    if (resultado == 1) printf("El numero es par");
    else printf("El numero es impar");
}

hacer sumatoria