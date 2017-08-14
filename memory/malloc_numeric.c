#include <stdio.h>
#include "stdlib.h"
#include <math.h>
/* For a 1GB array of double type (8 byte precision), we
 * need a total of (1024*1024*1024 bytes)/(8 bytes) = 2**27
 * elements.
 */
#define NX 4096     // 2**12
#define NY 32768    // 2**15
#define NZ 3

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


void free_array2d(double **arr, int nrows){
    //--- free ALL pointers ---//

    // as this a single contiguos block
    // of memory, we just need to free
    // the pointer to the 1st element! :)
    free(arr);
}


int main(){
    char input[100];
    //------------ 2d
    double **b;
    b = arr2d(NX, NY);
    //double *bp = &b[0][0];

    // test
    //b[i][j] = 19.8;
    //b[0][0] = 66.6; b[2][2]=77.7;
    printf("\n [*] Press a key to star filling\n\n");
    scanf("%s", &input);
    for(int i=0; i<NX; i++){
        printf("\n   [*] Filling row %d", i);
        if( fmodf(1.*i,1000.)==0. ) scanf("%s", &input);
        //printf(" i:%d; mod: %g\n", i, fmodf(1.*i,100.));
        for(int j=0; j<NY; j++){
            //printf("i,j: %d, %d\n", i, j);
            b[i][j] = 3.4;
        }
    }
    sleep(1);
    printf("\n [+] Finished filling w/ values.\n");

    printf("\n [*] Press a key to free memory\n\n");
    scanf("%s", &input);
    // free mem
    free_array2d(b, NX);

    printf("\n [*] Press a key to exit.\n\n");
    scanf("%s", &input);
    return 0;
}
