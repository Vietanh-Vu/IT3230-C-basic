#include<stdio.h>

int f(int i) {
    if (i==0 || i==1) return 1;
    return f(i-1) + f(i-2);
}

int main() {
    for (int i=0; i<=20; i++) {
        printf("f(%d) = %d\n", i, f(i));
    }
    return 0;
}