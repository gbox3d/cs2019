// mapTool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

extern CHAR_INFO* pBackBuf;
void changeCursorColor(int nColor);
void applyEditor(HANDLE hStdout);

void parse_chgcolor(void* pObj)
{
	changeCursorColor(
		atoi(((char(*)[64])pObj)[1])
	);
}

void test1(void *pObj)
{
	printf_s("test 1 %s \n", ((char(*)[64])pObj)[1]);
}
void test2(void* pObj)
{
	printf_s("test 2\n");
}
void test3(void* pObj)
{
	printf_s("test 3\n");
}

void moveCursor(int x, int y);

void parse_moveCursor(void* pObj)
{
	moveCursor(
		atoi(((char(*)[64])pObj)[1]),
		atoi(((char(*)[64])pObj)[2])
	);
}

const char* nameTable[] = {
	"test1",
	"test2",
	"test3",
	"chgcolor",
	"mvCursor" //moveCursor xpos ypos
};

void *arrayHandlers[] = {
	test1,
	test2,
	test3,
	parse_chgcolor,
	parse_moveCursor
};

int main()
{
	int bLoop = true;

	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	TGE::hideCursor(hStdout);

	pBackBuf = TGE::CreateScreenBuffer();
	TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0090);

	while (bLoop)
	{
		if (TGE::input::g_KeyTable[VK_RETURN]) {
			//동기식 입력 처리 
			TGE::input::pauseInputThread();
			TGE::input::setEditMode();

			TGE::showCursor(hStdout);
			TGE::setCursor(hStdout, 0, 27);

			char szBuf[256];
			gets_s(szBuf);
			int tokenNum = TGE::Tokenize(szBuf);
			if (!strcmp("exit", TGE::g_szTokens[0])) {
				bLoop = false;
				puts("exit program....");
			}

			//void* ptr = TGE::g_szTokens;
			//printf_s("%s \n", ((char(*)[64])ptr)[0]);
			

			for (int i = 0; i < sizeof(nameTable)/sizeof(nameTable[0]); i++)
			{
				if (strcmp(nameTable[i], TGE::g_szTokens[0]) == 0) {
					((void (*)(void *))arrayHandlers[i])(TGE::g_szTokens);
					break;
				}
			}
			

			//커서 다시 숨기기 
			TGE::hideCursor(hStdout);
			TGE::input::g_KeyTable[VK_RETURN] = false;

			TGE::input::setNormalMode();
			TGE::input::resumeInputThread();
		}
		
		applyEditor(hStdout);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
		
	}
	TGE::endTGE();
	return 0;
}
