#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


void gotoXY(int x, int y)
{
	// x, y ��ǥ ����
	COORD position = { x, y };

	// Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
int main()
{
#pragma region _kbhit() �Լ�

	//	char key = 0;
	//	int x = 5;
	//	int y = 5;
	//	
	//	// Update()
	//	while (1)
	//	{
	//		gotoXY(x, y);
	//		printf("�� ");
	//		if(_kbhit()) // Ű���� �Է��� Ȯ���ϴ� �Լ�
	//		{
	//			key = _getch();
	//	
	//			if (key == -32)
	//			{
	//				key = _getch();
	//			}
	//	
	//			switch (key)
	//			{
	//			case UP: if (y <= 0) break;
	//				y--;
	//				break;
	//			case LEFT: if (x <= 0) break;
	//				x--;
	//				break;
	//			case RIGHT: x++;
	//				break;
	//			case DOWN: y++;
	//				break;
	//			}
	//			system("cls");		// ��ũ���� ����� �Լ�
	//		}		
	//	
	//		// gotoXY(20, 10);
	//		// printf("���� ��...\n");
	//	
	//		// Sleep : 1/1000�� 1�� ���Ǹ�,
	//		// Sleep(1000);
	//	}


#pragma endregion

#pragma region 

#pragma endregion

	// LNK1036 ��ŷ

	return 0;
}