#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_L 256

// initial nodelist 
typedef struct Profile {
    char name[MAX_L];  // ten sinh vien
    char email[MAX_L]; // email cua sinh vien
    struct Profile *prev;
    struct Profile *next;
} Profile;

Profile *first, *last;

int isEmptyList() {
    return first == NULL && last == NULL;
}

Profile *makeProfile (char name[MAX_L], char email[MAX_L]) {
    Profile *node = (Profile *)malloc(sizeof(Profile));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void *insertLast (char name[MAX_L], char email[MAX_L]) {
    Profile *node = makeProfile(name,email);
    if (isEmptyList()) {
        first = node;
        last = node;
    } else {
        node->prev = last;
        last->next = node;
        last = last->next;
    }
}

// initial global variable 
int choice;

// FUNCTION

// FUNCTION 1
void readData () {
    FILE *f;
    f = fopen("studentData.txt", "r");
    char name[MAX_L], email[MAX_L];
    while (!feof(f)) {
        fscanf(f, "%s %s\n", &name, &email);
        insertLast(name, email);
    }
    fclose(f);
    printf("\n\n");
}

// FUNCTION 2
void printProfileList () {
    Profile *currentStudent = first;
    int i = 1;
    while (currentStudent!= NULL) {
        printf("Student %d: \nName: %s\nEmail: %s\n\n", i, currentStudent->name, currentStudent->email);
        i++;
        currentStudent = currentStudent->next;
    }
}

// FUNCTION 3
void makeNewProfile () {
    char name[MAX_L], email[MAX_L];
    printf("Enter new profile: \n");
    printf("Name: "); scanf("%s", &name);
    printf("Email: "); scanf("%s", &email);
    insertLast(name,email);
}


// FUNCTION 5
Profile *findStudentByName () {
    char name[MAX_L];
    printf("Enter the student name: "); scanf("%s", &name);
    Profile *currentStudent = first;
    while (currentStudent != NULL) {
        if (strcmp(currentStudent->name, name) == 0) {
            printf("Your student: \n");
            printf("Name: %s\nEmail: %s\n\n",currentStudent->name, currentStudent->email);
            return currentStudent;
        }
        currentStudent = currentStudent->next;
    }
    printf("Cannot find student %s\n\n", name);
    return NULL;
}


// FUNCTION 4
Profile *deleteProfile() {
    Profile *deleteStudent = findStudentByName();
    Profile *currentStudent = first;

    // cannot find student
    if (deleteStudent == NULL) return first;

    // delete student is the first student in list 
    if (deleteStudent == currentStudent) { 
        first = first->next;
        first->prev = NULL;
        free(currentStudent);
        return first;
    } 
    currentStudent = currentStudent->next;
    
    // delete student in the middle of list 
    while (currentStudent != NULL && currentStudent != last) {
        if (currentStudent == deleteStudent) {
            Profile *left = currentStudent->prev;
            Profile *right = currentStudent->next;
            left->next = right;
            right->prev = left;
            free(currentStudent);
            return first;
        }
        currentStudent = currentStudent->next;
    }

    // delete student in the end of list 
    if (currentStudent == last && currentStudent == deleteStudent) {
        last = currentStudent->prev;
        last->next = NULL;
        free(currentStudent);
        return first;
    }
}

// FUNCTION 6
void save() {
    FILE *f;
    f = fopen("studentData.txt", "w");
    Profile *currentStudent = first;
    while (currentStudent != NULL) {
        fprintf(f,"%s %s\n", currentStudent->name, currentStudent->email);
        currentStudent = currentStudent->next;
    }
    fclose(f);
}


void printfMenu() {
    printf("----------------------------\n");
    printf("1. Read data from file.\n");
    printf("2. Print student list.\n");
    printf("3. Make new profile.\n");
    printf("4. Delete profile by name.\n");
    printf("5. Find student by name.\n");
    printf("6. Save.\n");
    printf("7. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: "); scanf("%d", &choice);
    printf("----------------------------\n");

}

int main() {
    do {
        printfMenu();
        switch (choice)
        {
        case 1:
            readData();
            break;
        case 2:
            printProfileList();
            break;
        case 3:
            makeNewProfile();
            break; 
        case 4:
            deleteProfile();
            break;         
        case 5:
            findStudentByName();
            break;   
        case 6:
            save();
            break;   
        case 7:
            printf("Exit!\n");
            break;
        default:
            printf("Invalid!\n");
            break;
        }

    } while(choice != 7);
    return 0;
}