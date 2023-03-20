#include<stdio.h>
#include <string.h>
int A[100][100];

int C(int k, int n) {
    if (k == 0 || k == n) A[k][n] = 1;
    if (A[k][n] == 0) A[k][n] = C(k, n-1) + C(k-1, n-1);
    return A[k][n];
}

int main() {
    memset(A, 0, sizeof(A));
    printf("%d\n", C(6,10));
    return 0;
}