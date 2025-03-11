#include <stdio.h>
#include <omp.h>
#define N 10
int main() {
int i, a[N], b[N];
#pragma omp parallel sections private(i)
{
#pragma omp section
{
for (i=1 ; i<=N ; i++){
        a[i] = i*2;
        printf("Thread %d : %d \n",omp_get_thread_num(), a[i]);
        }
}
#pragma omp section
{
for (i=1 ; i<=N ; i++) {
        b[i] = i*4;
        printf("Thread %d : %d \n",omp_get_thread_num(), b[i]);
        }
}
}
}
