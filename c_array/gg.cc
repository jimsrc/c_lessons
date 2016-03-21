#include <stdio.h>
#include "stdlib.h"
#define nx 3
#define ny 3
#define nz 3

/* This creates a contiguos block of 2d-matrix
 */
double** arr2d(int ROWS, int COLS){
    double **A;
    A = (double**) malloc(ROWS * sizeof(double*));
    A[0] = (double*) malloc(ROWS * COLS * sizeof(double));
    for(int i = 1; i < ROWS; i++) 
        A[i] = A[i-1] + COLS;
    return A;
//source:
//http://stackoverflow.com/questions/13534966/how-to-dynamically-allocate-a-contiguous-block-of-memory-for-a-2d-array
}



/*  This alocates a contigous block of memory for 3d-matrix
 */
double*** arr3dAlloc(const int ind1, const int ind2, const int ind3)
{
  int i;
  int j;
  double*** array = (double***) malloc( (ind1 * sizeof(double*)) + (ind1*ind2 * sizeof(double**)) + (ind1*ind2*ind3 * sizeof(double)) );
  for(i = 0; i < ind1; ++i) {
    array[i] = (double**)(array + ind1) + i * ind2;
    for(j = 0; j < ind2; ++j) {
      array[i][j] = (double*)(array + ind1 + ind1*ind2) + i*ind2*ind3 + j*ind3;
    }
  }
  return array;
//source:
//http://stackoverflow.com/questions/2306172/malloc-a-3-dimensional-array-in-c
}



int main () {
// esto corre ok:
// g++ gg.cc
// ./a.out

    //------------ 3d
    double ***a;
    a = arr3dAlloc(nx, ny, nz);

    // test
    int i, j, k;
    i=1; j=2; k=1;
    a[i][j][k] = 10;
    printf(" arr : %g\n", a[i][j][k]);
    printf(" arr2: %g\n", (*(**a + i*nx*ny + j*ny + k)) );

    //------------ 2d
    double **b;
    b = arr2d(nx, ny);
    double *bp = &b[0][0];

    // test
    b[i][j] = 19.8;
    b[0][0] = 66.6; b[2][2]=77.7;
    printf(" b : %g\n", b[i][j]);
    printf(" b : %g\n", *(*b + 2 + 2*ny) ); // *b == &b[0][0]
    printf(" b : %g\n", bp[i*ny+j] );

    //------------ 2d-static
    double bb[nx][ny];
    // test
    bb[i][j] = 51.55;
    printf(" bb : %g\n", *(bb[i]+j));

    return 0;
}
