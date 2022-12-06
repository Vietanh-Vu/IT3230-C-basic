#include <stdio.h>

int x[100];
int n = 5;
int k = 2;

void PrintSolution() {
	for(int j = 1; j <= k; j++){
		printf("%d ", x[j]);
	}
	printf("\n");
}

int check(int v, int k){
	
}

int TRY(int i) {
	for(int v = x[i-1] + 1; v <= n-k+i; v++) {
		if(1){
			x[i] = v;
			if(i == k) PrintSolution();
    		else TRY(i+1);
		}
	}
}

int main() {
	x[0] = 0;
	TRY(1);
	return 0;
}
