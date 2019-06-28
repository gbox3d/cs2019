// exam7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;

	if (GetConsoleScreenBufferInfo(hConsole, &csbInfo) == 0) 
	{
		printf_s("스크린 버퍼를 얻지못했습니다.\n");
	}
	else 
	{
		WORD wOldColor = csbInfo.wAttributes;
		SetConsoleTextAttribute(hConsole, 0x0c); //0000 1100  //red
		printf_s("hello \n");
		SetConsoleTextAttribute(hConsole, 0x0a); //0000 1010 // Green
		printf_s("hello \n");
		SetConsoleTextAttribute(hConsole, 0x09); //0000 1001 // Blue
		printf_s("hello \n");

		SetConsoleTextAttribute(hConsole, 0xfc); //1111 1100 // 흰색 바탕에 빨간글씨
		printf_s("hello \n");
		SetConsoleTextAttribute(hConsole, 0xf4); //1111 0100 // 흰색 바탕에 빨간글씨
		printf_s("hello \n");

		SetConsoleTextAttribute(hConsole, wOldColor); //원래 색상으로 돌려주기 

	}

	return 0;
}
