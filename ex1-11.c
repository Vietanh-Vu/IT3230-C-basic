#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = NULL;
    char fileName[999];
    char arr[99][999];
    int i = 0;
    printf("Input file name: "); scanf("%s", fileName);
    f = fopen(fileName, "r");
    while (fgets(arr[i], 999, f) != NULL) {
        if (arr[i][strlen(arr[i]) - 1] == '\n')
            arr[i][strlen(arr[i]) - 1] = 0;
        printf("%d %s\n", i + 1, arr[i]);
        i++;
    }
    fclose(f);
    return 0;
}