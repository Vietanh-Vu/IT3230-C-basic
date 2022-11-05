#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f = fopen("out.txt", "w");
    int n, sum = 0;
    int *arr = (int *)malloc(n * sizeof(int));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        fprintf(f, "%d ", arr[i]);
    }
    fprintf(f, "%d", sum);
    fclose(f);
    return 0;
}