#include <stdio.h>

int main()
{
    int n, m, M;
    printf("Number of elements: ");
    scanf("%d", &n);
    printf("Min: ");
    scanf("%d", &m);
    printf("Max: ");
    scanf("%d", &M);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = m + rand() % (M - m + 1);
        printf("%d ", a[i]);
    }

    FILE *f;
    f = fopen("randArr.txt", "w");
    fprintf(f, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d ", a[i]);
    }

    fclose(f);

    return 0;
}