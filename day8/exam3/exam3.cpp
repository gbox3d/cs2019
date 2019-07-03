// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

int getStringLength(char strTemp[], int nBufSize);

int main()
{
	char szBuf[256];

	gets_s(szBuf, sizeof(szBuf));

	printf_s("%s \n", szBuf);

	int nLength = getStringLength(szBuf, sizeof(szBuf));

	printf_s("문자열의 길이 : %d \n", nLength);

	return 0;
}
