#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int array_check (int arr1[100], int arr2[100]) {
		for (int i = 0; i < 100; i++) {
			if (arr1[i] != arr2[i]) {
				return 0;
			}
		}
		return 1;
}

int main () {
	int arr1[100] = {1,3,4,6};
	int arr2[100] = {1,3,4};
	printf("%d", array_check(arr1, arr2));
}
