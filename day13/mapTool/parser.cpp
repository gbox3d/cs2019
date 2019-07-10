#include "..\..\..\cstudy\engine\tge.h"

extern CHAR_INFO* pBackBuf;
void changeCursorColor(int nColor);
void moveCursor(int x, int y);
void getCursorPos(int* curX, int* curY);
int getCursorAttr();

void parse_chgcolor(void* pObj)
{
	changeCursorColor(
		atoi(((char(*)[64])pObj)[1])
	);
}
void parse_moveCursor(void* pObj)
{
	moveCursor(
		atoi(((char(*)[64])pObj)[1]),
		atoi(((char(*)[64])pObj)[2])
	);
}

void clearScreen(int nColor);

void parse_clear(void* pObj)
{
	clearScreen(atoi(((char(*)[64])pObj)[1]));
}

/*
struct S_FunctionTable
{
	const char* m_szNameTable[64];
	void* m_arFpHandler[64];
};

S_FunctionTable g_FunctionTale;

void addFunctionTable(const char *pszName,void *fp)
{
	g_FunctionTale.m_arFpHandler[]

}
*/

void parse_SaveMapData(void* pObj)
{
	char* fileName = ((char(*)[64])pObj)[1];
	TGE::saveBufferBinary(pBackBuf, fileName);
	puts("저장 했습니다.");
}

void parse_LoadMapData(void* pObj)
{
	char* fileName = ((char(*)[64])pObj)[1];
	TGE::loadBufferBinary(pBackBuf, fileName);
	puts("읽기 완료");
}

//getTile x y
void parse_getTileAttribute(void* pObj)
{
	CHAR_INFO *pChr = TGE::getCharacter(pBackBuf,
		atoi(((char(*)[64])pObj)[1]),//x
		atoi(((char(*)[64])pObj)[2]) //y
	);

	printf_s("[tile : %d]",pChr->Attributes);

}

//drawHLine length
void parse_DrawHLine(void* pObj)
{
	int _cx, _cy;
	getCursorPos(&_cx, &_cy);
	int nLength = atoi(((char(*)[64])pObj)[1]); //길이
	int nDir = atoi(((char(*)[64])pObj)[2]);
	
	for (int i = 0; i < nLength; i++)
	{
		TGE::setCharacter(pBackBuf, _cx+(i*nDir), _cy, 0x0020, getCursorAttr());
	}
}

//drawLine length angle
void parse_DrawLine(void* pObj)
{
	int _cx, _cy;
	getCursorPos(&_cx, &_cy);
	int nLength = atoi(((char(*)[64])pObj)[1]); //길이

	double _x, _y;
	double _dx, _dy;

	_dx = 1.0;
	_dy = atof(((char(*)[64])pObj)[2]);

	
	double __len =  sqrt( (_dx * _dx) + (_dy * _dy) );

	_dx /= __len;
	_dy /= __len;

	_x = _cx;
	_y = _cy;

	for (int i = 0; i < nLength; i++)
	{	
		TGE::setCharacter(pBackBuf, _x ,_y  , 0x0020, getCursorAttr());
		_x += _dx;
		_y += _dy;
	}
}




const char* nameTable[] = {
	"drawLine",
	"drawHLine",
	"getTile",
	"loadMap",
	"saveMap",
	"chgColor", //chgColor color
	"mvCursor", //moveCursor xpos ypos
	"clear" //clear color
};

void* arrayHandlers[] = {
	parse_DrawLine,
	parse_DrawHLine,
	parse_getTileAttribute,
	parse_LoadMapData,
	parse_SaveMapData,
	parse_chgcolor,
	parse_moveCursor,
	parse_clear
};

void parseCommand()
{
	for (int i = 0; i < sizeof(nameTable) / sizeof(nameTable[0]); i++)
	{
		if (strcmp(nameTable[i], TGE::g_szTokens[0]) == 0) {
			((void (*)(void*))arrayHandlers[i])(TGE::g_szTokens);
			break;
		}
	}
}