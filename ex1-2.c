#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int array_check(int *arr1, int *arr2, size_t size1, size_t size2)
{

	if (size1 != size2)
		return 0;
	for (size_t i = 0; i < size1; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int arr1[] = {1, 3, 4, 0};
	int arr2[] = {1, 3, 4};
	printf("%d", array_check(arr1, arr2, SIZE_OF_ARRAY(arr1), SIZE_OF_ARRAY(arr2)));
}
