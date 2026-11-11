/*  Afnan Ahmed 
    BS AI - 1A
    26K - 0002
*/

#include <stdio.h>


// Validationa & input of Festival Days
int getValidDays() {
    int festivalDays; printf("Enter Festival Days \n");
    scanf("%d", &festivalDays);

    while (festivalDays < 1 || festivalDays > 7) {
        printf("Enter Again \n");
        scanf("%d", &festivalDays);
    }

    return festivalDays;
}

// returns total sales of a particular day
float calculateDailySales(int dayNumber) {
    printf("Current Day Nunber %d \n", dayNumber);

    int order; printf("Enter Numebr of orders: ");
    scanf("%d", &order); printf("\n");

    float total = 0.0; float highest = 0.0; 
    float amount = 0.0;
    
    for (int i = 0; i < order; i++) {
        printf("Enter Amount: ");
        scanf("%f", &amount);

        while (amount <= 0) {
            printf("Enter Again");
            scanf("%f", &amount);
        } 

        total += amount;

        if (highest < amount) highest = amount;
    }

    printf("Highest Order amount: %.2f \n", highest );
    printf("Total Sales: %.2f \n", total);
    printf("Average Order Amount %.2f \n", total / order );
    return total;


}

int findHighestSalesDay(float dailySales[], int numDays) {
    int index = 0; float max = dailySales[0];

    for (int i = 0; i < numDays; i++) {
        if (dailySales[i] > max) {
            max = dailySales[i]; index = i;
        }
    }
    
    return index+1;
}

// function to display;
void displayBarChart(float dailySales[], int numDays) {
    

    for (int i = 0; i < numDays; i++) {
        int num = dailySales[i] / 100;
        
        printf("Day %d: ", i);
        for (int j = 0; j < num; j++) {
            printf("*");
        }
        printf("\n");
    }
}



int main() {
    int days = getValidDays();
    
    float dailySales[7];
    float total = 0.0;


    for (int i = 0; i < days; i++) {
        dailySales[i] = calculateDailySales(i+1);
        total += dailySales[i];
    }

    int ans = findHighestSalesDay(dailySales, days);

    printf("Total Sales are %.2f \n", total);
    printf("Highest Sales Day is %d \n", ans);
    
    displayBarChart(dailySales, days);

    return 0;



}