#pragma once
#include <stdio.h>
#include <string.h>

#pragma region �Լ� ������
// �Լ��� �ּҰ��� �����ϰ� ����ų �� �ִ� ����

//  void Delegate()
//  {
//      printf("�븮��~");
//  }
//  
//  int Add(int x, int y)
//  {
//      return x + y;
//  }
//  
//  int Substract(int x, int y)
//  {
//      return x - y;
//  }
//  
//  int Multiple(int x, int y)
//  {
//      return x * y;
//  }
//  
//  int Divide(int x, int y)
//  {
//      return x / y;
//  }
//  
//  void Calculator(int x, int y, int (*cptr) (int, int))
//  {
//      printf("cptr �Լ��� ��� : %d\n", cptr(x, y));
//  }
#pragma endregion


int main()
{
#pragma region �Լ� ������

    // �Լ� �����ʹ� �Լ��� ��ȯ���� �Ű� ������ Ÿ���� ��ġ�ؾ� �ϸ�,
    // �Լ� �����͸� ����Ͽ� �������� �޸𸮸� �Ҵ��� �� �����ϴ�.

    //  void (*fptr) ();
    //  int (*cptr) (int, int);

    //  Calculator(10, 20, Add);
    //  Calculator(10, 20, Substract);
    //  Calculator(10, 20, Multiple);
    //  Calculator(20, 20, Divide);

    //  cptr = Add;
    //  printf("cptr �Լ��� ��� : %d\n", cptr(10, 20));
    //  cptr = Substract;
    //  printf("cptr �Լ��� ��� : %d\n", cptr(10, 20));
    //  cptr = Multiple;
    //  printf("cptr �Լ��� ��� : %d\n", cptr(10, 20));
    //  cptr = Divide;
    //  printf("cptr �Լ��� ��� : %d\n", cptr(20, 20));


    //  fptr = Delegate;

    //  fptr();

#pragma endregion

#pragma region �Ҽ� �Ǻ� �˰���
    //  int number = 0;
    //  int count = 0;
    //  
    //  printf("���� �Է� : ");
    //  scanf_s("%d", &number);
    //  
    //  for (int i = 2; i < number; i++)
    //  {            
    //      if ( number % i == 0 )
    //      {
    //          count++;
    //      }
    //  }
    //  if (count == 1)
    //  {
    //      printf("�Ҽ��Դϴ�!");
    //  }
    //  else
    //  {
    //      printf("�Ҽ��� �ƴմϴ�!");
    //  }
#pragma endregion

#pragma region ȸ�� �Ǻ� �˰���
    //  const char* content = "Level";
    //  printf("%d", strlen(content));

    int flag = 0;

    const char* a = "aadda";

    int size = strlen(a);

    for (int i = 0; i < size / 2; i++)
    {
        if (a[1] == a[size - 1 - i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("ȸ���Դϴ�!");
    }
    else
    {
        printf("ȸ���� �ƴմϴ�!");
    }
#pragma endregion


    return 0;
}