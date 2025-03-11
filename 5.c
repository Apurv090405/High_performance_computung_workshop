#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
int tid, sum=5 ;
#pragma omp parallel private(sum) 
{
  tid = omp_get_thread_num();
  sum = sum + tid;
  printf("Value at thread %d = %d \n", tid, sum) ;
}

printf("Value After parallel region, thread %d = %d \n", omp_get_thread_num(), sum) ;
}
