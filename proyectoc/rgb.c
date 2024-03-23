#include <stdio.h>
#include <stdlib.h>

struct RGB {
    int r;
    int g;
    int b;
};

void rgb_set(struct RGB *rgb, int r, int g, int b) {
    if (r+g+b <= 255 * 3 && (r >= 0 && g >= 0 && b >= 0)) {
        rgb->r = r;
        rgb->g = g;
        rgb->b = b;
    }   
}

void rgb_invert(struct RGB *rgb) {
    rgb_set(rgb, 255 - rgb->r, 255 - rgb->g, 255 - rgb->b) ;
}

int main(int argc, char **argv) {
    /*
   if (argc != 2) {
        printf("Uso: rgb fichero\n");
        exit();
    }
    */

   struct RGB *rgb = malloc(sizeof(struct RGB));
   rgb->r = 0;
   rgb->g = 0;
   rgb->b = 0;
   

   printf("Color antes de invertir: [%d, %d, %d]\n", rgb->r, rgb->g, rgb->b);
   rgb_invert(rgb);
   printf("Color despues de invertir: [%d, %d, %d]\n", rgb->r, rgb->g, rgb->b);

   free(rgb);
}