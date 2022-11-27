#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


typedef struct cityinfo
{
	// 도시의 이름, 속한 국가, 인구 수에 대한 정보를 저장
	char name[20];
	char country[20];
	char population[20];
} City;


void inputmyCity(City *my3)
{
	printf("Input three cities: \n");
	for (int i = 0; i < 3; i++)
	{
		printf("Name> ");
		fgets(my3[i].name, sizeof(my3[i].name), stdin);
		my3[i].name[strlen(my3[i].name) - 1] = '\0';

		printf("Country> ");
		fgets(my3[i].country, sizeof(my3[i].country), stdin);
		my3[i].country[strlen(my3[i].country) - 1] = '\0';

		printf("Population> ");
		fgets(my3[i].population, sizeof(my3[i].population), stdin);
		my3[i].population[strlen(my3[i].population) - 1] = '\0';
	}
}


void ShowmyCity(City *my3)
{
	printf("\nPrinting the three cities: \n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d. %s in %s with a population of %s people \n", i + 1, my3[i].name, my3[i].country, my3[i].population);
	}
}

int main() {
	// 구조체 배열을 선언해서 이러한 도시에 대한 정보를 저장하는 구조
	City myci[3];
	inputmyCity(myci);
	ShowmyCity(myci);

	return 0;
}