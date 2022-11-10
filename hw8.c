#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//double pow(double a, double b); // a의 b승을 반환
//double sqrt(double x); // 루트 x를 반환

double stdev(double num[])
{
	double result, my_total = 0, my_m;
	// 평균 구하기
	for (int i = 0; i < 5; i++)
		my_total += num[i];
	my_m = my_total / 5;
	my_total = 0;

	// 표준편차 구하기
	for (int i = 0; i < 5; i++)
		my_total += pow(num[i] - my_m, 2);

	result = sqrt(my_total / 5);

	return result;
} 

int main() {
	double num[5];

	printf("Enter 5 real numbers: ");
	scanf(" %lf %lf %lf %lf %lf", &num[0], &num[1], &num[2], &num[3], &num[4]);
	// 실수형 변수, 서식문자 printf랑 scanf 확인하기
	// num[i]가 가리키는 값은 안에 담긴 값
	// &num[i]가 가리키는 값은 주소값

	printf("Standard Deviation = %.3f", stdev(num));
	
	return 0;
}