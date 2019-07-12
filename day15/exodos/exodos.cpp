// exodos.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"
#include "worldmap.h"
#include "playerObject.h"

WorldMap::S_OBJ g_LevelManager;
PlayerObject::S_OBJ g_objPlayer;

int g_nFsm; //유한 상태기계(오토마타 )

const char* g_szLevels[256] = {
	"../res/level1.map",
	"../res/level2.map"
};

int g_nCurrentLevel = 0;

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	WorldMap::init(&g_LevelManager);

	PlayerObject::init(&g_objPlayer, &g_LevelManager);
	

	UINT64 _worktick = TGE::util::GetTimeMs64();

	g_nFsm = 0;


	bool bLoop = true;
	while (bLoop)
	{
		UINT64 _deltaTick = TGE::util::GetTimeMs64() - _worktick;
		_worktick = TGE::util::GetTimeMs64();
		double fDelta = _deltaTick / 1000.0;

		switch (g_nFsm)
		{
		case 0:
		{
			TGE::setCursor(hStdout, 0, 25);
			puts("시작 하려면 스페이스바 hit!");
			if (TGE::input::g_KeyTable[VK_SPACE]) {
				TGE::input::g_KeyTable[VK_SPACE] = false;
				g_nFsm = 1; 
				g_nCurrentLevel = 0;
			}
		}	
			break;
		case 1:
		{
			WorldMap::readWorldData(&g_LevelManager, g_szLevels[g_nCurrentLevel], g_nCurrentLevel);
			g_objPlayer.m_fXpos = g_LevelManager.m_posRegen[0];
			g_objPlayer.m_fYpos = g_LevelManager.m_posRegen[1];
			g_nFsm = 10;
		}
			break;
		case 10:
		{
			//AI & action & animation(physics)
			PlayerObject::apply(&g_objPlayer, fDelta);
			WorldMap::apply(&g_LevelManager, fDelta);

			//Draw
			WorldMap::draw(&g_LevelManager);
			PlayerObject::draw(&g_objPlayer);
		}
			break;
		case 20:
		{
			TGE::clearScreenBuffer(TGE::g_chiBuffer,0x0020,0x0000);
			TGE::setCursor(hStdout, 0, 25);
			puts("다음 레벨을 시작하려면 스페이스바 hit!");
			g_nFsm = 21;
		}
		break;
		case 21:
		{ //다음 레벨로 가기 
			if ( TGE::input::g_KeyTable[VK_SPACE] ) {
				g_nCurrentLevel++;
				if (g_nCurrentLevel >= 2) {
					g_nFsm = 100; //game over
				}
				else {
					g_nFsm = 1;
				}
			}
		}
			break;
		case 100:
		{
			TGE::setCursor(hStdout, 0, 25);
			puts("     탈출 성공                             ");

			g_nFsm = 101; // 대기상태
		}
			break;
		default:
			break;
		}

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //화면에 보이게..
	}

	WorldMap::release(&g_LevelManager);
	TGE::endTGE();

	return 0;
}
