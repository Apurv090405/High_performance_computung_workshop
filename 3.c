#include <stdio.h>
#include <omp.h>
int main(int argc, char* argv[])
{
     omp_set_num_threads(2) ;
     #pragma omp parallel
     printf("Hello How are you?, I am thread = %d\n", omp_get_thread_num()) ;
}
