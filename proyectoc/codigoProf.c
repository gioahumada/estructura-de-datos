#include <stdio.h>
#include <stdlib.h>

struct Juego {
    int codigo;
    char *nombre;
    char *categoria;
    int valor;
};

int buscarJuego(struct Juego **juegos, int tam, int codigoBuscado);
struct Juego *crearJuegoNuevo(int codigoNuevo, char *nombreNuevo, char *categoriaNueva, int valorNuevo);
int agregarJuego(int codigoNuevo, char *nombreNuevo, char *categoriaNueva, int valorNuevo, struct Juego **juegos, int tam);
int buscarJuegoCompacto(struct Juego **juegos, int pLibre, int codigoBuscado);
int promValoresJuegos(struct Juego **juegos, int tam);
int contarJuegosCaros(struct Juego **juegos, int tam, int promedioValorJuegos);
void agregarJuegoCaro(struct Juego **juegos, int tam, struct Juego **juegosCaros, int promedioValorJuegos);

int main() {
    struct Juego **juegos, **juegosCaros;
    int tam = 0, tamCaros = 0, promValores = 0;

    do {
        printf("Ingrese la cantidad de juegos máxima a registrar: ");
        scanf("%d", &tam);
    } while (tam <= 0);

    juegos = (struct Juego **) malloc(tam * sizeof(struct Juego *));

    promValores = promValoresJuegos(juegos, tam);
    tamCaros = contarJuegosCaros(juegos, tam, promValores);
    juegosCaros = (struct Juego **) malloc(tamCaros * sizeof(struct Juego *));


    return 0;
}

int buscarJuego(struct Juego **juegos, int tam, int codigoBuscado) {
    int i;
    for (i = 0; i < tam; i++) {
        if (juegos[i] != NULL && juegos[i]->codigo == codigoBuscado)
            return 1;
    }
    return 0;
}

struct Juego *crearJuegoNuevo(int codigoNuevo, char *nombreNuevo, char *categoriaNueva, int valorNuevo) {
    struct Juego *juegoNuevo;

    juegoNuevo = (struct Juego *) malloc(sizeof(struct Juego));

    juegoNuevo->codigo = codigoNuevo;
    juegoNuevo->nombre = nombreNuevo;
    juegoNuevo->categoria = categoriaNueva;
    juegoNuevo->valor = valorNuevo;
    return juegoNuevo;
}

int agregarJuego(int codigoNuevo, char *nombreNuevo, char *categoriaNueva, int valorNuevo, struct Juego **juegos, int tam) {
    int i = 0;
    if (!buscarJuego(juegos, tam, codigoNuevo)) {
        for (i = 0; i < tam; i++) {
            if (juegos[i] == NULL) {
                juegos[i] = crearJuegoNuevo(codigoNuevo, nombreNuevo, categoriaNueva, valorNuevo);;
                return 1;
            }
        }
    }
    return 0;
}

int buscarJuegoCompacto(struct Juego **juegos, int pLibre, int codigoBuscado) {
    int i;
    for (i = 0; i < pLibre; i++) {
        if (juegos[i]->codigo == codigoBuscado)
            return 1;
    }
    return 0;
}

int agregarJuegoCompacto(int codigoNuevo, char *nombreNuevo, char *categoriaNueva, int valorNuevo, struct Juego **juegos, int tam, int *pLibre) {
    int i = 0;
    if (!buscarJuegoCompacto(juegos, *pLibre, codigoNuevo)) {
        juegos[(*pLibre)] = crearJuegoNuevo(codigoNuevo, nombreNuevo, categoriaNueva, valorNuevo);;
        (*pLibre)++;
        return 1;
    }
    return 0;
}

int promValoresJuegos(struct Juego **juegos, int tam) {
    int i, totalValores = 0;
    for (i = 0; i < tam; i++) {
        totalValores += juegos[i]->valor;
    }
    return totalValores/tam;
}

int contarJuegosCaros(struct Juego **juegos, int tam, int promValorJuegos) {
    int i, cont = 0;
    for (i = 0; i < tam; i++) {
        if (juegos[i]->valor > promValorJuegos)
            cont++;
    }
    return cont;
}

void agregarJuegoCaro(struct Juego **juegos, int tam, struct Juego **juegosCaros, int promValorJuegos) {
    int i, pLibre = 0;
    for (i = 0; i < tam; i++) {
        if (juegos[i]->valor > promValorJuegos) {
            juegosCaros[pLibre] = juegos[i];
            pLibre++;
        }
    }
}
