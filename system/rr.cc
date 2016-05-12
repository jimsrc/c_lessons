/* system example : DIR */
#include <mpi.h>	// (**1) 
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

int main (int argc, char* argv[])
{
    int w_rank, w_size;
	// -------------------------------------- iniciamos Open MPI
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &w_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &w_size);

    int i;
    char syscommand[4000];
    //sprintf(syscommand, "echo \"%s\" | gnuplot -persist", gnucommand);
    printf(" I'm %d\n", w_rank);
    sprintf(syscommand, "python tt.py %d", w_rank);
    i=system (syscommand);

	MPI_Finalize();
    return 0;
}
