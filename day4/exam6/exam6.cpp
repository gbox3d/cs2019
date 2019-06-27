// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

int main()
{
    //std::cout << "Hello World!\n";
	int num = 12;
	printf_s("10진수:%d 8진수:%o 16진수:%x", num, num, num);

	char _szBuf[256];

	sprintf_s(_szBuf, sizeof(_szBuf), "10진수:%d 8진수:%o 16진수:%x", num, num, num);

	MessageBoxA(NULL,_szBuf,"",MB_OK);
	
}
