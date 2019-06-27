// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int main()
{
	double days = 365.2422;

	double _day = days - 365;

	printf_s("%lf \n", _day);

	printf_s("h : %lf \n", _day * 24);
	return 0;
}
