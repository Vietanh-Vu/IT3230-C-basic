#include <stdio.h>

int x[100];
int n = 4;

void PrintSolution() {
	for(int k = 0; k < n; k++){
		printf("%d ", x[k]);
	}
	printf("\n");
}

int check(int v, int k){
	for(int i = 0; i < k; i++) {
		if (v==x[i]) {
			return 0;
		}
	}
	return 1;
}

int TRY(int k) {
	for(int v = 1; v <= n; v++) {
		if(check(v,k)){
			x[k] = v;
			if(k == n-1) PrintSolution();
    		else TRY(k+1);
		}
	}
}

int main() {
	TRY(0);
}
