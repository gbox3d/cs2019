// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

int main()
{
	double num1, num2, result;
	printf_s("두개의 수를 입력하세요 : ");
	scanf_s("%lf %lf", &num1, &num2);

	result = (num1 + num2) / 2.0;

	printf_s("결과는 : %lf \n", result);

	printf_s("결과는 :  %d  \n", (int) (&num1) - (int)(&result) );


	return 0;    
}

