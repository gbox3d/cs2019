// exodos.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"
#include "worldmap.h"

WorldMap::S_OBJ g_LevelManager;

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	WorldMap::init(&g_LevelManager);

	bool bLoop = true;
	while (bLoop)
	{
		WorldMap::apply(&g_LevelManager, 0);
		WorldMap::draw(&g_LevelManager);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //화면에 보이게..
	}

	WorldMap::release(&g_LevelManager);
	TGE::endTGE();

	return 0;
}
