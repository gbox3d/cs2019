// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

int main()
{
	char strTemp[256] = "hello";
	char strTemp2[] = "hello";
	char strTemp3[] = "트럼프";

	printf_s("배열의 크기 : %d \n",sizeof(strTemp));
	printf_s("배열의 크기 : %d \n", sizeof(strTemp2));
	printf_s("배열의 크기 : %d \n", sizeof(strTemp3));

	return 0;
}



