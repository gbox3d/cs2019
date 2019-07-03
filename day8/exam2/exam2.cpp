// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

//선언
int getStringLength(char strTemp[],int nBufSize);

int main()
{
	char strTemp[256];
	printf_s("문자열을 입력하세요 => ");
	scanf_s("%s", strTemp,sizeof(strTemp));

	int nCount = getStringLength(strTemp,sizeof(strTemp));

	printf_s("입력하신 문자열의 갯수는 %d \n", nCount);
    
}

