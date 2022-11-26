#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkCondition(const char* str, int length)
{
	// 패스워드가 숫자 및 알파벳을 혼합하고 있는지, 그리고 범위가 8-12자 이내인지 판단
	// str은 패스워드 문자열이고, length는 이 문자열의 길이
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
			printf("숫자와 알파벳을 혼합해 주세요: ");
			return 0;
		}
		else
		{
			return 1; // 해당 조건을 만족하면 1을, 아니면 0을 리턴합
		}

	}
	else
	{
		printf("범위 내의 문자 수로 다시 입력하세요: ");
		return 0;
	}
}

void encode(const char* str, int length, const char* encodingTable, char* newStr)
{
	// 인코딩에 사용되는 문자열 테이블 (입력)
	// 단일 치환 암호화 기법
	int num;

	strcpy(newStr, str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			// 1) 알파벳 소문자의 경우, main() 함수 내에 아래 encoding table을 정의하여 이를 함수로 전달하여 인코딩을 수행합니다.
			// 인코딩 결과 a는 w로, b는 y로, z은 i로 바뀌게 됩니다.
			// char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
			newStr[i] = encodingTable[str[i] - 'a'];
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			// 2) 숫자의 경우, 2를 더한 후 10으로 나눴을 때의 나머지를 이용하는 modular 연산을 수행합니다.
			//즉, 7은 9로, 8은 0으로, 9는 1로, 0은 2로 바뀌게 됩니다.
			num = str[i] - '0';
			num = (num + 2) % 10;
			num += '0';
			newStr[i] = num;			
		}
	}
}

void decode(const char* str, int length, const char* encodingTable, char* newStr)
{
	// 인코딩 또는 디코딩 결과가 저장되는 문자열(출력)
	// 디코딩은 위를 역으로 수행하여 원래 패스워드로 바꿔주면 됩니다.
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
	// 1) 알파벳 소문자의 경우, main() 함수 내에 아래 encoding table을 정의하여 
	// 이를 함수로 전달하여 인코딩을 수행합니다.
	// 인코딩 결과 a는 w로, b는 y로, z은 i로 바뀌게 됩니다.
	char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
	char my_ps[20];
	char en_str[20];
	char de_str[20];

	printf("====================================================\n");
	printf("패스워드를 입력하세요 (숫자와 알파벳을 혼합하여 8-12자): ");
	scanf("%s", &my_ps);

	while(!checkCondition(my_ps, strlen(my_ps)))
	{
		scanf("%s", &my_ps);
	}

	if (checkCondition(my_ps, strlen(my_ps)) == 1)
	{
		encode(my_ps, strlen(my_ps), encodingTable, en_str);
		printf("입력하신 패스워드가 %s로 암호화 되었습니다.\n", en_str);
		decode(en_str, strlen(en_str), encodingTable, de_str);
		printf("이를 다시 복호화한 결과, 패스워드는 %s입니다.\n", de_str);
	}
	
	printf("====================================================\n");

	return 0;
}