#include <stdio.h>

int x[100];
int n = 8;

void PrintSolution() {
	for(int k = 0; k < n; k++){
		printf("%d", x[k]);
	}
	printf("\n");
}

int check(int v, int k){
	if(v == 0) return 1;
	else{
		if(x[k-1] == 1) return 0;
		else return 1;
	}
}

int TRY(int k) {
	for(int v = 0; v <= 1; v++) {
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
