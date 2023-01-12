#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256
#define MAX 100000

//////////////////////////////////////////////////
// Declare variables
typedef struct Profile{
    char name[256];
    char email[256];
} Profile;

Profile profiles[MAX];
int numProfile = 0;
char choice[MAX_L];
//////////////////////////////////////////////////
// Sort profile
// Swap function to swap two values
void swap(Profile *a, Profile *b) {
  Profile temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function to partition the array around the pivot
int partition(Profile array[], int low, int high) {
  Profile pivot = array[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (strcmp(profiles[j].name, pivot.name) < 0) { // array[j] < pivot
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return i + 1;
}

// Quicksort function to sort the array
void quicksort(Profile array[], int low, int high) {
  if (low < high) {
    int pivot_index = partition(array, low, high);

    quicksort(array, low, pivot_index - 1);
    quicksort(array, pivot_index + 1, high);
  }
}

//////////////////////////////////////////////////
// Load data from file 

void load(){
    FILE* f = fopen("studentProfile.txt","r");
    if(f == NULL) printf("Load data -> file not found\n");
    while(!feof(f)){
        char name[MAX_L], email[MAX_L];
        fscanf(f, "%s %s", &name, &email);
        strcpy(profiles[numProfile].name, name);
        strcpy(profiles[numProfile].email, email);
        numProfile++;
    }

    quicksort(profiles, 0, numProfile-1);
    fclose(f);
}

//////////////////////////////////////////////////
// find by name (return index)
int binarySearch(Profile array[], int size, char value[MAX_L]) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(array[mid].name, value) < 0) { //array[mid] < value
            low = mid + 1;
        } else if (strcmp(array[mid].name, value) > 0) { //array[mid] > value
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;  // value not found
}

int find() {
    char name[MAX_L];
    printf("Enter name: "); scanf("%s", &name);
    int result = binarySearch(profiles, numProfile, name);
    if (result == -1) printf("Cannot find student!\n");
    else {
        printf("Your student:\nName: %s\nEmail: %s\n", profiles[result].name, profiles[result].email);
    }
    return result;
}

//////////////////////////////////////////////////
// insert profile
void processInsert(){
    char name[256], email[256];
    printf("Enter name and email: \n");
    scanf("%s %s", &name, &email);
    numProfile++;
    strcpy(profiles[numProfile-1].name, name);
    strcpy(profiles[numProfile-1].email, email);
    quicksort(profiles, 0, numProfile-1);
}

//////////////////////////////////////////////////
// remove profile by name
void processRemove() {
    char name[MAX_L];
    int indexOfRemovePr = find(name);
    for (int i = indexOfRemovePr; i<numProfile-1; i++) {
        profiles[i] = profiles[i+1];
    }
    numProfile--;
}

//////////////////////////////////////////////////
// print to screen
void printList() {
    for (int i=0; i<numProfile; i++) {
        printf("%s %s\n", profiles[i].name, profiles[i].email);
    }
}

//////////////////////////////////////////////////
// store 
void processStore(){
    char filename[256];
    printf("Enter file name: "); scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for (int i = 0; i<numProfile; i++) {
        fprintf(f, "%s %s\n", profiles[i].name, profiles[i].email);
    }
    fclose(f);
}

//////////////////////////////////////////////////
// printf menu
void printfMenu() {
    printf("----------------------------\n");
    printf("1. Load data from file.\n"); //load()
    printf("2. Find student by name.\n"); // find()
    printf("3. Insert new profile.\n"); // processInsert()
    printf("4. Remove profile by name.\n"); // processRemove()
    printf("5. Store.\n"); // processStore()
    printf("6. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: "); scanf("%s", &choice);
    printf("----------------------------\n");
}

int main(){
    while(1){
        printf("Enter command: ");
        char cmd[256];
        scanf("%s",&cmd);
        if(strcmp(cmd,"Quit")==0){printf("Bye"); break;} 
            else if(strcmp(cmd,"Load")==0) load();
            else if(strcmp(cmd,"Print")==0) printList();
            else if(strcmp(cmd,"Find")==0) find();
            else if(strcmp(cmd,"Insert")==0) processInsert();
            else if(strcmp(cmd,"Remove")==0) processRemove();
            else if(strcmp(cmd,"Store")==0) processStore();
    }
    return 0;
}

