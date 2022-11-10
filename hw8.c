#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//double pow(double a, double b); // a�� b���� ��ȯ
//double sqrt(double x); // ��Ʈ x�� ��ȯ

double stdev(double num[])
{
	double result, my_total = 0, my_m;
	// ��� ���ϱ�
	for (int i = 0; i < 5; i++)
		my_total += num[i];
	my_m = my_total / 5;
	my_total = 0;

	// ǥ������ ���ϱ�
	for (int i = 0; i < 5; i++)
		my_total += pow(num[i] - my_m, 2);

	result = sqrt(my_total / 5);

	return result;
} 

int main() {
	double num[5];

	printf("Enter 5 real numbers: ");
	scanf(" %lf %lf %lf %lf %lf", &num[0], &num[1], &num[2], &num[3], &num[4]);
	// �Ǽ��� ����, ���Ĺ��� printf�� scanf Ȯ���ϱ�
	// num[i]�� ����Ű�� ���� �ȿ� ��� ��
	// &num[i]�� ����Ű�� ���� �ּҰ�

	printf("Standard Deviation = %.3f", stdev(num));
	
	return 0;
}