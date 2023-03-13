#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int choice;

void printMenu() {
    printf("\n-------------------------------------\n");
    printf("1. Name feature 1.\n");
    printf("2. Name feature 2.\n");
    printf("3. Name feature 3.\n");
    printf("4. Name feature 4.\n");
    printf("5. Name feature 5.\n");
    printf("-------------------------------------\n");
    printf("Enter your choice (1-5): "); scanf("%d", &choice);
    printf("-------------------------------------\n");
}

int main() {
    do {
        printMenu();
        switch (choice) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
            
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid!\n");
                break;
        }
    } while (choice!=5);
    return 0;
}
