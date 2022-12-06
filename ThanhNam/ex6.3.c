#include <stdio.h>

a[10][10];

void ini(){
	for(int i=0; i <10; i++){
		for(int j = 0; j < 10; j++ ){
			a[i][j] == 0;
		}
	}
}

int C(k,n) {
	if(k == 0 || k == n){
		a[k][n] = 1;
		return a[k][n];
	}
	else{
		a[k][n] = C(k,n-1) + C(k-1,n-1);
		return a[k][n];
	}
}

int main() {
	printf("%d", C(2,5));
}
