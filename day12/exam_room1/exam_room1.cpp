// exam_room1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"

int map[64] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,10,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);	
	TGE::hideCursor(hStdout);

	S_PlayerObject playerObj;
	initPlayerObject(&playerObj, "랜디");
	

	int bLoop = true;
	
	UINT64 ddwTick = TGE::util::GetTimeMs64();
	UINT64 accTick =0;

	CHAR_INFO* pBackBuf = TGE::CreateScreenBuffer();

	TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0000);

	int regenPosX, regenPosY;

	for (int iy = 0; iy < 8; iy++)
	{
		for (int ix = 0; ix < 8; ix++)
		{
			int nTileIndex = map[iy * 8 + ix];
			if (nTileIndex == 1) {
				TGE::setCharacter(pBackBuf, ix, iy, 0x0020, 0x00a0);
			}
			else if (nTileIndex) {
				regenPosX = ix; //리젠 위치 찾기 
				regenPosY = iy;
			}
			else {
				TGE::setCharacter(pBackBuf, ix, iy, 0x0020, 0x0000);
			}
		}
	}

	playerObj.m_fXpos = regenPosX;
	playerObj.m_fYpos = regenPosY;

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

		applyPlayerObject(&playerObj, _deltaTick/1000.0, map); //입력 처리 , 행동에 대한처리 

		TGE::clearScreenBuffer(TGE::g_chiBuffer,0x0020,0x0000);

		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);//배경 그리기
		DrawPlayerObject(&playerObj,TGE::g_chiBuffer); //배경위에 캐릭터 그리기 
		//TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);//배경 그리기

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //우리눈에 보이게 되는 과정

		TGE::setCursor(hStdout,0, 26);
		
		printf_s("%4.2f,%4.2f   %llu      \n", playerObj.m_fXpos, playerObj.m_fYpos, accTick);

		int _chrposIndex = (int)playerObj.m_fYpos * 80 + (int)playerObj.m_fXpos;

		printf_s("  %x    \n", pBackBuf[_chrposIndex].Attributes);
	}

	TGE::endTGE();

	releasePlayerObject(&playerObj);

	return 0;
}
