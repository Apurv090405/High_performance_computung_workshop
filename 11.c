#include<stdio.h>
#include <omp.h>
#define N 10

int main() {
omp_set_num_threads(100);
double s = 0.0, a[N];
int i;
// initialize the array
for (i=0; i <N; i++){
  a[i] = i * 1.0;
}
#pragma omp parallel for
for (i=0 ; i<N ; ++i) 
{
s += a[i];
}

printf("s = %f \n", s);
}
