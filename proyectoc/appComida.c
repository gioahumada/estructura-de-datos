#include <stdio.h>

struct Comidas {
    int id;
    char *nombre;
    char *categoria;
    int precio;
    int puntuacion; /* Puede variar entre 1 y 5*/
};

struct Aplicacion {
    char *nombre;
    struct Comidas **menu;
};

int buscarID(struct Comidas **array, int *pLibre, int buscar) {
    int i;

    if (*pLibre > 0) {
        for (i = 0;i<*pLibre;i++) {
            if (array[i]->id == buscar)
                return 1;
        }
    }
    return 0;
}

struct Comidas *crearComida(int id, char *nombre, char *categoria, int precio, int puntuacion) {
    struct Comidas *nuevaComida = (struct Comidas *) malloc(sizeof(struct Comidas ));

    nuevaComida->id = id;
    nuevaComida->nombre = nombre;
    nuevaComida->categoria = categoria;
    nuevaComida->precio = precio;
    nuevaComida->puntuacion = puntuacion;

    return nuevaComida;
}

int agregarComida(struct Aplicacion *app, int *pLibre, int id, char *nombre, char *categoria, int precio, int puntuacion) {
    int i;

    if(buscarID(app->menu, *pLibre, id) == 0) {
        app->menu[*pLibre] = crearComida(id, nombre, categoria, precio, puntuacion);
        (*pLibre)++;
        return 1;
    }
    return 0;
}

int main() {
    int *pLibre = 0;
    struct Aplicacion *Rappi = NULL;

}