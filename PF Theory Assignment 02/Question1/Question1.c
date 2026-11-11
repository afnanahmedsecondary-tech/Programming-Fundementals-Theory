/*  Afnan Ahmed 
    BS AI - 1A
    26K - 0002
*/

#include <stdio.h>

int main() {
    int rows; printf("Print Number of Seating Rows \n"); scanf("%d", &rows);
    int seats; printf("Enter Numbr of Seats per Row \n"); scanf("%d", &seats);
    
    int seat_arrangement[rows][seats];
    

    // enter status of each Row 0 & 1
    printf("Enter Seating Arrangement \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < seats; j++) {
            scanf("%d", &seat_arrangement[i][j]);
        }
    }


    // Displaying  Arrangement
    
    printf("Seat: ");
    for (int i =0; i < seats; i++) printf("%d ", i);
    printf("\n");


    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);

        for (int j = 0; j < seats; j++) {
            if (seat_arrangement[i][j] == 0) printf("_ ");
            else printf("X ");
        }
        printf("\n");
    }

    // Displaying Seating Plan
    int total = 0;
    for (int i =0; i < rows; i++) {

        printf("Rows: %d ", i );
        int count = 0;
        for (int j = 0; j < seats; j++) {
            if (seat_arrangement[i][j] == 0) {count++; total++;}
        }
        printf("%d are available \n", count);
    }
    printf("Total Number of Available Seats: %d \n", total);


  // Group Booking Logic
    int k;
    printf("Enter Number of Customers: ");
    scanf("%d", &k);

    if (k > seats || k <= 0) {
        printf("Invalid Size\n");
        return -1;
    }
    else {

        int found = 0;
        int startSeat = 0;
        int row = 0;
        int middle = rows / 2;

        for (int d = 0; d < rows && found == 0; d++) {

            int left = middle - d;
            int right = middle + d;

            // Search left row first
            if (left >= 0) {

                int consecutive = 0;

                for (int j = 0; j < seats; j++) {

                    if (seat_arrangement[left][j] == 0)
                        consecutive++;
                    else
                        consecutive = 0;

                    if (consecutive == 1)
                        startSeat = j;

                    if (consecutive == k) {
                        row = left;
                        found = 1;
                        break;
                    }
                }
            }

            // Search right row
            if (right < rows  && found == 0) {

                int consecutive = 0;

                for (int j = 0; j < seats; j++) {

                    if (seat_arrangement[right][j] == 0)
                        consecutive++;
                    else
                        consecutive = 0;

                    if (consecutive == 1)
                        startSeat = j;

                    if (consecutive == k) {
                        row = right;
                        found = 1;
                        break;
                    }
                }
            }
        }

        // Confirming Booking
        if (found == 1) {

            printf("Seats Booked \n");
            printf("Allocated Row: %d\n", row);
            printf("Allocated Seats: ");

            for (int p = startSeat; p < startSeat + k; p++) {
                printf("%d ", p);
                seat_arrangement[row][p] = 1;
            }

            printf("\n");
        }
        else {
            printf("No suitable consecutive seats found!\n");
        }
    }
    
    // Final Seating Arrangement
    printf("Seat: ");
    for (int i =0; i < seats; i++) printf("%d ", i);
    printf("\n");


    for (int i = 0; i < rows; i++) {
        printf("Row %d: ", i);

        for (int j = 0; j < seats; j++) {
            if (seat_arrangement[i][j] == 0) printf("_ ");
            else printf("X ");
        }
        printf("\n");
    }
    printf("Total Number of Seats %d /n", total - k);
}