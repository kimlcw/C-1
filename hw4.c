#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int mynum, mynum2 = 0;
	printf("Please enter a number: ");
	scanf("%d", &mynum);

	for (int i = 1; i <= mynum; i++)
	{
		if((mynum % i) == 0)
			mynum2++;
	}
	
	if(mynum2 == 2)
		printf("It is a prime number.\n");
	else
		printf("It is not a prime number.\n");

	return 0;
}