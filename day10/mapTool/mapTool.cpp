// mapTool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

extern CHAR_INFO* pBackBuf;
void applyEditor();

int main()
{
	int bLoop = true;

	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	pBackBuf = TGE::CreateScreenBuffer();
	TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0090);

	while (bLoop)
	{
		/*char szBuf[256];
		gets_s(szBuf);
		int tokenNum = TGE::Tokenize(szBuf);
		if (!strcmp("exit", TGE::g_szTokens[0])) {
			bLoop = false;
			puts("exit program....");
		}
		else {
			puts("알수 없는 명령어입니다.");
		}*/
		applyEditor();
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
		
	}
	TGE::endTGE();
	return 0;
}
