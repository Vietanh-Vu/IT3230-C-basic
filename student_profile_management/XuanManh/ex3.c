#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct Profile{
    char name[256];
    char email[256];
    struct Profile* next;
} Profile;

Profile *first = NULL;

Profile *makeProfile(char *name, char *email) {
    Profile *p = (Profile*)malloc(sizeof(Profile));
    strcpy(p->name, name);
    strcpy(p->email, email);
    p->next = NULL;
    return p;
}

Profile *insertLast(Profile* h, char *name, char *email){
    Profile* p = h;
    if(h == NULL){
        return makeProfile(name, email);
    }
    while(p->next != NULL)
        p = p->next;
    Profile* q = makeProfile(name, email);
    p->next = q;
    return h;
}

void inputFromFile(char *fileName) {
    char name[256];
    char email[256];
    FILE *f = fopen(fileName, "r");
    while (fgets(name, 256, f) != NULL) {
        __fpurge(stdin);
        fgets(email, 256, f);
        __fpurge(stdin);
        if (name[strlen(name) - 1] == '\n')
            name[strlen(name) - 1] = 0;
        if (email[strlen(email) - 1] == '\n')
            email[strlen(email) - 1] = 0;
        first = insertLast(first, name, email);
    }
    fclose(f);
}

void printProfiles() {
    Profile *p = first;
    do {
        printf("Name: %s\n", p->name);
        printf("Email: %s\n\n", p->email);
        p = p->next;
    } while(p != NULL);
}

void addProfile(char *name, char *email) {
    first = insertLast(first, name, email);
}

void deleteProfile(char *name) {
    Profile *p = first;
    Profile *q =NULL;
    if (strcmp(p->name, name) == 0) 
        first = first->next;
    else {
        while (1) {
            q = p->next;
            if (strcmp(q->name, name) == 0) {
                p->next = q->next;
                break;
            } else {
                p = q;
            }
        }
    }
}

void findProfile(char *name) {
    Profile *p = first;
    while (strcmp(p->name, name) != 0) {
        p = p->next;
    }
    printf("The profile of %s is: \n", name);
    printf("Name: %s\n", p->name);
    printf("Email: %s\n", p->email);
}

void saveProfiles(char *fileName) {
    Profile *p = first;
    FILE *f = fopen(fileName, "w+");
    do {
        fprintf(f, "%s\n", p->name);
        fprintf(f, "%s\n", p->email);
        p = p->next;
    } while (p != NULL);
    fclose(f);
}

void printMenu() {
    printf("1.Đọc dữ liệu từ file văn bản vào danh sách\n");
    printf("2.In danh sách sinh viên\n");
    printf("3.Thêm 1 hồ sơ\n");
    printf("4.Xóa 1 hồ sơ\n");
    printf("5.Tìm kiếm hồ sơ\n");
    printf("6.Lưu hồ sơ vào file văn bản\n");
    printf("7.Thoát\n");
}

void main() {
    bool exit = false;
    int choice;
    char fileName[256], name[256], email[256];
    char isContinue = 'y';
    while (!exit) {
        if (isContinue == 'y')
            printMenu();
        else 
            exit = true;
        printf("Chọn chức năng: "); scanf("%d", &choice); __fpurge(stdin);
        printf("\n");
        switch (choice) {
            case 1: {
                printf("ĐỌC DỮ LIỆU TỪ FILE \n\n");
                printf("Nhập tên file: "); scanf("%s", fileName); __fpurge(stdin);
                inputFromFile(fileName);
            }
                break;
            case 2: {
                printf("DANH SÁCH SINH VIÊN:\n\n");
                printProfiles();
            }
                break;
            case 3: {
                printf("THÊM 1 HỒ SƠ: \n\n");
                printf("Name: "); fgets(name, 256, stdin); name[strlen(name) - 1] = 0; __fpurge(stdin);
                printf("Email: "); fgets(email, 256, stdin); email[strlen(email) - 1] = 0; __fpurge(stdin);
                addProfile(name, email);
            }
                break;
            case 4: {
                printf("XÓA 1 HỒ SƠ: \n\n");
                printf("Nhập tên của hồ sơ muốn xóa: "); fgets(name, 256, stdin); name[strlen(name) - 1] = 0; __fpurge(stdin);
                deleteProfile(name);
            } 
                break;
            case 5: {
                printf("TÌM KIẾM HỒ SƠ: \n\n");
                printf("Nhập tên của hồ sơ muốn tìm kiếm: "); fgets(name, 256, stdin); name[strlen(name) - 1] = 0; __fpurge(stdin);
                findProfile(name);
            }
                break;
            case 6: {
                printf("LƯU HỒ SƠ VÀO FILE: \n\n");
                printf("Nhập tên file: "); scanf("%s", fileName); __fpurge(stdin);
                saveProfiles(fileName);
            } 
                break;
            case 7: {
                exit = true;
            }
                break;
        }
        __fpurge(stdin);
        if (!exit) {
            printf("Tiếp tục ? (y/n): "); scanf("%c", &isContinue); __fpurge(stdin);
        }
    }
    free(first);
}