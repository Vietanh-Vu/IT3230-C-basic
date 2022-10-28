#include <stdio.h>

int main()
{
    double num;
    printf("Enter number: ");
    scanf("%lf", &num);
    printf("Integer: %d\n", (int)num);
    printf("Faction: %lf", num - (int)num);
    return 0;
}