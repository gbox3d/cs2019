// exodos.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"
#include "worldmap.h"
#include "playerObject.h"

WorldMap::S_OBJ g_LevelManager;
PlayerObject::S_OBJ g_objPlayer;

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	WorldMap::init(&g_LevelManager,"../res/level1.map");
	

	PlayerObject::init(&g_objPlayer, &g_LevelManager);
	g_objPlayer.m_fXpos = g_LevelManager.m_posRegen[0];
	g_objPlayer.m_fYpos = g_LevelManager.m_posRegen[1];

	UINT64 _worktick = TGE::util::GetTimeMs64();

	bool bLoop = true;
	while (bLoop)
	{
		UINT64 _deltaTick = TGE::util::GetTimeMs64() - _worktick;
		_worktick = TGE::util::GetTimeMs64();
		double fDelta = _deltaTick / 1000.0;

		//AI & action & animation(physics)
		PlayerObject::apply(&g_objPlayer, fDelta);
		WorldMap::apply(&g_LevelManager, fDelta);
		
		//Draw
		WorldMap::draw(&g_LevelManager);
		PlayerObject::draw(&g_objPlayer);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //화면에 보이게..
	}

	WorldMap::release(&g_LevelManager);
	TGE::endTGE();

	return 0;
}
