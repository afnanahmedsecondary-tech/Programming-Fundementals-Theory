#include <stdio.h>


int main() {
    int students; printf("Enter Number of Students\n");
    scanf("%d", &students);

    while (students > 0) {


        int sum = 0;
        int i  = 0;
        int defficency = 0;

        while (i < 5) {
            int marks = 0;
            printf("Enter Subject Marks");
            scanf("%i", &marks);

            if ( marks < 33) {
                defficency++;
            }
            sum += marks;
            i++;
        }


        float avg = sum  / 5.0;


        if ( defficency != 0) {
            printf("Fail — Subject Deficiency \n");
        }
        else if (avg >= 80) 
            printf("Distinction\n");
        
        else if (avg >= 60)
            printf("Pass\n");
        
        else 
            printf("Fail\n");

        students -= 1;
    }
}