#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


typedef struct cityinfo
{
	char name[20];
	char country[20];
	int population;
} City; 

typedef struct three_info // 좌표 저장
{
	City myci[3];
} Tee;


void inputmyCity(Tee my3)
{
	printf("Input three cities: \n");
	for (int i = 0; i < 3; i++)
	{
		printf("Name> ");
		fgets(my3.myci[i].name, strlen(my3.myci[i].name), stdin);

		printf("Country> ");
		fgets(my3.myci[i].country, strlen(my3.myci[i].country), stdin);

		printf("Population> ");
		fgets(my3.myci[i].population, strlen(my3.myci[i].population), stdin);
	}
}


void ShowmyCity(Tee my3)
{
	printf("Printing the three cities: \n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d. %s in %s with a population of %d people \n", i+1, my3.myci[i].country, my3.myci[i].name, my3.myci[i].population);
	}
}

int main() {
	Tee my_input;
	inputmyCity(my_input);
	ShowmyCity(my_input);

	return 0;
}
