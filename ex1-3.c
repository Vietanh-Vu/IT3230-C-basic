#include <stdio.h>
#include <string.h>

void replaceLetters(char str[], char first, char second)
{
    int strLength = strlen(str);
    for (int i = 0; i < strLength; i++)
    {
        if (str[i] == first)
        {
            str[i] = second;
        }
    }
    printf("Result: %s", str);
}

int main()
{
    char inputString[100], firstChar, secondChar;

    printf("Enter your string: ");
    scanf("%s", &inputString);
    fflush(stdin);
    printf("Enter first char: ");
    scanf("%c", &firstChar);
    fflush(stdin);
    printf("Enter second char: ");
    scanf("%c", &secondChar);

    replaceLetters(inputString, firstChar, secondChar);
    return 0;
}