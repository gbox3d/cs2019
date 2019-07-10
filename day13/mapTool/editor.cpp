#include "..\..\..\cstudy\engine\tge.h"

int cursor_x = 0;
int cursor_y = 0;
int cursorAttr = 0xf0;

CHAR_INFO* pBackBuf;

int _Table[] = {
		0x00,
		0xc0,0x40, //¹àÀº »¡°£,¾îµÎ¿î »¡°£
		0xa0,0x20, //³ì»ö
		0x90,0x10,
		0xF0,0x80
};

void changeCursorColor(int nColor)
{	
	cursorAttr = _Table[nColor];
}

void moveCursor(int x,int y)
{
	cursor_x = x;
	cursor_y = y;
}
void clearScreen(int nColor)
{
	TGE::clearScreenBuffer(pBackBuf,
		0x0020,
		_Table[nColor]
	);
}

void applyEditor(HANDLE hStdout)
{
	if (TGE::input::g_KeyTable[VK_UP]) {
		cursor_y--;
		TGE::input::g_KeyTable[VK_UP] = false;
	}
	if (TGE::input::g_KeyTable[VK_DOWN]) {
		cursor_y++;
		TGE::input::g_KeyTable[VK_DOWN] = false;
	}
	if (TGE::input::g_KeyTable[VK_LEFT]) {
		cursor_x--;
		TGE::input::g_KeyTable[VK_LEFT] = false;
	}
	if (TGE::input::g_KeyTable[VK_RIGHT]) {
		cursor_x++;
		TGE::input::g_KeyTable[VK_RIGHT] = false;
	}
	if (TGE::input::g_KeyTable[VK_SPACE]) {

		TGE::setCharacter(pBackBuf, cursor_x, cursor_y, 0x0020, cursorAttr);

		TGE::input::g_KeyTable[VK_SPACE] = false;
	}

	//TGE::clearScreenBuffer(0x0020, 0x0090); //È­¸é Å¬¸®¾î 
	TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);
	TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x0020, 0x00f0); //Ä¿¼­ Ãâ·Â 

	TGE::setCursor(hStdout,0, 26);
	printf_s("%-4d,%-4d,%-4d", cursor_x, cursor_y, cursorAttr);
}