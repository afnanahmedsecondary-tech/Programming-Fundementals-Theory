/*  Afnan Ahmed 
    BS AI - 1A
    26K - 0002
*/


#include <stdio.h>


// Function for taking hourly readings
void inputReadings(int hourlyReading, int arr[][hourlyReading], int sensor) {
    printf("Enter hourly Reading \n");
    for (int i = 0; i < sensor; i++) {
        for (int j = 0; j < hourlyReading; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}


// Function for analyzing Sensor
void analyzeSensor(int hourlyReading, int arr[][hourlyReading], int sensor) {
    float total = 0.0;  int count = 0;
    int highest = arr[sensor][0];
    int lowest = arr[sensor][0];

    int critical = 0; int warning = 0;

    int streak = 0; int maxStreak = 0;

    for (int j = 0; j < hourlyReading; j++) {

        if (highest < arr[sensor][j]) highest = arr[sensor][j];
        if (lowest > arr[sensor][j]) lowest = arr[sensor][j];

        if (arr[sensor][j] >= 40) critical++;

        if (arr[sensor][j] >= 35 && arr[sensor][j] <= 39) warning++;

        if (arr[sensor][j] >= 35) {
            streak++;
        }
        else {
            if (maxStreak < streak) maxStreak = streak;
            streak = 0;
        }

        total += arr[sensor][j];
        count++;
    }

    if (maxStreak < streak) maxStreak = streak;

    

    printf("Highest Temp %d \n", highest);
    printf("Lowest Temp %d \n", lowest);
    printf("Total Temperature %f \n", total);
    printf("Avg Temp: %.2f \n", total / count);
    printf("Critical Count: %d \n", critical);
    printf("Warning Count: %d \n", warning);
    printf("Max Streak: %d \n", maxStreak);
}


//Function to Find Highest Average
int highestAverage(int hourlyReading, int arr[][hourlyReading], int sensor){
    float highest_avg; int index;
    
    for (int i = 0; i < sensor; i++) {

        float total = 0.0; int count = 0;

        for (int j = 0; j < hourlyReading; j++) {
            total += arr[i][j]; count++;
        }
        if (highest_avg < total / count) {
            highest_avg = total / count;
            index = i;
        }
    }

    return index;
}


int main() {
    int sensor; printf("Enter Number of Sensors \n"); scanf("%d", &sensor);
    int hourlyReading; printf("Enter Hourly Reading \n"); scanf("%d", &hourlyReading);

    int temperature[sensor][hourlyReading];


    inputReadings(hourlyReading, temperature, sensor);

    for (int i = 0; i < sensor; i++) {
        analyzeSensor(hourlyReading, temperature, i);
    }

    int final = highestAverage(hourlyReading, temperature, sensor);

    float total = 0.0;
    for (int i= 0; i < hourlyReading; i++) {
        total += temperature[final][i];
    }
    
    printf("Sensor with highet reading at %d with avg of %.2f \n", final, total / hourlyReading);



}
