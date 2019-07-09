// exam_room1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);	
	TGE::hideCursor(hStdout);

	S_PlayerObject playerObj;
	initPlayerObject(&playerObj, "랜디");
	playerObj.m_fXpos = 30;
	playerObj.m_fYpos = 10;

	int bLoop = true;
	
	UINT64 ddwTick = TGE::util::GetTimeMs64();

	UINT64 accTick =0;

	while (bLoop) {

		if (TGE::input::g_KeyTable[VK_RETURN]) {
			//동기식 입력 처리 
			TGE::input::pauseInputThread();
			TGE::input::setEditMode();

			TGE::showCursor(hStdout);
			TGE::setCursor(hStdout, 0, 27);
			char szBuf[256];
			gets_s(szBuf, sizeof(szBuf));

			int tokenNum = TGE::Tokenize(szBuf); //TGE::g_szTokens 에 토큰 저장 
			if (tokenNum > 0) {
				if (!strcmp(TGE::g_szTokens[0], "exit")) {
					bLoop = false;
					TGE::setCursor(hStdout, 0, 26);
					puts("종료합니다.");
				}
				else {
					TGE::setCursor(hStdout, 0, 27);
					puts("                        ");

				}
			}
			//커서 다시 숨기기 
			TGE::hideCursor(hStdout);
			TGE::input::g_KeyTable[VK_RETURN] = false;

			TGE::input::setNormalMode();
			TGE::input::resumeInputThread();
		}

		UINT64 _deltaTick = TGE::util::GetTimeMs64() - ddwTick;
		ddwTick = TGE::util::GetTimeMs64();
		accTick += _deltaTick;

		applyPlayerObject(&playerObj, _deltaTick/1000.0); //입력 처리 , 행동에 대한처리 

		TGE::clearScreenBuffer(TGE::g_chiBuffer,0x0020,0x0000);

		DrawPlayerObject(&playerObj,TGE::g_chiBuffer); //그리기 

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //우리눈에 보이게 되는 과정

		TGE::setCursor(hStdout,0, 26);
		
		printf_s("%4.2f,%4.2f   %llu      \n", playerObj.m_fXpos, playerObj.m_fYpos, accTick);

	}

	TGE::endTGE();

	releasePlayerObject(&playerObj);

	return 0;
}
