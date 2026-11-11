/*  Afnan Ahmed 
    BS AI - 1A
    26K - 0002
*/

#include <stdio.h>


// function for menu
void displayMenu() {
    printf("\n===== UNIVERSITY LIBRARY MENU =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}



void registerMember(char memberName[], int *id, int *type) {
    printf("Enter name: "); scanf(" %49[^\n]", memberName);

    printf("Enter student ID: "); scanf("%d", id);

    printf("Enter membership type (1 = Student, 2 = Faculty): "); scanf("%d", type);


    while (*type != 1 && *type != 2) {
        printf("Invalid membership type! Enter 1 for Student or 2 for Faculty: ");
        scanf("%d", type);
    }

    printf("Member registered successfully.\n");
}


// function for display
void displayBooks(int IDs[], char titles[][50], int copies[], int bookCount) {
    int index;
    printf("\n%-6s %-25s %s\n", "ID", "Title", "Copies");

    printf("------------------------------------------\n");

    for (index = 0; index < bookCount; index++)
        printf("%-6d %-25s %d\n", IDs[index], titles[index], copies[index]);
}


// function for borrowing books
void borrowBook(int IDs[], char titles[][50], int copies[], int bookCount,
    int borrowedIDs[], int *borrowedCount, int type) {
    int enteredID, keepingDays, index, bookIndex = -1;
    
    int borrowingLimit = (type == 1) ? 14 : 30;

    if (*borrowedCount >= 3) {
        printf("Borrowing limit reached! You can borrow a maximum of 3 books at a time.\n");
        return;
    }


    printf("Enter book ID: "); scanf("%d", &enteredID);


    for (index = 0; index < bookCount; index++)
         if (IDs[index] == enteredID) bookIndex = index;


    if (bookIndex == -1) {
        printf("Invalid book ID!\n");
        return;
    }


    if (copies[bookIndex] == 0) {
        printf("Sorry no copies of \"%s\" are available.\n", titles[bookIndex]);
        return;
    }


    printf("Enter number of days: "); scanf("%d", &keepingDays);


    while (keepingDays <= 0) {
        printf("Invalid Days! Enter again: ");
        scanf("%d", &keepingDays);
    }



    borrowedIDs[(*borrowedCount)++] = enteredID;
    copies[bookIndex]--;
    printf("You have borrowed \"%s\". Permitted period: %d days.\n", titles[bookIndex], borrowingLimit);


    if (keepingDays > borrowingLimit)
        printf("Note: the intended period exceeds the permitted %d days; fines apply after %d days.\n", 
            borrowingLimit, borrowingLimit);
}



float returnBook(int IDs[], int copies[], int bookCount, int borrowedIDs[],
    int *borrowedCount, int type, float *totalFine) {


    int enteredID, keepingDays, index, borrowedIndex = -1, bookIndex = -1;
    int extraDays, borrowingLimit, fineRate;

    char enteredCode[20], correctCode[] = "LIB2026";

    float fineAmount = 0;

    printf("Enter book ID to return: "); scanf("%d", &enteredID);


    for (index = 0; index < *borrowedCount; index++)
        if (borrowedIDs[index] == enteredID) borrowedIndex = index;


    if (borrowedIndex == -1) {
        printf("You have not borrowed this book!\n");
        return 0;
    }


    printf("Enter actual number of days the book was kept: "); scanf("%d", &keepingDays);


    while (keepingDays <= 0) {
        printf("Invalid Days! Enter again: ");
        scanf("%d", &keepingDays);
    }

    for (index = 0; index < bookCount; index++)
        if (IDs[index] == enteredID) bookIndex = index;


    copies[bookIndex]++;

    borrowingLimit = (type == 1) ? 14 : 30;

    fineRate = (type == 1) ? 20 : 10;


    if (keepingDays > borrowingLimit) {

        extraDays = keepingDays - borrowingLimit;
        fineAmount = (float)extraDays * fineRate;

        printf("Book returned late by %d day(s). Late fine: Rs. %.2f\n", extraDays, fineAmount);
        *totalFine += fineAmount;

        printf("Enter membership code: "); scanf("%19s", enteredCode);


        for (index = 0; correctCode[index] != '\0' && enteredCode[index] == correctCode[index]; index++);
        
        if (correctCode[index] == '\0' && enteredCode[index] == '\0') {
            fineAmount /= 2;
            printf("Correct code! 50%% waiver applied.\n");
        } 
        else printf("Incorrect code. No waiver applied.\n");
        
        printf("Fine payable for this return: Rs. %.2f\n", fineAmount);

    } 
    
    else printf("Book returned on time. No fine.\n");
    

    for (index = borrowedIndex; index < *borrowedCount - 1; index++)
        borrowedIDs[index] = borrowedIDs[index + 1];

    (*borrowedCount)--;

    return fineAmount;
}

void displayMemberRecord(char memberName[], int id, int type, int borrowedIDs[],
    int borrowedCount, float totalFine, float payableFine) {


    int index;
    printf("\n===== MEMBER RECORD =====\n");
    printf("Name: %s\n", memberName);
    printf("Student ID: %d\n", id);

    printf("Membership Type: %s\n", (type == 1) ? "Student" : "Faculty");

    printf("Currently borrowed books:");

    if (borrowedCount == 0) printf(" None");


    for (index = 0; index < borrowedCount; index++) printf(" %d", borrowedIDs[index]);


    printf("\nTotal fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable: Rs. %.2f\n", payableFine);
}

int main() {
    int IDs[4] = {101, 102, 103, 104};
    char titles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int copies[4] = {5, 3, 0, 4};
    int bookCount = 4;

    char memberName[50] = "";
    int studentID = 0, memberType = 0, isRegistered = 0;
    int borrowedIDs[3], borrowedCount = 0;
    float totalFine = 0, payableFine = 0;
    int menuChoice;

    do {
        displayMenu();
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                if (isRegistered)
                    printf("A member is already registered.\n");
                else {
                    registerMember(memberName, &studentID, &memberType);
                    isRegistered = 1;
                }
                break;


            case 2:
                displayBooks(IDs, titles, copies, bookCount);
                break;


            case 3:
                if (!isRegistered) printf("Please register a member first.\n");
                else borrowBook(IDs, titles, copies, bookCount,
                                borrowedIDs, &borrowedCount, memberType);
                break;


            case 4:
                if (!isRegistered) printf("Please register a member first.\n");
                else payableFine += returnBook(IDs, copies, bookCount,
                                                   borrowedIDs, &borrowedCount, memberType, &totalFine);
                break;


            case 5:
                if (!isRegistered) printf("Please register a member first.\n");
                else displayMemberRecord(memberName, studentID, memberType, borrowedIDs,
                                         borrowedCount, totalFine, payableFine);
                break;


            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    } while (menuChoice != 6);
    return 0;
}