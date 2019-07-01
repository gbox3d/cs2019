// exam7_cursorControl.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	printf_s("hello");

	COORD _pos;
	_pos.X = 10;
	_pos.Y = 5;

	SetConsoleCursorPosition(hStdout, _pos);
	SetConsoleTextAttribute(hStdout, 0x9e);
	printf_s("world");

	_pos.X = 10;
	_pos.Y = 4;

	int num;
	SetConsoleCursorPosition(hStdout, _pos);
	scanf_s("%d", &num);
	
	int _ix, _iy;
	for (_iy = 8; _iy < 16; _iy++) 
	{
		for (_ix = 20; _ix < 28; _ix++)
		{
			_pos.X = _ix;
			_pos.Y = _iy;
			SetConsoleCursorPosition(hStdout, _pos);
			SetConsoleTextAttribute(hStdout, 0xae);
			printf_s(" ");

		}
	}

	SetConsoleTextAttribute(hStdout, 0x07);
	return 0;
}
