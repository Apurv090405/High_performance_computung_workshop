#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
   int rank, n_ranks, neighbour;
   char send_message[50];  // Array to hold the message to be sent
   char recv_message[50];  // Array to hold the received message
   MPI_Status status;

   // First call MPI_Init
   MPI_Init(&argc, &argv);

   // Get my rank and the number of ranks
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &n_ranks);

   // Check that there are exactly two ranks
   if (n_ranks != 2) {
        printf("This example requires exactly two ranks\n");
        MPI_Finalize();
        return(1);
   }

   // Set the message to be sent
   if (rank == 0) {
      neighbour = 1;
      // Prepare the message "Hello Om" to send
      strcpy(send_message, "Hello 22AMIT016");

      // Send the message to the other rank
      MPI_Send(send_message, strlen(send_message) + 1, MPI_CHAR, neighbour, 0, MPI_COMM_WORLD);

      printf("Message '%s' sent by rank %d \n", send_message, rank);
   } else {
      neighbour = 0;

      // Receive the message from rank 0
      MPI_Recv(recv_message, 50, MPI_CHAR, neighbour, 0, MPI_COMM_WORLD, &status);

      // Print the received message
      printf("Message '%s' received by rank %d \n", recv_message, rank);
   }

   // Call finalize at the end
   MPI_Finalize();

   return 0;
}

