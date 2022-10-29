#include <stdio.h>

int main()
{
    double a, b;
    printf("Enter your height: ");
    scanf("%lf", &a);
    printf("Enter your width: ");
    scanf("%lf", &b);
    printf("Rectangle area: %lf\n", a * b);
    printf("Rectangle perimeter: %lf", (a + b) * 2);
    return 0;
}