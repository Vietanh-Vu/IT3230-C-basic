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
// Heap sort 
void heapify(Profile arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && compareProfile(arr[l], arr[largest]) >= 0) //arr[l] > arr[largest]
        largest = l;

    if (r < n && compareProfile(arr[r], arr[largest]) >= 0) //arr[r] > arr[largest]
        largest = r;

    if (largest != i)
    {
        Profile temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(Profile arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        Profile temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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
    heapSort(profiles, numPros);
    printData(numPros);
    return 0;
}
