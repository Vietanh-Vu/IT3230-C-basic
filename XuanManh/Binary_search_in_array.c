#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int A[], int i, int N)
{
    int L = 2 * i;
    int R = 2 * i + 1;
    int max = i;
    if (L <= N && A[L] > A[i])
        max = L;
    if (R <= N && A[R] > A[max])
        max = R;
    if (max != i)
    {
        swap(&A[i], &A[max]);
        heapify(A, max, N);
    }
}

void buildHeap(int A[], int N)
{
    for (int i = N / 2; i >= 1; i--)
        heapify(A, i, N);
}

void heapSort(int A[], int N)
{
    buildHeap(A, N);
    for (int i = N; i > 1; i--)
    {
        swap(&A[1], &A[i]);
        heapify(A, 1, i - 1);
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

void binarySearchSolve(int a[], int n, int Q)
{
    heapSort(a, n);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int ok = binarySearch(a, i + 1, n, Q - a[i]);
        cnt += ok;
    }
    printf("%d", cnt);
}

int main()
{
    int a[1000000], n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    binarySearchSolve(a, n, q);
    return 0;
}