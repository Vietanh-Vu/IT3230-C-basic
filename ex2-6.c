// initial value in address.txt --> 01 Dai Co Viet, Hai Ba Trung, hi loi.
// start = 30, end = 36
// after change --> 01 Dai Co Viet, Hai Ba Trung, Ha Noi.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // initial value
    FILE *f;
    f = fopen("address.txt", "r+");
    int start, end;
    printf("Input start: ");
    scanf("%d", &start);
    printf("Input end: ");
    scanf("%d", &end);
    int lengthOfLoad = end - start + 1;
    char *loadData = (char *)malloc((lengthOfLoad) * sizeof(char));

    // load data form start to end
    fseek(f, start, SEEK_SET);
    fgets(loadData, lengthOfLoad, f);
    printf("Load data: %s\n", loadData);

    // change data and save
    printf("Change load data: ");
    fflush(stdin);
    fgets(loadData, lengthOfLoad, stdin);
    fseek(f, start, SEEK_SET);
    fprintf(f, "%s", loadData);

    fclose(f);
    return 0;
}