#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int c;

	for (a = 0; a < 5; a++)
	{
		for (b = 0; b < (4-a); b++) {
			printf(" ");	// space 개수 = 5 - a - 1 = 4 - a
		}
		for (c = 0; c < (a*2)-1; c++) {
			printf("*");	// * 개수 = a*2-1
		}
		printf("\n");
	}


	return 0;
}
