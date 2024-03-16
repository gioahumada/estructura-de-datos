#ifndef FUNCIONES_H
#define FUNCIONES_H

struct User {
    char username[50];
    char password[50];
};

int sessionLogin(User)

int sumarDos(int n) {
    return n + 2;
}

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



#endif
