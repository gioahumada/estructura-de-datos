#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamArreglos 5000

// Definición de estructuras
struct Artista {
    int id;
    char *nombre;
    char *genero;
    char *selloDiscografico;
};

struct Evento {
    int id;
    char *fecha;
    struct Artista *artista;
};

struct Recinto {
    int id;
    char *nombre;
    int capacidad;
    struct Evento **eventos;
    int pLibreEventos;
};

struct NodoRecinto {
    struct Recinto *datosRecinto;
    struct NodoRecinto *ant, *sig;
};

struct Pais {
    char *nombre;
    struct NodoRecinto *recintos;
};

struct NodoPais {
    struct Pais *pais;
    struct NodoPais *sig;
};

struct NodoArtista {
    struct Artista *datosArtista;
    struct NodoArtista *izq, *der;
};

struct ListaArtistas {
    int cantArtistas;
    struct NodoArtista *abbArtistas;
};

struct SistemaEventos {
    struct ListaArtistas *artistas;
    struct NodoPais *paises;
};

// Funciones auxiliares
struct NodoArtista* crearNodoArtista(struct Artista *nuevoArtista) {
    struct NodoArtista *nuevoNodo = (struct NodoArtista*) malloc(sizeof(struct NodoArtista));
    nuevoNodo->datosArtista = nuevoArtista;
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
}

int compararArtistas(struct Artista *a, struct Artista *b) {
    return a->id - b->id;
}

struct NodoArtista* agregarNodoArtista(struct NodoArtista *raiz, struct Artista *nuevoArtista) {
    if (raiz == NULL) {
        return crearNodoArtista(nuevoArtista);
    }
    if (compararArtistas(nuevoArtista, raiz->datosArtista) < 0) {
        raiz->izq = agregarNodoArtista(raiz->izq, nuevoArtista);
    } else if (compararArtistas(nuevoArtista, raiz->datosArtista) > 0) {
        raiz->der = agregarNodoArtista(raiz->der, nuevoArtista);
    }
    return raiz;
}

struct NodoArtista* buscarNodoArtista(struct NodoArtista *raiz, int idArtista) {
    if (raiz == NULL || raiz->datosArtista->id == idArtista) {
        return raiz;
    }
    if (idArtista < raiz->datosArtista->id) {
        return buscarNodoArtista(raiz->izq, idArtista);
    } else {
        return buscarNodoArtista(raiz->der, idArtista);
    }
}

int agregarArtista(struct SistemaEventos *SE, struct Artista *nuevoArtista) {
    if (buscarNodoArtista(SE->artistas->abbArtistas, nuevoArtista->id) != NULL) {
        return 0; // Artista ya existe
    }
    SE->artistas->abbArtistas = agregarNodoArtista(SE->artistas->abbArtistas, nuevoArtista);
    SE->artistas->cantArtistas++;
    return 1;
}

// Función para encontrar un recinto por ID
struct Recinto* buscarRecinto(struct NodoPais *paises, int idRecinto) {
    struct NodoPais *np = paises;
    while (np != NULL) {
        struct NodoRecinto *nr = np->pais->recintos;
        while (nr != NULL) {
            if (nr->datosRecinto->id == idRecinto) {
                return nr->datosRecinto;
            }
            nr = nr->sig;
        }
        np = np->sig;
    }
    return NULL;
}

// Función para verificar si un artista tiene un evento en una fecha dada
int artistaOcupado(struct Artista *artista, char *fecha) {
    // Aquí deberíamos recorrer todos los eventos del sistema para verificar esto
    // No está claro en el enunciado cómo están almacenados todos los eventos
    // Por simplicidad, supongamos que tenemos una función que hace esto
    return 0;
}

int agendarEvento(struct SistemaEventos *SE, int idEvento, int idRecinto, char *fechaEvento, int idArtista) {
    struct Recinto *recinto = buscarRecinto(SE->paises, idRecinto);
    if (recinto == NULL || recinto->pLibreEventos >= recinto->capacidad) {
        return 0; // Recinto no encontrado o lleno
    }

    struct NodoArtista *nodoArtista = buscarNodoArtista(SE->artistas->abbArtistas, idArtista);
    if (nodoArtista == NULL || artistaOcupado(nodoArtista->datosArtista, fechaEvento)) {
        return 0; // Artista no encontrado o ocupado en esa fecha
    }

    struct Evento *nuevoEvento = (struct Evento*) malloc(sizeof(struct Evento));
    nuevoEvento->id = idEvento;
    nuevoEvento->fecha = fechaEvento;
    nuevoEvento->artista = nodoArtista->datosArtista;

    recinto->eventos[recinto->pLibreEventos++] = nuevoEvento;
    return 1;
}

// Función para verificar si una fecha está libre en un recinto
int fechaLibreEnRecinto(struct Recinto *recinto, char *fecha) {
    for (int i = 0; i < recinto->pLibreEventos; i++) {
        if (strcmp(recinto->eventos[i]->fecha, fecha) == 0) {
            return 0;
        }
    }
    return 1;
}

int reprogramarEvento(struct SistemaEventos *SE, int idEvento, char *nuevaFecha) {
    // Se debe buscar el evento en todos los recintos
    struct NodoPais *np = SE->paises;
    while (np != NULL) {
        struct NodoRecinto *nr = np->pais->recintos;
        while (nr != NULL) {
            struct Recinto *recinto = nr->datosRecinto;
            for (int i = 0; i < recinto->pLibreEventos; i++) {
                struct Evento *evento = recinto->eventos[i];
                if (evento->id == idEvento) {
                    if (!fechaLibreEnRecinto(recinto, nuevaFecha) || artistaOcupado(evento->artista, nuevaFecha)) {
                        return 0; // Fecha ocupada en el recinto o por el artista
                    }
                    evento->fecha = nuevaFecha;
                    return 1;
                }
            }
            nr = nr->sig;
        }
        np = np->sig;
    }
    return 0; // Evento no encontrado
}

