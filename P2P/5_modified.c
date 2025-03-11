#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, n_ranks, neighbour;
    int n_numbers = 1000000000;
    int *send_message;
    int *recv_message;
    MPI_Status status;

    send_message = malloc(n_numbers * sizeof(int));
    recv_message = malloc(n_numbers * sizeof(int));

    // First call MPI_Init
    MPI_Init(&argc, &argv);

    // Get my rank and the number of ranks
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n_ranks);

    // Check that there are exactly 4 ranks
    if (n_ranks != 4) {
        printf("This example requires exactly four ranks\n");
        MPI_Finalize();
        return(1);
    }

    // Print the rank and size of the communicator
    printf("Rank %d of %d processes.\n", rank, n_ranks);

    // Generate numbers to send
    for (int i = 0; i < 5; i++) {  // Print only first 5 numbers for brevity
        send_message[i] = i * i * i * i * i * i;
    }

    // Sending and receiving messages between neighbors
    // Adjust the neighbors based on the rank
    if (rank == 0) {
        neighbour = 1;
        MPI_Send(send_message, 5, MPI_INT, neighbour, 0, MPI_COMM_WORLD);  // Send only 5 elements
        printf("Rank %d: Sent message to Rank %d: ", rank, neighbour);
        for (int i = 0; i < 5; i++) {
            printf("%d ", send_message[i]);
        }
        printf("\n");
    } else if (rank == 1) {
        neighbour = 2;
        MPI_Recv(recv_message, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);  // Receive only 5 elements
        printf("Rank %d: Received message from Rank %d: ", rank, 0);
        for (int i = 0; i < 5; i++) {
            printf("%d ", recv_message[i]);
        }
        printf("\n");
        MPI_Send(send_message, 5, MPI_INT, neighbour, 0, MPI_COMM_WORLD);  // Send only 5 elements
        printf("Rank %d: Sent message to Rank %d: ", rank, neighbour);
        for (int i = 0; i < 5; i++) {
            printf("%d ", send_message[i]);
        }
        printf("\n");
    } else if (rank == 2) {
        neighbour = 3;
        MPI_Recv(recv_message, 5, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);  // Receive only 5 elements
        printf("Rank %d: Received message from Rank %d: ", rank, 1);
        for (int i = 0; i < 5; i++) {
            printf("%d ", recv_message[i]);
        }
        printf("\n");
        MPI_Send(send_message, 5, MPI_INT, neighbour, 0, MPI_COMM_WORLD);  // Send only 5 elements
        printf("Rank %d: Sent message to Rank %d: ", rank, neighbour);
        for (int i = 0; i < 5; i++) {
            printf("%d ", send_message[i]);
        }
        printf("\n");
    } else if (rank == 3) {
        MPI_Recv(recv_message, 5, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);  // Receive only 5 elements
        printf("Rank %d: Received message from Rank %d: ", rank, 2);
        for (int i = 0; i < 5; i++) {
            printf("%d ", recv_message[i]);
        }
        printf("\n");
    }

    // Call finalize at the end
    free(send_message);
    free(recv_message);

    return MPI_Finalize();
}
