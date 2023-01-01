#include <stdio.h>
#include <string.h>

typedef struct
{
    char ho[10];
    char tenDem[10];
    char ten[10];
    int year;
    int month;
    int day;
} student;

student students[1000];
int n;

void readFromFile()
{
    FILE *f1 = fopen("profile.txt", "r");
    int i = 0;
    do
    {
        i++;
        fscanf(f1, "%s", students[i].ho);
        if (!strcmp(students[i].ho, "#"))
            break;
        fscanf(f1, "%s %s", students[i].tenDem, students[i].ten);
        fscanf(f1, "%d-%d-%d", &students[i].year, &students[i].month, &students[i].day);  
    } while (1);
    n = i - 1;
    fclose(f1);
}

void writeToFile()
{
    FILE *f2 = fopen("sorted-profile.txt", "w+");
    for (int i = 1; i <= n; i++)
    {
        fprintf(f2, "%s %s %s\n%d-%d-%d\n", students[i].ho, students[i].tenDem, students[i].ten, students[i].year, students[i].month, students[i].day);
    }
    fprintf(f2, "#");
    fclose(f2);
}

int cmp(student a, student b)
{
    if (!strcmp(a.ten, b.ten))
        if (!strcmp(a.tenDem, b.tenDem))
            if (!strcmp(a.ho, b.ho))
                return 0;
            else 
                return strcmp(a.ho, b.ho);
        else 
            return strcmp(a.tenDem, b.tenDem);
    else
        return strcmp(a.ten, b.ten);
}

void swap(student *a, student *b)
{
    student tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(student A[], int i, int n)
{
    int L = 2 * i;
    int R = 2 * i + 1;
    int max = i;
    if (L <= n && cmp(A[i], A[L]) < 0)
    {
        max = L;
    }
    if (R <= n && cmp(A[max], A[R]) < 0)
    {
        max = R;
    }
    if (max != i)
    {
        swap(&A[i], &A[max]);
        heapify(A, max, n);
    }    
}

void buildHeap(student A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(A, i, n);
    }
}

void heapSort(student A[], int n)
{
    buildHeap(A, n);
    for (int i = n; i > 1; i--)
    {
        swap(&A[1], &A[i]);
        heapify(A, 1, i - 1);
    }
}

int main()
{
    readFromFile();
    heapSort(students, n);
    writeToFile();
    return 0;
}