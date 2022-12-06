#include<stdio.h>

void Swap(int n , char a, char b, char c ){
    if(n==1){
        printf("\t%c -> %c\n",a,b);
        return;
    }
    Swap(n-1,a,c,b); 
    Swap(1,a,b,c);
    Swap(n-1,c,b,a);
    }
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    while(n <= 0){
        printf("Nhap n: ");
    	scanf("%d", &n);	
	}
    Swap(n,'A','B','C');
}
