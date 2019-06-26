// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

int main()
{
	int num = 10;
	
	int num2;	
	num = 20;
	num2 = num;

	//scanf_s("%d", &num);
	/*
	printf_s("%d \n",num);
	*/

	//12 13 
	printf_s("정수 2개 입력 하세요 (구분은 공백으로) =>");
	scanf_s("%d %d", &num, &num2);
	printf_s("%d %d\n", num,num2);

	printf_s("정수 2개 입력 하세요 (구분은 /으로) =>");
	scanf_s("%d/%d", &num, &num2);
	printf_s("%d %d\n", num, num2);

	printf_s("정수 2개 입력 하세요 (구분은 개행으로) =>");
	scanf_s("%d\n", &num);
	scanf_s("%d", &num2);
	printf_s("%d %d\n", num, num2);

	return 0;
   
}
