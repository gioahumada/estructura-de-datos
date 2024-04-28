/* 
Codigo robado netamente con fines pedagogicos, porfavor el delito esta mal.
no roben.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 40

struct Juego {
    int id;
    char name[MAXLEN];
    int rating;
    int goty;
};

struct NodoJuego{
    struct Juego *juego;
    struct NodoJuego *prev;
    struct NodoJuego *next;
};

void leerCadena(char *str);
void leerDatosJuego(int *ptrId, char *name, int *ptrRating, int *ptrGoty);
struct Juego *crearJuego(int id, char *name, int rating, int goty);
struct NodoJuego *crearNodoJuego(struct Juego *juego);
struct Juego *buscarJuego(struct NodoJuego *lista, int idBuscado);
int agregarNodoJuego(struct NodoJuego **lista, struct NodoJuego *nuevo);
struct Juego *juegoMayorRating(struct NodoJuego *lista);
struct Juego *juegoMenorRating(struct NodoJuego *lista);
struct Juego *quitarJuego(struct NodoJuego **lista, int idAQuitar);
void showJuego(struct Juego *juego);
void showJuegosGoty(struct NodoJuego *lista);
void userMenu(struct NodoJuego **lista);
void accionAgregar(struct NodoJuego **lista);
void accionBuscar(struct NodoJuego *lista);
void accionMostrar(struct NodoJuego *lista);
void accionGoty(struct NodoJuego *lista);
void accionMayorRating(struct NodoJuego *lista);
void accionMenorRating(struct NodoJuego *lista);
void accionQuitar(struct NodoJuego **lista);
void accionEliminar(struct NodoJuego **lista);


int main() {
    struct NodoJuego *listaJuegos = NULL;
    userMenu(&listaJuegos);

    return 0;
}

void leerCadena(char *str) {
    char c;
    int i = 0;
    do {
        c = getchar();
        str[i] = c;
        i++;
    } while (c != '\n');
    str[i-1] = '\0';
}

void leerDatosJuego(int *ptrId, char *name, int *ptrRating, int *ptrGoty) {
    printf("Introduzca los datos del juego\n");
    printf("ID: ");
    scanf("%d%*c", ptrId);
    printf("Nombre: ");
    leerCadena(name);
    printf("Calificación (0-10): ");
    do {
        scanf("%d", ptrRating);

    } while (*ptrRating < 0 || *ptrRating > 10);
    do {
        printf("GOTY (0-1): ");
        scanf("%d", ptrGoty);
    } while (*ptrGoty > 1 || *ptrGoty < 0);
}

struct Juego *crearJuego(int id, char *name, int rating, int goty) {
    struct Juego *game;
    game = (struct Juego *) malloc(sizeof(struct Juego));
    game->id = id;
    strcpy(game->name, name);
    game->rating = rating;
    game->goty = goty;
    return game;
}

struct NodoJuego *crearNodoJuego(struct Juego *juego) {
    struct NodoJuego *nuevoNodo;
    nuevoNodo = (struct NodoJuego *) malloc(sizeof(struct NodoJuego));
    nuevoNodo->juego = juego;
    nuevoNodo->next = NULL;
    nuevoNodo->prev = NULL;
    return nuevoNodo;
}

struct Juego *buscarJuego(struct NodoJuego *lista, int idBuscado) {
    struct NodoJuego *current;
    if (lista != NULL) {
        current = lista;
        do {
            if (current->juego->id == idBuscado)
                return current->juego;
            current = current->next;
        } while (current != NULL);
    }
    return NULL;
}

int agregarNodoJuego(struct NodoJuego **lista, struct NodoJuego *nuevo) {
    struct NodoJuego *current, *prev;
    if (*lista == NULL) {
        *lista = nuevo;
        return 1;
    }
    if (buscarJuego(*lista, nuevo->juego->id) == NULL) {
        current = *lista;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        current->next = nuevo;
        current->next->prev = prev;
        return 1;
    }
    return 0;
}

struct Juego *juegoMayorRating(struct NodoJuego *lista) {
    struct Juego *mayorRating = NULL;
    struct NodoJuego *rec;
    rec = lista;
    while (rec != NULL) {
        if (mayorRating == NULL || rec->juego->rating > mayorRating->rating) {
            mayorRating = rec->juego;
        }
        rec = rec->next;
    }
    return mayorRating;
}

struct Juego *juegoMenorRating(struct NodoJuego *lista) {
    struct Juego *menorRating = NULL;
    struct NodoJuego *rec;
    rec = lista;
    while (rec != NULL) {
        if (menorRating == NULL || rec->juego->rating < menorRating->rating) {
            menorRating = rec->juego;
        }
        rec = rec->next;
    }
    return menorRating;
}

void showJuego(struct Juego *juego) {
    printf("%d - %s - %d/10\n", juego->id, juego->name, juego->rating);
}

void showJuegosGoty(struct NodoJuego *lista) {
    struct NodoJuego *current;
    current = lista;
    while (current != NULL) {
        if (current->juego->goty) {
            showJuego(current->juego);
        }
        current = current->next;
    }
}

struct Juego *quitarJuego(struct NodoJuego **lista, int idAQuitar) {
    struct NodoJuego *current;
    if (*lista != NULL) {
        current = *lista;
        do {
            if (current->juego->id == idAQuitar) {
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                if (current->prev == NULL) {
                    *lista = current->next;
                } else {
                    current->prev->next = current->next;
                }
                return current->juego;
            }
            current = current->next;
        } while (current != NULL);
    }
    return NULL;
}

void userMenu(struct NodoJuego **lista) {
    int option;
    do {
        printf("            BIBLIOTECA DE JUEGOS\n");
        printf("1. Agregar Juego            2. Buscar Juego\n");
        printf("3. Mostrar Juegos           4. Juegos GOTY\n");
        printf("5. Juego Mayor Rating       6. Juego Menor Rating\n");
        printf("7. Quitar Juego             8. Eliminar Juegos\n");
        printf("9. Terminar\n\n");
        do {
            printf("Introduzca la opción que desea realizar (1-9): ");
            scanf("%d%*c", &option);
        } while (option < 1 || option > 9);

        switch (option) {
            case 1:
                accionAgregar(lista);
                break;
            case 2:
                accionBuscar(*lista);
                break;
            case 3:
                accionMostrar(*lista);
                break;
            case 4:
                accionGoty(*lista);
                break;
            case 5:
                accionMayorRating(*lista);
                break;
            case 6:
                accionMenorRating(*lista);
                break;
            case 7:
                accionQuitar(lista);
                break;
            case 8:
                accionEliminar(lista);
                break;
            case 9:
                printf("Gracias por usar la biblioteca de juegos :)");
                break;
            default:
                break;
        }
        printf("\n");
    } while (option != 9);
}

void accionAgregar(struct NodoJuego **lista) {
    struct NodoJuego *nodoJuego;
    struct Juego *game;
    char name[MAXLEN];
    int result, id, rating, goty;
    leerDatosJuego(&id, name, &rating, &goty);
    game = crearJuego(id, name, rating, goty);
    nodoJuego = crearNodoJuego(game);
    result = agregarNodoJuego(lista, nodoJuego);
    if (result) {
        printf("Juego Agregado Exitosamente!\n");
    } else {
        printf("Juego Repetido, No Agregado.\n");
    }

}

void accionBuscar(struct NodoJuego *lista) {
    int idBuscado;
    if (lista == NULL) {
        printf("No Hay Juegos En Biblioteca.\n");
    } else {
        printf("Introduzca ID del juego a buscar: ");
        scanf("%d", &idBuscado);
        if (buscarJuego(lista, idBuscado) == NULL) {
            printf("Juego No Encontrado.\n");
        } else {
            showJuego(buscarJuego(lista, idBuscado));
        }
    }
}

void accionMostrar(struct NodoJuego *lista) {
    struct NodoJuego *rec;
    if (lista == NULL) {
        printf("No Hay Juegos En Biblioteca.\n");
    } else {
        rec = lista;
        while (rec != NULL) {
            showJuego(rec->juego);
            rec = rec->next;
        }
    }
}

void accionGoty(struct NodoJuego *lista) {
    if (lista == NULL) {
        printf("No Hay Juegos En Biblioteca.\n");
    } else {
        printf("Juegos que han ganado el premio GOTY:\n");
        showJuegosGoty(lista);
    }
}

void accionMayorRating(struct NodoJuego *lista) {
    if (lista == NULL) {
        printf("No Hay Juegos En Biblioteca.\n");
    } else {
        printf("Juego con mayor rating registrado:\n");
        showJuego(juegoMayorRating(lista));
    }
}

void accionMenorRating(struct NodoJuego *lista) {
    if (lista == NULL) {
        printf("No Hay Juegos En Biblioteca.\n");
    } else {
        printf("Juego con menor rating registrado:\n");
        showJuego(juegoMenorRating(lista));
    }
}

void accionQuitar(struct NodoJuego **lista) {
    int idAQuitar;
    if (*lista == NULL) {
        printf("No Hay Juegos En Biblioteca.\n");
    } else {
        printf("Introduzca ID del juego a quitar: ");
        scanf("%d", &idAQuitar);
        if (buscarJuego(*lista, idAQuitar) == NULL) {
            printf("Juego No Encontrado.\n");
        } else {
            showJuego(quitarJuego(lista, idAQuitar));
        }
    }
}

void accionEliminar(struct NodoJuego **lista) {
    int option;
    printf("Al eliminar juegos se perderán los juegos de la biblioteca.\n");
    printf("1. Eliminar                                    0. Cancelar\n");
    scanf("%d", &option);
    if (option) {
        *lista = NULL;
        printf("Juegos Eliminados Exitosamente.\n");
    } else {
        printf("Eliminación de Juegos Cancelada.\n");
    }
}