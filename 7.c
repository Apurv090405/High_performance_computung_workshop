#include <stdio.h>
#include <omp.h>

#define NUM_ELEMENTS 100

int main(int argc, char* argv[]) {
    int tid, sum = 5;
    int array[NUM_ELEMENTS];  // Array of numbers to sum
    // Initialize the array
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        array[i] = i + 1; // Sample values: 1, 2, 3, ..., 100
    }

    // Parallel region to compute sum for each thread
    #pragma omp parallel firstprivate(sum)
    {
        tid = omp_get_thread_num();
        int avg = 0;  // Initialize avg to 0 for each thread
        for (int i = 0; i < NUM_ELEMENTS; i++) {
            avg += array[i];  // Sum the array elements
        }
        printf("Value at thread %d = %d \n", tid, avg);
    }

    // This will print the sum value after the parallel region (note: sum is unchanged here)
    printf("Value After parallel region, thread %d = %d \n", omp_get_thread_num(), sum);

    return 0;
}
