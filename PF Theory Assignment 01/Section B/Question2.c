#include <stdio.h>

int main() {

    int current_floor = 0;
    int requests; printf("Enter Number of Floor Requests \n");
    int requested_floor;
    scanf("%i", &requests);


    while (requests > 0 ) {
        
        printf("Enter Floor Number\n");
        scanf("%i", &requested_floor);

        if (requested_floor > current_floor ){
            printf("Moving Up\n");
        }

        else if (requested_floor < current_floor) {
            printf("Moving Down\n");
        }

        else 
            printf("Doors Opening\nope");

        current_floor = requested_floor;

        requests -= 1;
    }

    


}