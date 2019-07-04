// tge_exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../../../cstudy/engine/tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	int bLoop = true;
	while (bLoop)
	{
		if (TGE::input::g_KeyTable[VK_RETURN]) //커멘드모드 진입(동기모드)
		{
			TGE::input::pauseInputThread();
			TGE::input::setEditMode();

			//...동기식 코드 
			char szBuf[256];
			TGE::setCursor(hStdout, 0, 26);
			puts(">                            ");
			TGE::setCursor(hStdout, 1, 26);
			gets_s(szBuf);
			int tokenNum = TGE::Tokenize(szBuf);

			if (tokenNum > 0)
			{
				if (strcmp(TGE::g_szTokens[0], "exit") == 0)
				{
					bLoop = false;
					puts("종료합니다.");
				}
				else if (strcmp(TGE::g_szTokens[0], "setchar") == 0)
				{
					TGE::setCharacterW(TGE::g_chiBuffer,
						atoi(TGE::g_szTokens[1]),
						atoi(TGE::g_szTokens[2]),
						0x0020,0x00f9
					);
				}
				else if (strcmp(TGE::g_szTokens[0], "update") == 0)
				{
					TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
				}
				else
				{
					puts("알수없는 명령어");
				}			
			}
			TGE::input::g_KeyTable[VK_RETURN] = false; //키버퍼 클리어...
			TGE::input::setNormalMode();
			TGE::input::resumeInputThread();
		}

		TGE::setCursor(hStdout,0, 26);
		//printf_s("%d", TGE::input::g_KeyTable[VK_RETURN]);
	}
	TGE::endTGE();
}

