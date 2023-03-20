#include<stdio.h>

int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    return C(k, n-1) + C(k-1, n-1);
}

int main() {
    printf("%d\n", C(3,5));
    printf("%d\n", C(6,10));
    return 0;
}