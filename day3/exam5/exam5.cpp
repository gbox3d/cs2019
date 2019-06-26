// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main()
{
	double _v,_result;
	printf_s("전기 사용량 :");
	scanf_s("%lf", &_v);

	_result = 660 + (88.5*_v);

	_result = _result + (_result * ((double)9/(double)100) );

	printf_s("%lf \n", _result);
	MessageBox(NULL, TEXT("결과는 :"), TEXT("정보창"), MB_OK);

   
}
