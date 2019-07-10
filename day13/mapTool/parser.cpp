#include "..\..\..\cstudy\engine\tge.h"

extern CHAR_INFO* pBackBuf;
void changeCursorColor(int nColor);
void moveCursor(int x, int y);

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

const char* nameTable[] = {
	"loadMap",
	"saveMap",
	"chgColor", //chgColor color
	"mvCursor", //moveCursor xpos ypos
	"clear" //clear color
};

void* arrayHandlers[] = {
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