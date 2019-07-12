#include "..\..\..\cstudy\engine\tge.h"
#include "editor.h"


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

void parse_clear(void* pObj)
{
	clearScreen(atoi(((char(*)[64])pObj)[1]));
}

void parse_SaveMapData(void* pObj)
{
	char* fileName = ((char(*)[64])pObj)[1];
	if (saveMapData(fileName) == 0)
	{
		puts("저장 했습니다.");
	}
	else {
		puts("저장 실패");
	}
	
}

void parse_LoadMapData(void* pObj)
{
	char* fileName = ((char(*)[64])pObj)[1];
	if (loadMapData(fileName) == 0)
	{
		puts("읽기 완료");
	}
	else 
	{
		puts("읽기 실패");

	}
	//TGE::loadBufferBinary(pBackBuf, fileName);
		
}

//getTile x y
void parse_getTileAttribute(void* pObj)
{
	/*CHAR_INFO *pChr = TGE::getCharacter(pBackBuf,
		atoi(((char(*)[64])pObj)[1]),//x
		atoi(((char(*)[64])pObj)[2]) //y
	);*/

	int x = atoi(((char(*)[64])pObj)[1]);
	int y = atoi(((char(*)[64])pObj)[2]);
	int attr = getTileAttribute(x,y);

	printf_s("[tile : %d]",attr);

}

//drawHLine length
void parse_DrawHLine(void* pObj)
{
	int _cx, _cy;
	getCursorPos(&_cx, &_cy);
	int nLength = atoi(((char(*)[64])pObj)[1]); //길이
	int nDir = atoi(((char(*)[64])pObj)[2]);
	
	DrawHLine(_cx, _cy, nLength, nDir,getCursorAttr());
	
}

//drawLine length angle
void parse_DrawLine(void* pObj)
{
	int _cx, _cy;
	getCursorPos(&_cx, &_cy);
	int nLength = atoi(((char(*)[64])pObj)[1]); //길이
	double dy = atof(((char(*)[64])pObj)[2]);

	DrawLine(_cx, _cy, nLength,dy);
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