#include "..\..\..\cstudy\engine\tge.h"

int cursor_x = 0;
int cursor_y = 0;
int cursorAttr = 0xf0;
int cursorAttrSub = 0x00;

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

void getCursorPos(int *curX,int *curY)
{
	*curX = cursor_x;
	*curY = cursor_y;
}
int getCursorAttr()
{
	return cursorAttr;
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

int saveMapData(const char* fileName)
{
	return TGE::saveBufferBinary(pBackBuf, fileName);	
}

int loadMapData(const char* fileName)
{
	return TGE::loadBufferBinary(pBackBuf, fileName);
}

WORD getTileAttribute(int x,int y)
{
	CHAR_INFO* pChr = TGE::getCharacter(pBackBuf,x,y);

	return pChr->Attributes;

}

void DrawHLine(int _cx, int _cy, int nLength, int nDir,int attr)
{	
	for (int i = 0; i < nLength; i++)
	{
		TGE::setCharacter(pBackBuf, _cx + (i * nDir), _cy, 0x0020, attr);
	}
}

void DrawLine(int _cx,int _cy,int nLength,double _dy)
{
	//int _cx, _cy;
	//getCursorPos(&_cx, &_cy);
	//int nLength = atoi(((char(*)[64])pObj)[1]); //±æÀÌ

	double _x, _y;
	double _dx;

	_dx = 1.0;
	_dy = _dy;

	double __len = sqrt((_dx * _dx) + (_dy * _dy));

	_dx /= __len;
	_dy /= __len;

	_x = (double)_cx;
	_y = (double)_cy;

	for (int i = 0; i < nLength; i++)
	{
		TGE::setCharacter(pBackBuf, (int)_x, (int)_y, 0x0020, getCursorAttr());
		_x += _dx;
		_y += _dy;
	}
}

//-------------------

void setupEditor(HANDLE hStdout)
{
	pBackBuf = TGE::CreateScreenBuffer();
	TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0000);
}

void endEditor()
{
	free(pBackBuf);
}

void applyEditor(HANDLE hStdout)
{
	/*if (TGE::input::g_KeyTable[VK_UP]) {
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
	}*/
	cursor_x = TGE::input::g_cdMousePos.X;
	cursor_y = TGE::input::g_cdMousePos.Y;
	//¹üÀ§ Ã¼Å© 
	if (cursor_x < 0) { cursor_x = 0; }
	if (cursor_y < 0) { cursor_y = 0; }

	if (cursor_x >= 80) { cursor_x = 79; }
	if (cursor_y >= 25) { cursor_y = 24; }

	if (TGE::input::g_dwButtonState == 1) {
		TGE::setCharacter(pBackBuf, cursor_x, cursor_y, 0x0020, cursorAttr);
	}
	if (TGE::input::g_dwButtonState == 2) {
		TGE::setCharacter(pBackBuf, cursor_x, cursor_y, 0x0020, cursorAttrSub);
	}

	TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);
	TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x0020, cursorAttr); //Ä¿¼­ Ãâ·Â 

	TGE::setCursor(hStdout,0, 26);
	printf_s("%-4d,%-4d,%-4d , %-4d", cursor_x, cursor_y, cursorAttr,
		TGE::getCharacter(pBackBuf, cursor_x, cursor_y)->Attributes );
}