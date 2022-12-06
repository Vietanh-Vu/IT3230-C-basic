#include <stdio.h>

int n, M, T;
int x[100];

void PrintSolution(){
	for(int i = 1; i <= n; i++){
		printf("%d ", x[i]);
		if(i!=n) {
			printf("+ ");
		}
	}
	printf("= %d\n", M);
}

int check(int v, int k) {
	if(k == n) return T + v == M; 
	//kiem tra nghiem cuoi cung cua phuong trinh co duoc in khong
	return 1;
	//neu k < n thi cho phep Try tiep
}

void Try(int k) {
	for(int v = 1; v <= M-T-(n-k); v++) {
		if (check(v,k)){
			x[k] = v;
			T += v;
			if(k == n) PrintSolution();
			else Try(k+1);
			T -= v; //tra lai gia tri T de xet gia tri khac
		}
	}
}

int main() {
	n = 3; M = 5; T = 0;
	Try(1);
}