// Obtener eventos por artista
struct Evento* getEventosPorArtista(struct SistemaEventos *SE, int idArtista) {
    struct NodoArtista *nodoArtista = buscarNodoArtista(SE->artistas->abbArtistas, idArtista);
    if (nodoArtista == NULL) {
        return NULL;
    }

    struct Evento *listaEventos = NULL;
    struct Evento **ultimoEvento = &listaEventos;
    
    struct NodoPais *np = SE->paises;
    while (np != NULL) {
        struct NodoRecinto *nr = np->pais->recintos;
        while (nr != NULL) {
            struct Recinto *recinto = nr->datosRecinto;
            for (int i = 0; i < recinto->pLibreEventos; i++) {
                struct Evento *evento = recinto->eventos[i];
                if (evento->artista->id == idArtista) {
                    *ultimoEvento = evento;
                    ultimoEvento = &(evento->sig);
                }
            }
            nr = nr->sig;
        }
        np = np->sig;
    }
    return listaEventos;
}

// Obtener el ID del recinto más ocupado
int getIdRecintoMasOcupado(struct SistemaEventos *SE) {
    int maxEventos = -1;
    int idRecintoMasOcupado = -1;

    struct NodoPais *np = SE->paises;
    while (np != NULL) {
        struct NodoRecinto *nr = np->pais->recintos;
        while (nr != NULL) {
            struct Recinto *recinto = nr->datosRecinto;
            if (recinto->pLibreEventos > maxEventos) {
                maxEventos = recinto->pLibreEventos;
                idRecintoMasOcupado = recinto->id;
            }
            nr = nr->sig;
        }
        np = np->sig;
    }

    return idRecintoMasOcupado;
}

// Función para contar eventos por país
int contarEventosPais(struct Pais *pais) {
    int contador = 0;
    struct NodoRecinto *nr = pais->recintos;
    while (nr != NULL) {
        contador += nr->datosRecinto->pLibreEventos;
        nr = nr->sig;
    }
    return contador;
}

// Obtener los países con más eventos
struct Pais **paisesConMasEventos(struct SistemaEventos *SE) {
    int maxEventos = 0;
    struct NodoPais *np = SE->paises;
    
    while (np != NULL) {
        int eventos = contarEventosPais(np->pais);
        if (eventos > maxEventos) {
            maxEventos = eventos;
        }
        np = np->sig;
    }
    
    if (maxEventos == 0) {
        return NULL;
    }
    
    np = SE->paises;
    int count = 0;
    
    while (np != NULL) {
        if (contarEventosPais(np->pais) == maxEventos) {
            count++;
        }
        np = np->sig;
    }
    
    struct Pais **result = (struct Pais **) malloc(count * sizeof(struct Pais *));
    np = SE->paises;
    int i = 0;
    
    while (np != NULL) {
        if (contarEventosPais(np->pais) == maxEventos) {
            result[i++] = np->pais;
        }
        np = np->sig;
    }
    
    return result;
}

// Función para contar la variedad de artistas en un país
int contarVariedadArtistasPais(struct Pais *pais) {
    // Aquí se debe implementar una lógica para contar los diferentes artistas en el país
    return 0;
}

// Obtener el país con más variedad de artistas
struct Pais *paisConMasVariedadArtistas(struct SistemaEventos *SE) {
    int maxVariedad = 0;
    struct Pais *paisMaxVariedad = NULL;
    struct NodoPais *np = SE->paises;

    while (np != NULL) {
        int variedad = contarVariedadArtistasPais(np->pais);
        if (variedad > maxVariedad) {
            maxVariedad = variedad;
            paisMaxVariedad = np->pais;
        }
        np = np->sig;
    }

    return paisMaxVariedad;
}

// Obtener el ID del artista que visita más países
int getIdArtistaEnMasPaises(struct SistemaEventos *SE) {
    // Aquí se debe implementar una lógica para contar la cantidad de países que visita cada artista
    return -1;
}

// Quitar un artista del sistema
struct Artista *quitarArtista(struct SistemaEventos *SE, int idArtista) {
    // Aquí se debe implementar una lógica para eliminar un artista y sus eventos
    return NULL;
}

// Obtener lista de artistas por sello discográfico
struct ListaArtistas *getArtistasSelloDiscografico(struct SistemaEventos *SE, char *selloDiscografico) {
    struct ListaArtistas *lista = (struct ListaArtistas *) malloc(sizeof(struct ListaArtistas));
    lista->cantArtistas = 0;
    lista->abbArtistas = NULL;
    
    struct NodoArtista *na = SE->artistas->abbArtistas;
    
    while (na != NULL) {
        if (strcmp(na->datosArtista->selloDiscografico, selloDiscografico) == 0) {
            lista->abbArtistas = agregarNodoArtista(lista->abbArtistas, na->datosArtista);
            lista->cantArtistas++;
        }
        if (na->izq != NULL) {
            na = na->izq;
        } else if (na->der != NULL) {
            na = na->der;
        } else {
            break;
        }
    }
    
    if (lista->cantArtistas == 0) {
        free(lista);
        return NULL;
    }
    
    return lista;
}

int main() {
    // Aquí se pueden agregar pruebas de las funciones implementadas
    return 0;
}
