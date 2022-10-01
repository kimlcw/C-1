#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	/*
	<1�� ���α׷��� ���� (������ 5% �ݿ�)>

	�÷� ä�δ� 8��Ʈ�� �Ҵ�� 24��Ʈ RGB �÷��� hex code (16���� �÷� �ڵ尪)�� ����ϰ�, 
	RGB ������Ʈ���� ������ �����ϴ� ���α׷��� ����� �����Դϴ�.
	*/

	int clr = 0x0;
	int clr_R = 0, clr_G = 0, clr_B = 0, change_lv = 0;
	char change_chl = 0, asr = 0;

	//1) 16���� �÷� �ڵ尪�� �Է� �޽��ϴ� (���� ���� ���� ó���� ���� �ʾƵ� ��)
	printf("16���� �÷� �ڵ尪�� �Է��ϼ���:");
	scanf(" %x", &clr);

	//2) �̿� ���� RGB���� ���� ����Ͽ� ����� �ݴϴ�.
	// �̴� �����ð��� ��� ��Ʈ �������� ��� �����մϴ�(and�� ������ shift)
	clr_R = (clr >> 16) & 0x0000FF;
	clr_G = (clr >> 8) & 0x0000FF;
	clr_B = clr & 0x0000FF;
	printf("�Էµ� �÷��� R,G,B ���� (%d, %d, %d)�Դϴ�.\n", clr_R, clr_G, clr_B);
	
	while (1)
	{
		//3) ��������, ������ �÷� ä���� �Է��մϴ�.
		// �� �� R,G,B,r,g,b ���� �Է� ���ڿ� ���ؼ��� ���� �޽����� ���� �ְ� �ٽ� �Է� �޽��ϴ�.
		printf("\nRGB �� ������ �÷� ä���� �Է��ϼ���:");
		scanf(" %c", &change_chl);
		switch (change_chl)
		{
		case 'R': case 'r': case 'G': case 'g': case 'B': case 'b':
			// 4) ä�κ� ���� ������ �Է� �޽��ϴ�. 
			printf("%c ä���� ���� ������ �Է��ϼ���: ", change_chl);
			scanf(" %d", &change_lv);
			// ���� ������ �� �÷� ä���� ���� [0, 255] ���̰� �ƴ� ���, 
			// �������� 0����, 256 �̻��� ���� 255�� �����մϴ�
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

			//5) ������ �� �÷� ä���� ���� �̸� �̿��Ͽ� ���� hex code���� ����մϴ�. 
			// hex code�� ����� ������ or�� ���� shift ������ ����մϴ�.
			clr = (clr_R << 16) | (clr_G << 8) | (clr_B);
			printf("\n������ �÷��� R,G,B ���� (%d, %d, %d)�̰�, �̴� 0x%0X�� ����˴ϴ�.\n", clr_R, clr_G, clr_B, clr);

			// 6) ��� �÷��� �Է� �ްڳİ� ��� ��, y �Ǵ� Y�� ������ ó������ ���ư���, �ٸ� ���ڸ� ������ �����մϴ�.
			printf("��� �÷��� �����Ͻðڽ��ϱ�? (y/n) ");
			scanf(" %c", &asr);
			if (asr == 'y' || asr == 'Y')
				continue;
			else
				break;

		default:
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
			continue;
		}		
		break;
	}
	return 0;
}