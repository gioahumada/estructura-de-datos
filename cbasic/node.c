#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

int main() {
    struct Node *xd = malloc(sizeof(struct Node));
    xd->value = 1;

    xd->next = malloc(sizeof(struct Node));
    xd->next->value = 2;

    printf("Direccion de memoria Nodo 1: %p\n", xd);
    printf("Valor del primer nodo: %d\n\n", xd->value);

    printf("Direccion de memoria Nodo 2: %p\n", xd->next);
    printf("Valor del segundo nodo %d\n",xd->next->value);
}