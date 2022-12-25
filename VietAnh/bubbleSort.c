#include<stdio.h>
#include<stdlib.h>


void bubbleSort(int arr[], int numEl) {
    int i, j;
    for (i = 0; i < numEl-1; i++) {
        for (j = 0; j < numEl-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
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
    bubbleSort(arr, numEl);
    for (int i = 0; i<numEl; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}