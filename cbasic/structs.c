#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Punto {
    double x;
    double y;
};

int main() {
    struct Punto *punto = malloc(sizeof(struct Punto));
    punto->x = 6.4;
    punto->y = 7.9;
    printf("x: %.2lf, y: %.2lf\n",punto->x, punto->y);
    free(punto);
}