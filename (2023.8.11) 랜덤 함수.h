#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#pragma region 랜덤 함수
    // 0 ~ 32767 사이의 난수 값을 반환하는 함수.

    //  int seed = rand();
    //  srand(time(NULL));

    //  for (int i = 0; i < 10; i++)
    //  {
    //      seed = rand() % 10 + 1;
    //      printf("seed의 값 : %d\n", seed);
    //  }

#pragma endregion

#pragma region 업 다운 게임

    int a; // 컴퓨터 숫자
    int count = 0;
    int point = 5;
    int num;
    a = rand() % 50 + 1;


    printf("1~50까지의 숫자를 맞추시오\n");

    while (count < point)
    {
        printf("숫자를 입력해주세요\n");
        scanf_s("%d", &num);
        if (num == a)
        {
            printf("정답입니다!\n");
            break;
            return;
        }
        else if (num > a)
        {
            count++;
            printf("랜덤숫자보다 큽니다!\n");
        }
        else if (num < a)
        {
            count++;
            printf("랜덤숫자보다 작습니다!\n");
        }
    }
    if (count == point)
    {
        printf("죽었습니다.");
    }

#pragma endregion

    return 0;
}