#include <stdio.h>
#define limite 7

int main() {
    int i, array[10];

    array[0] = 1;
    array[1] = 35;
    array[2] = 24;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;
    array[6] = 9;

    // CODIGO AQUI - CODIGO AQUI - CODIGO AQUI
        printf("[%d] ", array[i]);

    return 0;
}

/* ALTERNATIVAS

RESPUESTA 
[35] [24] [4] [5] [6] [9]

1) for(i = 0; i < limite; i++) 
2) for(i = 1; i < 6; i++) {
3) for(i = 1; i < limite; i++) {
4) for(i = 0; i < 7; i++) {

*/