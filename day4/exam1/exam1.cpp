// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int main()
{
	char _a = 'A';
	const char *_b = "hello";
	char _c[16] = "world"; //16byte 문자배열
	printf_s("%c \n", _a);
	printf_s("%s \n", _b);
	printf_s("%s \n", _c);
	//입력
	char _code;
	char _name[32];
	printf_s("코드 문자 입력 :"); scanf_s("%c", &_code,1);
	printf_s("이름 입력 :"); scanf_s("%s", _name,32);

	printf_s("입력 하신 코드 번호는 %c , 이름은 %s 입니다. 맞나요?(y/n) \n", _code, _name);


}
