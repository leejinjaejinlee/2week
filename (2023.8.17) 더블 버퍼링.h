#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#pragma region ������۸�

int width;
int height;
int key;

// HANDLE �ε����� �����ؼ� ���۸� ��ü��Ű�� ����
int screenIndex = 0;

// ���� ����
HANDLE Screen[2];

// [0] : Front Buffer
// [1] : Back Buffer

struct Player
{
	int x;
	int y;
	const char* shape;
};

// ���۸� �ʱ�ȭ�ϴ� �Լ�

void Init()
{
	CONSOLE_CURSOR_INFO cursor;

	// ������ ���� ������, ���� ������
	COORD size = { width, height };

	// LEFT, TOP, RIGHT, BOTTOM
	SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

	// ȭ�� 2���� �����Ѵ�
	// FRONT BUFFER
	Screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	SetConsoleScreenBufferSize(Screen[1], size);

	SetConsoleWindowInfo(Screen[1], TRUE, &rect);

	// Ŀ���� Ȱ��ȭ ����
	// false : ����
	// true : ��

	cursor.bVisible = false;

	SetConsoleCursorInfo(Screen[0], &cursor);
	SetConsoleCursorInfo(Screen[1], &cursor);
}

void Flipping()
{
	// ���۴� �ϳ��� Ȱ��ȭ��ų �� �ֽ��ϴ�.
	SetConsoleActiveScreenBuffer(Screen[screenIndex]);

	// true <- false
	screenIndex = !screenIndex;
}

// ���۸� �����
// ��ü�� ���۸� �����ִ� �Լ�

void Clear()
{
	COORD coord = { 0,0 };

	DWORD dw;

	FillConsoleOutputCharacter
	(
		Screen[screenIndex],
		' ',
		width * height,
		coord,
		&dw
	);
}

void ReleaseScreen()
{
	CloseHandle(Screen[0]);
	CloseHandle(Screen[1]);
}

// ���۸� �̿��ؼ� ����ϴ� �Լ�
void ShowBuffer(int x, int y, const char* string)
{
	COORD cursorPosition = { x, y };

	DWORD dw;

	SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

	WriteFile
	(
		Screen[screenIndex],
		string,
		strlen(string),
		&dw,
		NULL
	);
}

#pragma endregion

int main()
{

#pragma region ���� ���۸�

	//	Player player = { 5, 5, "��" };
	//	
	//	// 1. ���� �ʱ�ȭ
	//	Init();
	//	
	//	while (1)
	//	{
	//		if (_kbhit())
	//		{
	//			key = _getch();
	//	
	//			switch (key)
	//			{
	//			case UP: if (player.y <= 0) break;
	//				player.y--;
	//				break;
	//			case LEFT: if (player.x <= 0) break;
	//				player.x--;
	//				break;
	//			case RIGHT: player.x++;
	//				break;
	//			case DOWN: player.y++;
	//				break;
	//			}
	//		}
	//		
	//		ShowBuffer(player.x, player.y, player.shape);
	//		
	//		// 2. ���� ��ü
	//		Flipping();
	//	
	//		// 3. ��ü�� ������ ������ �����Ѵ�
	//		Clear();
	//	}
	//	
	//	// 4. ���۸� �����Ѵ�.
	//	ReleaseScreen();

#pragma endregion

#pragma region �ִ� �����

	int x = 0;
	int y = 0;
	int multipul = 0;	// ���ϱ�

	printf("������ �Է����ּ���\n");
	scanf_s("%d %d", &x, &y);

	for (int i = 1; i <= x && i <= y; i++)
	{
		if (x % i == 0 && y % i == 0)
			multipul = i;
	}
	printf("�ִ������� %d�̴�.", multipul);

#pragma endregion

	return 0;
}