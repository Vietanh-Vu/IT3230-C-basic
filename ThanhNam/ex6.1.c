#include <stdio.h>

int a[100];

int f(int n){
    if(n <= 1) {
    	a[n] = 1; return a[n];
	}
	else {
    	a[n] = f(n-1)+ f(n-2);
	    return a[n];	
	}
}

int main(){
//	a[0] = 1;
//	a[1] = 1;
    for(int i = 0; i <= 20; i++){
    	a[i] = f(i);
	    printf("%d ",a[i]);	
	}
}
