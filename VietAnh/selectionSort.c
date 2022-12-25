#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

void selectionSort (int arr[], int numEl) {
    int i = 0;
    while (i<numEl) {
        int min = INT_MAX;
        int index = i;
        for (int j = i; j<numEl; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }

        // Swap min to top
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;

        i++;
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
    selectionSort(arr, numEl);
    for (int i = 0; i<numEl; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}