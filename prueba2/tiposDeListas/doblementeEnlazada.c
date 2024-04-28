#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int elemento;

    struct Nodo *ant;
    struct Nodo *sig;
};

struct Nodo *crearNodo(int n) {
    struct Nodo *new;
    new = (struct Nodo *)malloc(sizeof(struct Nodo));

    printf("Numero a agregar: \n");
    scanf("%d",&new->elemento);

    new->ant = NULL;
    new->sig = NULL;
    
    return new;
}

int enlazarNodo(struct Nodo **head, struct Nodo *new) {
    struct Nodo *rec = *head;

    if(*head = NULL) {
        *head = new;

        return 1;
    }

    while(rec != NULL) {
        if(rec->sig == NULL) {
            
            rec->sig = new;
            rec->sig->ant = NULL;

            rec = new;

        }
    }
}

int main() {

}