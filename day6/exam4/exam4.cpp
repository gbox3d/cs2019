// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int sumint(int num1, int num2);
int subInt(int num1, int num2);

int main()
{	
	int result;

	result = sumint(2, 3);
	printf_s("%d\n", result );

	printf_s("%d\n", sumint(3, 3));
	printf_s("%d\n", sumint(4, 3));

	printf_s("%d\n", subInt(7, 2)); //7-2 = 5    
}

//+
int sumint(int num1, int num2)
{
	int num3 = num1 + num2;
	return num3;
}

// -
int subInt(int num1, int num2)
{
	//...
	int num3 = num1 - num2;
	return num3;
}
