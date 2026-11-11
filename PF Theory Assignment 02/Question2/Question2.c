/*  Afnan Ahmed 
    BS AI - 1A
    26K - 0002
*/


#include <stdio.h>

// finds the sum of all divisors
int sumDivisors(int num) {
    int sum = 0;
    
    for (int i = 1; i < num - 1; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    printf("Enter a number \n");
    int n; scanf("%d", &n);

    int count = 0;
    
    // checks for pairs. Also loops through all numbers
    for (int i = 1; i <= n; i++) {
        for (int j  = i + 1; j <= n; j++) {
            
            if (sumDivisors(i) == j && sumDivisors(j) == i) {
                printf("Two paris found %d , %d \n", i, j);
                count++;
            } 
        }
    }

    // outputs the final statement
    (count == 0) ? printf("No pairs found \n") : printf("Total Pairs Found %d \n", count);
}