#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5];

	printf("Please input five integers: ");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		scanf(" %d", &arr[i]);
	}


	printf("\nOdd numbers: ");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		if (arr[i] % 2 != 0)
			printf("%d ", arr[i]);
	}

	printf("\nEven numbers: ");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		if (arr[i] % 2 == 0)
			printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}