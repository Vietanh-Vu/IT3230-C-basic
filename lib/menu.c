#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int choice;

void printMenu() {
    printf("\n-------------------------------------\n");
    printf("1. Doc file.\n");
    printf("2. Tim kiem theo ma chung khoan.\n");
    printf("3. Tim kiem nhung ma chung khoan co xu huong tang.\n");
    printf("4. Tim ma co so ngay tang lon nhat.\n");
    printf("5. Thoat chuong trinh.\n");
    printf("-------------------------------------\n");
    printf("Nhap lua chon (1-5): "); scanf("%d", &choice);
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
                printf("Vu Viet Anh 20215261\n");
                break;
            default:
                printf("Invalid!\n");
                break;
        }
    } while (choice!=5);
    return 0;
}