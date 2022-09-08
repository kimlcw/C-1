#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int mynum1, mynum2;
	printf("Input two integers : ");
	scanf("%d %d", &mynum1, &mynum2);
	printf("%d & %d = %d\n", mynum1, mynum2, mynum1 & mynum2);
	printf("%d | %d = %d\n", mynum1, mynum2, mynum1 | mynum2);
	printf("%d ^ %d = %d\n", mynum1, mynum2, mynum1 ^ mynum2);

	return 0;
}