// exam_room1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"

int map[2000];

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
	TGE::loadBufferBinary(pBackBuf, "level1.map");
	//TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0000);

	int regenPosX =0, regenPosY=0;

	for (int iy = 0; iy < 25; iy++)
	{
		for (int ix = 0; ix < 80; ix++)
		{
			int nIndex = iy * 80 + ix;

			//printf_s("%d \n", tempBuff[nIndex].Attributes);
			
			if (pBackBuf[nIndex].Attributes == 0xF0) {
				map[nIndex] = 1;
			}
			else if (pBackBuf[nIndex].Attributes == 0x40) { //리젠포인트 
				regenPosX = ix;
				regenPosY = iy;
				pBackBuf[nIndex].Attributes = 0x00;
			}
			else {
				map[nIndex] = 0;
			}

		}
	}
	

	playerObj.m_fXpos = regenPosX;
	playerObj.m_fYpos = regenPosY;

	int nFsm = 0;

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

		switch (nFsm)
		{
		case 0:
		{
			TGE::setCursor(hStdout, 0, 0);
			printf_s("당신은 낮선 방에서 혼자 정신을 잃고 쓰러져있었습니다.");
			TGE::setCursor(hStdout, 0, 1);
			printf_s("<진행하려면 스페이스바....>");
			if (TGE::input::g_KeyTable[VK_SPACE]) {
				nFsm = 10;
				TGE::input::g_KeyTable[VK_SPACE] = false; //여러번 눌림 방지 
			}
		}
			break;
		case 10:
		{
			applyPlayerObject(&playerObj, _deltaTick / 1000.0, map); //입력 처리 , 행동에 대한처리 

			TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);

			TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);//배경 그리기
			DrawPlayerObject(&playerObj, TGE::g_chiBuffer); //배경위에 캐릭터 그리기 
			//TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);//배경 그리기

			TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //우리눈에 보이게 되는 과정

			TGE::setCursor(hStdout, 0, 26);

			printf_s("%4.2f,%4.2f   %llu      \n", playerObj.m_fXpos, playerObj.m_fYpos, accTick);

			int _chrposIndex = (int)playerObj.m_fYpos * 80 + (int)playerObj.m_fXpos;

			printf_s("  %x    \n", pBackBuf[_chrposIndex].Attributes);

		}
			break;
		default:
			break;
		}

		
	}

	TGE::endTGE();

	free(pBackBuf);
	releasePlayerObject(&playerObj);

	TGE::showCursor(hStdout);

	return 0;
}
