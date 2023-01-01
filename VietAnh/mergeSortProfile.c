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
// Merge sort 

// Function to merge two subarrays of arr[]
void merge(Profile arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    Profile L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (compareProfile(L[i], R[j]) <= 0) //L[i] <= R[j]
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(Profile arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    mergeSort(profiles, 0, numPros-1);
    printData(numPros);
    return 0;
}
