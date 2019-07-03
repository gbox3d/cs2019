// tge_exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../../../cstudy/engine/tge.h"

int main()
{
	HANDLE hStdOut;
	TGE::startTGE(&hStdOut);
	//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	char szTokens[8][TGE::MAX_TOKEN_SIZE];
	char szBuf[256];

	int bLoop = true;

	TGE::input::setEditMode();

	while (bLoop) {
		puts("명령어를 입력하세요.(v1.0)");
		gets_s(szBuf,sizeof(szBuf));

		int tokenCount = TGE::doTokenize(szBuf, szTokens);
		if (strcmp(szTokens[0], "exit") == 0)
		{
			bLoop = false;
		}
		else if (strcmp(szTokens[0], "clear") == 0) 
		{
			TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x009f);
			TGE::updateBuffer(hStdOut, TGE::g_chiBuffer);
		}
		else if (strcmp(szTokens[0], "setChar") == 0)
		{
			TGE::setCharacter(TGE::g_chiBuffer,10,10, TEXT('A'), 0x00fc);
			
			TGE::updateBuffer(hStdOut, TGE::g_chiBuffer);
		}
		else {
			printf_s("%s 는 알수없는 명령어 입니다.\n", szTokens[0] );
		}

		/*
		for (int i = 0; i < tokenCount; i++)
		{
			puts(szTokens[i]);
		}*/

	}

	//TGE::endTGE();
	return 0;
}


