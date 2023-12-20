
#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for (int k=0; k < mat->r; k++){
		change_rows(k,mat,b);
        	if (mat->data[k][k] == 0)
			return 1;
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

void change_rows(int k,Matrix *mat, Matrix *b){
	int i=0;
 	int z=k;
	double temp;
	int j;
	while(i<mat->r){
		if (mat->data[i][k] >mat->data[z][k]){
			z=i;
		}
		i++;
	}
    	temp = b->data[k][0];
	b->data[k][0] =  b->data[z][0];
	b->data[z][0] = temp;
	for(j=k; j < mat->c; j++){
		temp = mat->data[k][j];
		mat->data[k][j] = mat->data[z][j];
		mat->data[z][j] = temp;	
	}
}
