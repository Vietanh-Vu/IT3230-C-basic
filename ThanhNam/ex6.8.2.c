#include <stdio.h>

int n, M, T;
int x[100];
int A[100] = {0, 1, 2, 2}; //ta xet tu A[1] nen cho A[0] = 0

void PrintSolution(){
	for(int i = 1; i <= n; i++){
		printf("%d*%d ", A[i], x[i]);
		if(i!=n) {
			printf("+ ");
		}
	}
	printf("= %d\n", M);
}

int check(int v, int k) {
	if(k == n) return T + v*A[k] == M; 
	//kiem tra nghiem cuoi cung cua phuong trinh co duoc in khong
	return 1;
	//neu k < n thi cho phep Try tiep
}

void Try(int k) {
	for(int v = 1; v <= (M-T-(n-k))/A[k]; v++) {
		if (check(v,k)){
			x[k] = v;
			T += v*A[k];
			if(k == n) PrintSolution();
			else Try(k+1);
			T -= v*A[k]; //tra lai gia tri T de xet gia tri khac
		}
	}
}

int main() {
	n = 3; M = 10; T = 0;
	Try(1);
}
