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

int partition(student A[], int L, int R, int pivotIndex)
{
    student pivot = A[pivotIndex];
    int storeIndex = L;
    swap(&A[pivotIndex], &A[R]);
    for (int i = L; i <= R - 1; i++)
    {
        if (cmp(A[i], pivot) < 0)
        {
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[R], &A[storeIndex]);
    return storeIndex;
}

void quickSort(student A[], int L, int R)
{
    if (L < R)
    {
        int pivot = (L + R) / 2;
        pivot = partition(A, L, R, pivot);
        if (L < pivot)
        {
            quickSort(A, L, pivot - 1);
        }
        if (pivot < R)
        {
            quickSort(A, pivot + 1, R);
        }
    }
}

int main()
{
    readFromFile();
    quickSort(students, 1, n);
    writeToFile();
    return 0;
}