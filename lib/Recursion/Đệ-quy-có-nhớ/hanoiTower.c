#include<stdio.h>

void hanoi(int n, char source, char target, char auxiliary) {
    if (n>0) {
        hanoi(n-1, source, auxiliary, target);
        printf("Move %c to %c\n", source, target);
        hanoi(n-1, auxiliary, target, source);
    }
}

int main() {
    hanoi(3,'A','B','C');
    return 0;
}