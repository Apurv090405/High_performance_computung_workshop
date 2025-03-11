#include<stdio.h>
#include <omp.h>
#define N 10

int main() {
double s = 0.0, a[N], s_local;
int i;
// initialize the array
for (i=0; i < N; i++){
  a[i] = i * 1.0;
}
#pragma omp parallel private(i, s_local) 
{
#pragma omp for
for (i=0 ; i<N ; ++i)
{
s_local += a[i];
}
#pragma omp atomic
s += s_local;
}
printf("s = %f \n", s);
}
