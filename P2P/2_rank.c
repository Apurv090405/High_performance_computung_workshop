#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)
{

int rank;

MPI_Init(&argc, &argv);

// Get my rank*
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
printf("My rank is %d\n", rank);

MPI_Finalize();

}
