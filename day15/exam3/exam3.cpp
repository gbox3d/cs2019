// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\\cstudy\engine\irrlicht\include\irrlicht.h"
#include "..\..\\..\\cstudy\engine\tge.h"

#include "playerObject.h"

PlayerObject::S_OBJ g_playerObj;

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	bool bLoop = true;
	UINT64 _tick = TGE::util::GetTimeMs64();

	PlayerObject::init(&g_playerObj, NULL);
	g_playerObj.m_fSpeed = 1.0;
	g_playerObj.m_vPos = irr::core::vector2df(40, 12);

	while (bLoop)
	{
		UINT64 _delta = TGE::util::GetTimeMs64() - _tick;
		_tick = TGE::util::GetTimeMs64();
		double _fDelta = _delta / 1000.0;

		PlayerObject::apply((void *)&g_playerObj, _fDelta);

		TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);

		PlayerObject::draw((void *)&g_playerObj);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
		TGE::setCursor(hStdout, 0, 25);

	}
	TGE::endTGE();
}

