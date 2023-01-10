#include<stdio.h>
#include<stdlib.h>

int* randArray (int n, int m, int M) {
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        a[i] = m + rand() % (M - m + 1);
        printf("%d ", a[i]);
    }
    return a;
}

// Swap function to swap two values
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function to partition the array around the pivot
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (array[j] < pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return i + 1;
}

// Quicksort function to sort the array
void quicksort(int array[], int low, int high) {
  if (low < high) {
    int pivot_index = partition(array, low, high);

    quicksort(array, low, pivot_index - 1);
    quicksort(array, pivot_index + 1, high);
  }
}

int binarySearch(int a[], int L, int R, int Y)
{
    if (L > R)
        return 0;
    if (L == R)
        if (a[L] == Y)
            return 1;
        else
            return 0;
    int m = (L + R) / 2;
    if (a[m] == Y)
        return 1;
    if (a[m] > Y)
        return binarySearch(a, L, m - 1, Y);
    return binarySearch(a, m + 1, R, Y);
}

int main () {
    // initial value
    int n, M, count = 0;
    scanf("%d %d", &n, &M);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort
    quicksort(arr, 0, n-1);

    for (int i = 0; i<n; i++) {
      int key = M - arr[i];
      if (binarySearch(arr, i+1, n-1, key) == 1) {
          count ++;
      }
    }

    printf("%d", count);
    
    return 0;
}