#include <stdio.h>
#include <stdlib.h>

struct Inmobiliaria {
    char *nombre;
    struct NodoProyecto *proyectos;
    struct NodoCliente *clientes;
};

struct Proyecto {
    char *ubicacion;
    int codigo;
    struct NodoCasa *casas;
};

struct Casa {
    int codigo;
    char *descripcion;
};

struct Cliente {
    int codigo;
    char *nombre;
    int edad;
    struct NodoCasa *propiedades;
};

struct NodoProyecto {
    struct Proyecto *proyecto;
    struct NodoProyecto *sig, *ant;
};

struct NodoCliente {
    struct Cliente *cliente;
    struct NodoCliente *sig;
};

struct NodoCasa {
    struct Casa *casa;
    struct NodoCada *ant, *sig;
};

struct Cliente *buscarDueno(struct Inmobiliaria *lista, int codigo) {
    struct Cliente *rec;

    if (lista != NULL) {
        rec = lista;

        while(rec != NULL) {
            if(rec->nombre == codigo) {
                
            }
            rec = rec->propiedades->sig;
        }
    }

    rec
}

int main() {

}