#include <stdio.h>
#include <string.h>

void main() {
    char s[999];
    FILE *f1 = fopen("lab1.txt", "w+b");
    FILE *f2 = fopen("lab1a.txt", "w+b");
    fwrite("Hello World!!!", sizeof(char), strlen("Hello World!!!"), f1);
    fclose(f1);
    f1 = fopen("lab1.txt", "rb");
    while (!feof(f1)) {
        fread(s, sizeof(char), 999, f1);
        fwrite(s, sizeof(char), strlen(s), f2);
    }
    fclose(f1);
    fclose(f2);
}