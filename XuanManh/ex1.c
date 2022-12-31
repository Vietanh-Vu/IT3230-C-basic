#include <stdio.h>
#include <math.h>

char ho[15][10] = {"Nguyen", "Tran", "Le", "Pham", "Hoang", "Huynh", "Phan", "Vu", "Vo", "Dang", "Bui","Do", "Ho", "Duong", "Ly"};
char tenDem[7][10] = {"Quoc", "Van", "Phuc", "Ngoc", "Phong", "Huu", "Thi"};
char ten[10][10] = {"Huy", "Khang", "Bao", "Minh", "Phuc", "Anh", "Khoa", "Phat", "Dat", "Khoi"};

int main()
{
    int n;
    printf("Nhap so ho so can tao: "); scanf("%d", &n);
    FILE *f = fopen("profile.txt", "w+");
    for (int i = 1; i <= n; i++) 
    {
        fprintf(f, "%s %s %s\n%d-%d-%d\n", ho[rand() % 15], tenDem[rand() % 7], ten[rand() % 10], rand() % 40 + 1980, rand() % 12 + 1, rand() % 30 + 1);
    }
    fprintf(f, "#");
    fclose(f);
    return 0;
}