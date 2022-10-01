#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	/*
	<1차 프로그래밍 과제 (성적에 5% 반영)>

	컬러 채널당 8비트씩 할당된 24비트 RGB 컬러의 hex code (16진수 컬러 코드값)를 계산하고, 
	RGB 컴포넌트별로 색상을 조정하는 프로그램을 만드는 과제입니다.
	*/

	int clr = 0x0;
	int clr_R = 0, clr_G = 0, clr_B = 0, change_lv = 0;
	char change_chl = 0, asr = 0;

	//1) 16진수 컬러 코드값을 입력 받습니다 (값에 대한 예외 처리는 하지 않아도 됨)
	printf("16진수 컬러 코드값을 입력하세요:");
	scanf(" %x", &clr);

	//2) 이에 대한 RGB값을 각각 계산하여 출력해 줍니다.
	// 이는 수업시간에 배운 비트 연산으로 계산 가능합니다(and와 오른쪽 shift)
	clr_R = (clr >> 16) & 0x0000FF;
	clr_G = (clr >> 8) & 0x0000FF;
	clr_B = clr & 0x0000FF;
	printf("입력된 컬러의 R,G,B 값은 (%d, %d, %d)입니다.\n", clr_R, clr_G, clr_B);
	
	while (1)
	{
		//3) 다음으로, 변경할 컬러 채널을 입력합니다.
		// 이 때 R,G,B,r,g,b 외의 입력 문자에 대해서는 오류 메시지를 보여 주고 다시 입력 받습니다.
		printf("\nRGB 중 변경할 컬러 채널을 입력하세요:");
		scanf(" %c", &change_chl);
		switch (change_chl)
		{
		case 'R': case 'r': case 'G': case 'g': case 'B': case 'b':
			// 4) 채널별 증감 정도를 입력 받습니다. 
			printf("%c 채널의 증감 정도를 입력하세요: ", change_chl);
			scanf(" %d", &change_lv);
			// 증감 이후의 각 컬러 채널의 값이 [0, 255] 사이가 아닐 경우, 
			// 음수값은 0으로, 256 이상의 값은 255로 보정합니다
			switch (change_chl)
			{
			case 'R': case 'r':
				clr_R += change_lv;
				if (clr_R < 0)
					clr_R = 0;
				else if (clr_R > 255)
					clr_R = 255;
				break;

			case 'G': case 'g':
				clr_G += change_lv;
				if (clr_G < 0)
					clr_G = 0;
				else if (clr_G > 255)
					clr_G = 255;
				break;

			case 'B': case 'b':
				clr_B += change_lv;
				if (clr_B < 0)
					clr_B = 0;
				else if (clr_B > 255)
					clr_B = 255;
				break;
			}

			//5) 조정된 각 컬러 채널의 값과 이를 이용하여 계산된 hex code값을 출력합니다. 
			// hex code를 계산할 때에는 or와 왼쪽 shift 연산을 사용합니다.
			clr = (clr_R << 16) | (clr_G << 8) | (clr_B);
			printf("\n조정된 컬러의 R,G,B 값은 (%d, %d, %d)이고, 이는 0x%0X로 저장됩니다.\n", clr_R, clr_G, clr_B, clr);

			// 6) 계속 컬러를 입력 받겠냐고 물어본 후, y 또는 Y를 누르면 처음으로 돌아가고, 다른 문자를 누르면 종료합니다.
			printf("계속 컬러를 조정하시겠습니까? (y/n) ");
			scanf(" %c", &asr);
			if (asr == 'y' || asr == 'Y')
				continue;
			else
				break;

		default:
			printf("잘못 입력하셨습니다. 다시 입력하세요.\n");
			continue;
		}		
		break;
	}
	return 0;
}