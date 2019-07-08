// mapTool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

extern CHAR_INFO* pBackBuf;
void changeCursorColor(int nColor);
void applyEditor(HANDLE hStdout);

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
			else if (!strcmp("chgcolor", TGE::g_szTokens[0])) {
				
				changeCursorColor(
					atoi( TGE::g_szTokens[1] ) 
				);
			}
			else {
				puts("알수 없는 명령어입니다.");
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
