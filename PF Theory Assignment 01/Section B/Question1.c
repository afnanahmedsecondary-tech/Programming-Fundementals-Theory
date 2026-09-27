#include <stdio.h>

int main() {

    int guests; printf("Enter Number of Guests \n");
    scanf("%d", &guests);

    int revenue = 0;

    while (guests > 0) {
        int season; printf("Enter 1 for Peak or 2 for Off Peak \n");
        scanf("%d", &season);
        
        int nights; printf("Enter number of nights \n");
        scanf("%d", &nights);
        
        int room_type; printf("Enter Room Type \n 1 for Standard \n 2 for Deluxe \n 3 for Suite \n");
        scanf("%d", &room_type);
        
        int total_price;
        int rate = 0;
        float discount = 1;



        if (season == 1) {

            if (room_type == 1) {
                rate = 5000;
            }
            else if (room_type == 2) {
                rate = 8000;
            }
            else 
                rate = 12000;
        }

        if (season == 2) {
            if (room_type == 1) {
                rate = 3000;
            }
            else if (room_type == 2) {
                rate = 5000;
            }
            else 
                rate = 8000;
        }

        if (nights > 7) {
            discount = 1 - 0.15;
            
        }

        total_price = discount * rate * nights;
        revenue += total_price;

        printf("Total Price %d \n", total_price);

        guests -= 1;

    }   

    printf("Total Revenue %d \n", revenue);
    return 0;

}