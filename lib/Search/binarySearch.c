#include<stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch (int arr[], int key, int left, int right) {
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key) right = mid - 1;
        if (arr[mid] < key) left = mid + 1;
    }
    return -1;
}

int main () {
    int arr[] = {3,6,4,9,2,3,7,5,9,1,0};
    quickSort(arr, 0, 10);
    int key;
    printf("Enter key: "); scanf("%d", &key);
    if (binarySearch(arr, key, 0, 10) != -1) printf("Founded!");
    else printf("Not found!");
    return 0;
}