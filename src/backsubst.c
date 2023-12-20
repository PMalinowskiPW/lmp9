#include "backsubst.h"
#include "mat_io.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

        if (mat->c != x->r){
                fprintf(stderr, "Błąd nieprawidłowych rozmiarów macierzy\n");
                return 2;
        }

        for (int i = 1; i <= mat->r; i++) {

                x->data[x->r -i][0] = b->data[b->r -i][0];

                for (int j = 1; j < i; j++)
                        x->data[x->r -i][0] -= (mat->data[mat->r - i][mat->c -j -1] * x->data[x->r -i +1][0]);

                if (mat->data[mat->r -i][mat->c -i] == 0){
                        fprintf(stderr, "Błąd dzielenia przez 0 (element na diagonali = 0)\n");
                        return 1;
                }

                x->data[x->r -i][0] /= mat->data[mat->r -i][mat->c -i];
        }

return 0;
}
