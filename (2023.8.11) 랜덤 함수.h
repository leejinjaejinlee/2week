#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#pragma region ���� �Լ�
    // 0 ~ 32767 ������ ���� ���� ��ȯ�ϴ� �Լ�.

    //  int seed = rand();
    //  srand(time(NULL));

    //  for (int i = 0; i < 10; i++)
    //  {
    //      seed = rand() % 10 + 1;
    //      printf("seed�� �� : %d\n", seed);
    //  }

#pragma endregion

#pragma region �� �ٿ� ����

    int a; // ��ǻ�� ����
    int count = 0;
    int point = 5;
    int num;
    a = rand() % 50 + 1;


    printf("1~50������ ���ڸ� ���߽ÿ�\n");

    while (count < point)
    {
        printf("���ڸ� �Է����ּ���\n");
        scanf_s("%d", &num);
        if (num == a)
        {
            printf("�����Դϴ�!\n");
            break;
            return;
        }
        else if (num > a)
        {
            count++;
            printf("�������ں��� Ů�ϴ�!\n");
        }
        else if (num < a)
        {
            count++;
            printf("�������ں��� �۽��ϴ�!\n");
        }
    }
    if (count == point)
    {
        printf("�׾����ϴ�.");
    }

#pragma endregion

    return 0;
}