
#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for (int k=0; k < mat->r; k++){
			if (mat->data[k][k]!=0)
		eliminacja(k,mat,b);	
		}
return 0;
}


void eliminacja(int k,Matrix *mat, Matrix *b){
	for (int i = k+1; i < mat->r; i++)
        	if (mat->data[i][k] != 0){
                	double i_0 =  mat->data[i][k];
                	b->data[i][0] = (b->data[i][0] * mat->data[k][k] / i_0) - b->data[k][0];
                        for (int j = k; j < mat->c; j++){
                        	mat->data[i][j] = (mat->data[i][j] * mat->data[k][k] / i_0) - mat->data[k][j];

                        }
             	}

}

