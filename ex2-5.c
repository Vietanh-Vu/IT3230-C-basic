#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct address_book{
	char name[30];
	char tel[11];
	char email[50];
} info_t ;

info_t data[100];
int soluong = 0;
int n ;

void input() {
	
	fflush(stdin);
	printf("So luong can nhap : "); scanf("%d", &n);
	int start = soluong;
	int end = soluong + n;
	soluong = end; //update 
	
	for (int i = start; i < end ; i++) {
	    fflush(stdin); 
		printf("Nhap ten : ");
		fgets(data[i].name, 100, stdin);
		data[i].name[strlen(data[i].name) -1] = '\0';
		
		fflush(stdin); 
		printf("Nhap so dien thoai : ");
		fgets(data[i].tel, 11, stdin);
		data[i].tel[strlen(data[i].tel) - 1] = '\0';
		
		fflush(stdin); 
		printf("Nhap email : ");
		fgets(data[i].email, 100, stdin);
		data[i].email[strlen(data[i].email) -1] = '\0';		
		fflush(stdin);
	}
}

int main (){
	
	input();

	int end = soluong;
	int start = soluong - n;
	FILE *f;
	f = fopen("address_book.txt", "w+");
	
	for (int i = start; i < end; i++) {
		fwrite(&data[i], sizeof(info_t), 1, f);
	}
	
	info_t temp;
	printf("%32s%12s%32s\n","Ho va ten","So dien thoai", "Email");
	rewind(f);
	for (int i = 0; i < end; i++) {
		fread(&temp, sizeof(info_t), 1, f);
	    printf("%32s%12s%32s\n",temp.name, temp.tel, temp.email);
	}
	
	fclose(f);
	
}
