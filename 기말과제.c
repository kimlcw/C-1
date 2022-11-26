#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkCondition(const char* str, int length)
{
	// �н����尡 ���� �� ���ĺ��� ȥ���ϰ� �ִ���, �׸��� ������ 8-12�� �̳����� �Ǵ�
	// str�� �н����� ���ڿ��̰�, length�� �� ���ڿ��� ����
	int abc_count = 0, num_count = 0;

	if (length >= 8 && length <= 12)
	{
		for (int i = 0; i < length; i++)
		{
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				abc_count++;
			if (str[i] >= '0' && str[i] <= '9')
				num_count++;
		}

		if (abc_count == 0 || num_count == 0)
		{
			printf("���ڿ� ���ĺ��� ȥ���� �ּ���: ");
			return 0;
		}
		else
		{
			return 1; // �ش� ������ �����ϸ� 1��, �ƴϸ� 0�� ������
		}

	}
	else
	{
		printf("���� ���� ���� ���� �ٽ� �Է��ϼ���: ");
		return 0;
	}
}

void encode(const char* str, int length, const char* encodingTable, char* newStr)
{
	// ���ڵ��� ���Ǵ� ���ڿ� ���̺� (�Է�)
	// ���� ġȯ ��ȣȭ ���
	int num;

	strcpy(newStr, str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			// 1) ���ĺ� �ҹ����� ���, main() �Լ� ���� �Ʒ� encoding table�� �����Ͽ� �̸� �Լ��� �����Ͽ� ���ڵ��� �����մϴ�.
			// ���ڵ� ��� a�� w��, b�� y��, z�� i�� �ٲ�� �˴ϴ�.
			// char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
			newStr[i] = encodingTable[str[i] - 'a'];
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			// 2) ������ ���, 2�� ���� �� 10���� ������ ���� �������� �̿��ϴ� modular ������ �����մϴ�.
			//��, 7�� 9��, 8�� 0����, 9�� 1��, 0�� 2�� �ٲ�� �˴ϴ�.
			num = str[i] - '0';
			num = (num + 2) % 10;
			num += '0';
			newStr[i] = num;			
		}
	}
}

void decode(const char* str, int length, const char* encodingTable, char* newStr)
{
	// ���ڵ� �Ǵ� ���ڵ� ����� ����Ǵ� ���ڿ�(���)
	// ���ڵ��� ���� ������ �����Ͽ� ���� �н������ �ٲ��ָ� �˴ϴ�.
	int num;

	strcpy(newStr, str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			for (int j = 0; j < strlen(encodingTable); j++)
			{
				if (str[i] == encodingTable[j])
					newStr[i] = j + 'a';
			}
		}
		if (str[i] >= '2' && str[i] <= '9')
		{
			num = newStr[i] - '0';
			num -= 2;
			newStr[i] = num + '0';
		}
		else if (str[i] >= '0' && str[i] <= '1')
		{
			num = newStr[i] - '0';
			num = num + 10 - 2;
			newStr[i] = num + '0';
		}
	}
}



int main(){
	// 1) ���ĺ� �ҹ����� ���, main() �Լ� ���� �Ʒ� encoding table�� �����Ͽ� 
	// �̸� �Լ��� �����Ͽ� ���ڵ��� �����մϴ�.
	// ���ڵ� ��� a�� w��, b�� y��, z�� i�� �ٲ�� �˴ϴ�.
	char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
	char my_ps[20];
	char en_str[20];
	char de_str[20];

	printf("====================================================\n");
	printf("�н����带 �Է��ϼ��� (���ڿ� ���ĺ��� ȥ���Ͽ� 8-12��): ");
	scanf("%s", &my_ps);

	while(!checkCondition(my_ps, strlen(my_ps)))
	{
		scanf("%s", &my_ps);
	}

	if (checkCondition(my_ps, strlen(my_ps)) == 1)
	{
		encode(my_ps, strlen(my_ps), encodingTable, en_str);
		printf("�Է��Ͻ� �н����尡 %s�� ��ȣȭ �Ǿ����ϴ�.\n", en_str);
		decode(en_str, strlen(en_str), encodingTable, de_str);
		printf("�̸� �ٽ� ��ȣȭ�� ���, �н������ %s�Դϴ�.\n", de_str);
	}
	
	printf("====================================================\n");

	return 0;
}