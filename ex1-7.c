#include <stdio.h>

int main()
{
    FILE *input, *output;
    input = fopen("lab1.txt", "r");
    output = fopen("lab1w.txt", "w+");
    char ch;
    ch = fgetc(input);
    while (ch != EOF)
    {
        fputc(ch, output);
        ch = fgetc(input);
    }
    fclose(input);
    fclose(output);
    return 0;
}