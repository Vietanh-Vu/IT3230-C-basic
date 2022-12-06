#include <stdio.h>

int x[9][9];

void PrintSolution() {
	for(int i = 0; i <= 8; i++) {
		for(int j = 0; j <= 8; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
}

int check(int v, int r, int c) {
	for (int i = 0; i <= r-1; i++) {
		if (x[i][c] == v) return 0;
	} // check cot c tu hang 1 den r-1
	for (int j = 0; j <= c-1; j++) {
		if(x[r][j] == v) return 0;
	}// check hang r tu cot 1 den c-1
	//check o 3x3 chua x[r][c]
	int I = r/3, J = c/3;
	for (int i = 0; i <= r - 3*I - 1; i++) {
		for(int j = 0; j <= 2; j++) {
			if(x[3*I + i][3*J + j] == v)
			return 0;
		}
	}
	for (int j = 0; j <= c - 3*J - 1; j++) {
		if(x[r][3*J + j] == v ) return 0;
	}
	return 1;
} 

void Try(int r, int c) {
	for (int v = 1; v <= 9; v ++) {
		if (check(v,r,c)) {
			x[r][c] = v;
			if (r == 8 && c == 8) {
				PrintSolution();
			} else {
				if(c == 8) Try (r+1,0);
				else Try (r, c+1);
			}
		}
	}
}

void main() {
	Try (0,0);
}
