#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Fecha;

typedef struct {
    char* nombre;
    Fecha* fecha;
    int tamano;
} Evento;

int main() {
    Evento evento;
    evento.nombre = "Evento de prueba";
    evento.tamano = 0;
    evento.fecha = NULL;

    printf("Ingrese las fechas del evento [dd mm aaaa] (ingresar 0 0 0 para terminar) \n");

    while (1) {
        Fecha fecha;
        scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.ano);

        if(fecha.dia == 0 && fecha.mes == 0 && fecha.ano == 0) break;

        evento.tamano++;

        evento.fecha = realloc(evento.fecha, evento.tamano * sizeof(Fecha));
        if(evento.fecha == NULL) return EXIT_FAILURE;

        evento.fecha[evento.tamano - 1] = fecha;
    }

    printf("Las fechas del %s son: \n",evento.nombre);
    for (int i = 0; i<evento.tamano;i++) {
        printf("%d/%d/%d\n",evento.fecha[i].dia, evento.fecha[i].mes, evento.fecha[i].ano);
    }

    free(evento.fecha);

    return 0;
}