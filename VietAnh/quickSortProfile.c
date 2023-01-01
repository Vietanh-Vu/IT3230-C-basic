#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////
// Structure profile
typedef struct {
    char surname[1024];
    char middle[1024];
    char name[1024];
    char dob[1024]; 
}Profile;

Profile profiles[1024];

//////////////////////////////////////////////////
// Compare profile 

int compareProfile(Profile p1, Profile p2) {
    int result = strcmp(p1.name, p2.name);
    if (result == 0) result = strcmp(p1.middle, p2.middle);
    if (result == 0) result = strcmp(p1.surname, p2.surname);
    if (result == 0) result = strcmp(p1.dob, p2.dob);
    return result;
}



///////////////////////////////////////////
// quick sort 
void swap (Profile *a, Profile *b) {
    Profile tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(Profile A[], int L, int R, int indexPivot) {
    Profile pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(compareProfile(A[i], pivot) < 0){ //A[i] < pivot
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quickSort(Profile A[], int L, int R) {
    if(L < R){
        int index = (L + R)/2;
        index = partition(A, L, R, index);
        if(L < index) quickSort(A, L, index-1);
        if(index < R) quickSort(A, index+1, R);
    }
}



//////////////////////////////////////////////////
// Read data form file

int readData () {
    FILE *f = fopen("Profile.txt", "r");
    int numPros = 0;
    char line[1024];
    int isName = 1; // Flag to track whether the line is a name or a date of birth

    while (1) {
        fscanf(f, "%s %s %s\n", profiles[numPros].surname, profiles[numPros].middle, profiles[numPros].name);
        if (strcmp(profiles[numPros].surname, "#") == 0) return numPros;
        fgets(line, 1024, f);
        strcpy(profiles[numPros].dob, line);
        numPros++;
    }
    fclose(f);
    return numPros;
}


//////////////////////////////////////////////////
// Print data form file

void printData (int numPros) {
    FILE *f = fopen("Profile-sorted.txt", "w");
    char line[1024];

    for (int i = 0; i<=numPros; i++) {
        fprintf(f, "%s %s %s\n", profiles[i].surname, profiles[i].middle, profiles[i].name);
        fprintf(f, "%s", profiles[i].dob);
    }
    fclose(f);
}


int main() {
    // printf("%d\n", strcoll("Do Duc Bang", "Pham Viet Anh"));
    int numPros = readData();
    quickSort(profiles, 0, numPros-1);
    printData(numPros);
    return 0;
}
