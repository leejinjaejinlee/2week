#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void ReadTextFile(const char* fileName)
{
	FILE* readfile = fopen(fileName, "r");

	char buffer[10000] = { 0, };

	// fread()
	// ù ��° �Ű����� : ũ�⸦ ������ �迭�� ����Ű�� �������̴�.
	// �� ��° �Ű����� : �о���� ������ ũ���̸�, ������ ����Ʈ�̴�.
	// �� ��° �Ű����� : �о���� ���ҵ��� ������ �� ������ ũ���.
	// �� ��° �Ű����� : �����͸� �Է¹��� ��Ʈ���� FILE ��ü�� ����Ű�� �������̴�.

	fread(buffer, 1, 10000, readfile);
	printf("%s", buffer);

	fclose(readfile);
}

int main()
{
#pragma region ���� �����
	// ���� ��� ��ġ(��ũ)�κ��� �����͸� �о���ų� �����ϴ� ����

	// fopen("������ �ϴ� ���� �̸�", "���� ���")
	// "w" : ���� ���� (write)
	//	FILE* filePtr = fopen("data.txt", "w");
	//	
	//	char content[ ] = "Content";
	//	
	//	fputs("Hello World", filePtr);
	//	
	//	FILE* fileReader = fopen("data.txt", "r");
	//	fgets(content, sizeof(content), fileReader);
	//	printf("%s", content);
	//	
	//	// fprintf(filePtr, "%s\n", "Data");
	//	fclose(fileReader); // ���� �ݾ��ֱ�

#pragma endregion

	// ReadTextFile("Resources/original.txt");

	while (1)
	{
		ReadTextFile("Resources/data.txt");

		system("cls");
	}

	return 0;
}