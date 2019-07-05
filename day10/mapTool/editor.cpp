#include "..\..\..\cstudy\engine\tge.h"

int cursor_x = 0;
int cursor_y = 0;

CHAR_INFO* pBackBuf;

void applyEditor()
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

		TGE::setCharacter(pBackBuf, cursor_x, cursor_y, 0x0020, 0x00f0);

		TGE::input::g_KeyTable[VK_SPACE] = false;
	}

	//TGE::clearScreenBuffer(0x0020, 0x0090); //화면 클리어 
	TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);
	TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x0020, 0x00f0); //커서 출력 
}