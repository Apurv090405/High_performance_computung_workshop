#include <stdio.h>
#include <omp.h>

#define SIZE 100

int main(int argc, char* argv[])
{
    int tid, sum = 0;
    int numbers[SIZE]; // Array to store 100 numbers

    // Initialize the array with some values
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1; // Example initialization with values 1 to 100
    }

    int total_sum = 0;
    
    #pragma omp parallel private(tid) reduction(+:total_sum)
    {
        tid = omp_get_thread_num();
        
        // Parallel loop to sum up the numbers
        for (int i = 0; i < SIZE; i++) {
            total_sum += numbers[i];
        }
    }

    // Calculate the average
    float avg = (float)total_sum / SIZE;

    printf("Average = %.2f\n", avg);
    
    return 0;
}

