#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


// fgets() 호출 시 마지막에 삽입되는 줄바꿈 문자 \n을 제거

void RemoveBSN(char str[])
{
    str[strlen(str) - 1] = 0;
}





int main() {
    char str[100];

    printf("Input> ");
    fgets(str, strlen(str), stdin);
    RemoveBSN(str);

    

    for(int i =0;i<strlen(str);i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }

    
    printf("Output > %s", str);
    return 0;

}
