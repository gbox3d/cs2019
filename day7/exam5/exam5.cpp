// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

const int g_cScreenBufSize = 64; //8*8

void _put(CHAR_INFO chiBuffer[],int x,int y)
{	
	chiBuffer[(y * 4 + x) * 2].Char.UnicodeChar = 0x25A0;
	chiBuffer[(y * 4 + x) * 2].Attributes = COMMON_LVB_LEADING_BYTE | 0x009f;

	chiBuffer[(y * 4 + x) * 2 + 1].Char.UnicodeChar = 0x25A0;
	chiBuffer[(y * 4 + x) * 2 + 1].Attributes = COMMON_LVB_TRAILING_BYTE | 0x009f;
}

int main()
{
	system("cls");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO chiBuffer[g_cScreenBufSize];

	//clear
	for (int i = 0; i < g_cScreenBufSize / 2; i++) 
	{
		//유니코드에서 속성적용 
		//첫번째 바이트는 캐릭터의 좌우 선택 1->left , 2->right
		//두번째 바이트가 컬러속성,컬러 체계는 8421 -> IRGB 
		chiBuffer[i * 2].Char.UnicodeChar = 0x00;//0x25ce;//TEXT('◎');
		chiBuffer[i * 2].Attributes = COMMON_LVB_LEADING_BYTE | 0x009f; //첫번째 왼쪽표시
		chiBuffer[i * 2 + 1].Char.UnicodeChar = 0x00;// 0x25ce; //TEXT('◎');
		chiBuffer[i * 2 + 1].Attributes = COMMON_LVB_TRAILING_BYTE | 0x009f; //나머지 반절표시 
	}

	_put(chiBuffer, 1, 2);
	_put(chiBuffer, 1, 3);
	_put(chiBuffer, 1, 4);
	//_put(chiBuffer, 1, 1);

	SMALL_RECT destRect;
	destRect.Top = 0;
	destRect.Left = 0;
	destRect.Bottom = 7;
	destRect.Right = 7;

	WriteConsoleOutput(
		hStdout, // screen buffer to write to 
		chiBuffer,        // buffer to copy from 
		{8,8},     // col-row size of chiBuffer 
		{ 0,0 },    // top left src cell in chiBuffer 
		&destRect);  // dest. screen buffer rectangle 

	return 0;
}
