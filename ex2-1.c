#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcat(char *s1, char *s2) {
    char *s3 = (char *)malloc((strlen(s1) + strlen(s2)) * sizeof(char));
    strcpy(s3, s1); 
    strcpy(s3 + strlen(s1), s2);
    return s3;
}

void main() {
    char *s1 = "Hello ";
    char *s2 = "World!!!\n";
    printf("%s", my_strcat(s1, s2));
}