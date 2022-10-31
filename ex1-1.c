#include <stdio.h>
#include <string.h>

int main() {
    char line[999];
    int count[999];
    int i;
    printf("Input a line: "); 
    fgets(line, 999, stdin);
    line[strlen(line) - 1] = 0;
    for (i = 0; i < 999; i++) {
        count[i] = 0;
    }
    for (i = 0; i < strlen(line); i++) {
        count[line[i]]++;
    }
    for (i = 0; i < 999; i++) {
        if (count[i] != 0) {
            printf("The letter '%c' appears %d times(s).\n", i, count[i]);
        }
    }
    return 0;
}