#include <stdio.h>
#include <stdarg.h>

#pragma region 가변 인수
    // 인수의 개수가 정해지지 않은 인수.

void Function(int x, ...)
{
    // 1. va_list
    // 각 가변 인자의 시작 주소를
    // 가리킬 수 있는 포인터
    va_list ptr;


    // 2. va_start
    // va_list로 만들어진 포인터에게 고정 인자의 
    // 주소를 가르쳐주어 va_list의 값을 초기화 시켜줌
    va_start(ptr, x);

    // 3. va_arg
    // va_list에 저장된 var_type 값을 검색해 반환하고,
    // va_list에서 다음 인수를 가리키도록 va_list의 주소를
    // 이동시켜 다음 인수가 시작되는 위치를 변경

    printf("%d ", x);

    for (int i = 0; i < x; i++)
    {
        printf("%d ", va_arg(ptr, int));
    }
    printf("\n");

    // 4. va_end
    // va_list인 값을 NULL로 초기화한다.
    va_end(ptr);
}

#pragma endregion

int main()
{
    Function(4, 2, 3, 4, 5);
    Function(2, 10, 20);
    Function(5, 100, 200, 300, 400, 500);

    // Function(10, 20, 30, 40, 50);
    // printf("%d, %d, %d, %d", 10, 20, 30, 40);

    return 0;
}