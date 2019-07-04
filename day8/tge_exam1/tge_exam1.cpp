// tge_exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../../../cstudy/engine/tge.h"

int main()
{
	HANDLE hStdout; TGE::startTGE(&hStdout);	
	char szBuf[256];
	int bLoop = true;
	TGE::hideCursor(hStdout);
	while (bLoop) {	

		if (TGE::input::g_KeyTable[VK_RETURN])
		{
			TGE::input::pauseInputThread(); //입력쓰레드를 동기입력 모드로
			TGE::input::setEditMode();

			TGE::showCursor(hStdout);
			TGE::setCursor(hStdout, 0, 1);
			gets_s(szBuf,sizeof(szBuf));
			if (!strcmp(szBuf, "exit"))
			{
				bLoop = false;
				puts("종료 합니다");
			}

			TGE::input::setNormalMode();
			TGE::input::resumeInputThread();
			TGE::input::g_KeyTable[VK_RETURN] = false; //재입력방지
		}

		TGE::setCursor(hStdout, 0, 0);
		printf_s("U%-4dD%-4dL%-4dR%-4d",
			TGE::input::g_KeyTable[VK_UP],
			TGE::input::g_KeyTable[VK_DOWN],
			TGE::input::g_KeyTable[VK_LEFT],
			TGE::input::g_KeyTable[VK_RIGHT]
		);
	}

	TGE::endTGE();
	return 0;
}


