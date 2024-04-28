#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//definicion estructura de libro
struct Libro
{
    int codigo;
    char *titulo;
    char *autor;
    int estante;
    bool disponibilidad;
};

//definicion  estructura nodoLibro
struct NodoLibro
{
    struct Libro *libro;
    struct NodoLibro* sig;
    struct NodoLibro* ant;
};

//funcion para crear un struct libro nuevo
//parametros son los elementos de struct libro
struct Libro *crearLibro(int codigo, char *titulo, char *autor, int estante, bool disponibilidad)
{
    //creo variable nueva y asigno memoria
    struct Libro *nuevoLibro;
    nuevoLibro = (struct Libro*)malloc(sizeof(struct Libro));
    //------------------------------------------------

    // asigno datos a nueva variable
    nuevoLibro -> codigo = codigo;

    nuevoLibro -> titulo = titulo;

    nuevoLibro -> autor = autor;

    nuevoLibro -> estante = estante;

    nuevoLibro -> disponibilidad = disponibilidad;

    return nuevoLibro; // nueva variable
}

//funcion que crea el nodoLibro
struct NodoLibro *crearNodoLibro(struct Libro *libro)
{
    //creo variable y asigno memoria
    struct NodoLibro *nuevoNodo;
    nuevoNodo = (struct NodoLibro*)malloc(sizeof(struct NodoLibro));
    // ------------------------------------------------

    //asigno datos a nueva variable

    nuevoNodo -> libro = libro;

    nuevoNodo -> sig = NULL;

    nuevoNodo -> ant = NULL;

    return nuevoNodo;
}

//funcion para enlazar nidolibro a lista
void agregarNodoALista(struct NodoLibro **lista, struct Libro *libro)
{
    //creo un nuevo nodo con el libro
    struct NodoLibro *nuevoNodo = crearNodoLibro(libro);

    //si la lista esta vacia, el nuevo nodo se convierte en el head
    if (*lista == NULL)
    {
        *lista = nuevoNodo;
        return;
    }

    struct NodoLibro *rec = *lista;

    //si no, recorro la lista con un while hasta encontrar el ultimo nodo
    //valido que la posicion siguiente sea diferente de null para que actual tome la posicion de siguiente
    while (rec->sig != NULL)
    {
        rec = rec->sig;
    }

    // en caso de que siguiente == NULL entonces salgo del ciclo while

    //enlazo el nuevo nodo al final de la lista y con el nodo anterior
    rec->sig = nuevoNodo;
    nuevoNodo->ant = rec;
}

void agregarAListaInicio(struct NodoLibro **lista, struct Libro *libro)
{
    //uso funcion para crear nodo
    struct NodoLibro *nuevoNodo = crearNodoLibro(libro);
    // verifico si la lista esta vacia si lo esta, el nodo sera el head
    if (*lista == NULL)
    {
        *lista = nuevoNodo;
        return;
    }
    // en caso de lo contrario (*head) -> anterior = nuevo nodo
    // y nuevo nodo -> siguiente = *head
    //por lo que enlazo el nodo nuevo antes que head y al mismo tiempo lo enlazo a el
    (*lista) -> ant = nuevoNodo;
    nuevoNodo -> sig = *lista;

    //y por ultimo head = &nuevo nodo (& es para reasignar head a nuevo nodo)
    lista = &nuevoNodo;
}

struct NodoLibro *buscarCodigo(struct NodoLibro *lista, int codigoRecibido)
{
    // creo variable para recorrido
    struct NodoLibro *rec;

    // valido que la lista no sea nula para recorrerla
    if (lista != NULL )
    {
        // recorrido = "posicion" lista(head)
        rec = lista;
        // mientras recorrido sea distinto de null entra al loop
        while(rec != NULL)
        {
            // si rec(posicion) -> libro -> codigo es == al codigo por buscar, retorna recorrido(posicion de nodo) en el que se encontro
            if(rec -> libro -> codigo == codigoRecibido)
            {
                return rec;
            }
            // en caso de que no encuentra el codigo sale del if y avanza de nodo( posicion +1)
            rec = rec -> sig;
        }
    }
    // en caso de que la lista sea nula o de no encontrar el codigo durante todo el recorrido retorna null
    return NULL;
}

// para desreferenciar el nodo(borrarlo)  (el que voy a borrar)rec -> siguiente -> anterior = rec -> anterior
//                                        (el que voy a borrar)rec -> anterior -> siguiente = rec -> siguiente


void buscarAutor(struct NodoLibro *lista, char *autorBuscar)
{
    // creo variable para recorrido
    struct NodoLibro *rec;
    // valido que la lista no sea nula para recorrerla
    if (lista != NULL )
    {
        // recorrido = "posicion" lista(head)
        rec = lista;
        // mientras recorrido sea distinto de null entra al loop
        while(rec != NULL)
        {
            // si strcmp(comparar strings) autor == a autor buscado
            // actualizo la disponibilidad a false ya que se llevaron todos los libros
            if(strcmp(rec -> libro -> autor, autorBuscar) == 0)
            {
                rec -> libro -> disponibilidad = false;
            }
            // en caso de que no encuentra el autor sale del if y avanza de nodo( posicion +1)
            rec = rec -> sig;
        }
    }
}

struct NodoLibro *buscarEstante(struct NodoLibro *lista, int estanteBuscar)
{

    struct NodoLibro *rec;

    if (lista != NULL )
    {
        rec = lista;

        while(rec != NULL)
        {
            if(rec -> libro -> estante == estanteBuscar)
            {

            }
            rec = rec -> sig;
        }
    }
}


int main ()
{
    return 0;
}
