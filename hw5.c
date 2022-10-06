#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int DecToBin(int num)
{

	if (num == 1)
		return 1;
	else
		printf("%d ", DecToBin(num / 2));

	return num % 2; // 10 , 5, 2, 1
} // 

int main() {
	int input, output;
	printf("양의 정수를 입력해주세요.\n입력: ");
	scanf(" %d", &input);

	// 2 | 20 - 0
	// 2 | 10 - 0
	// 2 | 5 - 1
	// 2 | 2 - 0
	// 2 | 1 
	// 10100
	printf("%d ", DecToBin(input));
	//printf("")

	return 0;
}