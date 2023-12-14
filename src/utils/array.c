#include "array.h"


void freeArray(void **tab, int dimY) {
    int i;
    for (i = 0; i < dimY; i++) {
        free(tab[i]);
    }
    free(tab);
}

int** CreateEmptyIntArray(int dimX, int dimY) {
    int i, j;
    int** t = ec_malloc("create_empty_tab_int() -> malloc(t)", dimY * sizeof(*t));

    for (i = 0; i < dimY; i++) {
        t[i] = ec_malloc("create_empty_tab_int() -> malloc(t[i])", dimX * sizeof(**t));

        for(j = 0; j < dimX; j++) {
            t[i][j] = 0;
        }
    }

    return t;
}


char** CreateEmptyCharArray(int dimX, int dimY) {
    int i, j;
    char** t = ec_malloc("create_empty_tab_char() -> malloc(t)", dimY * sizeof(*t));

    for (i = 0; i < dimY; i++) {
        t[i] = ec_malloc("create_empty_tab_char() -> malloc(t[i])", dimX * sizeof(**t));

        for(j = 0; j < dimX; j++) {
            t[i][j] = 0;
        }
    }

    return t;
}