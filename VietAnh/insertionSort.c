#include<stdio.h>
#include<stdlib.h>


void insertionSort(int arr[], int numEl) {
    for (int i = 1; i<numEl; i++) {
        int key = arr[i];
        int j = i-1;

        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= key;
    }
}

int main() {
    int numEl;
    printf("Number of elements: "); scanf("%d", &numEl);
    int *arr = (int *)malloc(sizeof(int) * numEl);
    for (int i = 0; i<numEl; i++) {
        scanf("%d", &arr[i]);
    }

    printf("After sorting: \n");
    insertionSort(arr, numEl);
    for (int i = 0; i<numEl; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}