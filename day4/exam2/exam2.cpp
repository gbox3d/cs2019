// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int main()
{
    //std::cout << "Hello World!\n"; 
	char _szBuf[256];
	int _krw = 15000;
	size_t cn;
	TCHAR _szwBuf[256];

	sprintf_s(_szBuf, "전기요금은 %d원입니다.", _krw);
	
	//mbstowcs_s(&cn,_szwBuf,256, _szBuf, 256);
	swprintf_s(_szwBuf,256, L"전기요금은 %d원입니다.", _krw);

	MessageBoxA(NULL, _szBuf, "타이들바 정보", MB_OK);
	MessageBox(NULL, _szwBuf, L"타이들바 정보", MB_OK);


}
