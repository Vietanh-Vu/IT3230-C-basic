#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = NULL;
    char arr[99][999];
    int i = 0;
    f = fopen("/home/manh/input.txt", "r");
    while (fgets(arr[i], 999, f) != NULL) {
        if (arr[i][strlen(arr[i]) - 1] == '\n')
            arr[i][strlen(arr[i]) - 1] = 0;
        printf("%ld %s\n", strlen(arr[i]), arr[i]);
        i++;
    }
    fclose(f);
    return 0;
}