
#include "..\..\..\cstudy\engine\tge.h"
#include "worldmap.h"
#include "playerObject.h"

extern int g_nFsm;

namespace PlayerObject {
	void init(void* pObj, void* pMap)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		ptrThis->m_fXpos = 0;
		ptrThis->m_fYpos = 0;
		ptrThis->m_fSpeed = 2.0;
		ptrThis->m_pMap = pMap;	
		ptrThis->m_nStatus_HaveKey = 0;
		//strcpy_s(pObj->m_szName, 64,pszName);
	}

	void release(void* pObj)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;

	}

	void apply(void* pObj, double _fDelta)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		WorldMap::S_OBJ *pMap =  (WorldMap::S_OBJ*)ptrThis->m_pMap;

		double _delta = (ptrThis->m_fSpeed * _fDelta);

		double _oldx, _oldy;

		_oldx = ptrThis->m_fXpos;
		_oldy = ptrThis->m_fYpos;

		if (TGE::input::g_KeyTable[VK_UP]) {			
			ptrThis->m_fYpos -= _delta;
		}
		else if (TGE::input::g_KeyTable[VK_DOWN]) {
			ptrThis->m_fYpos += _delta;
		}
		else if (TGE::input::g_KeyTable[VK_RIGHT]) {
			ptrThis->m_fXpos += _delta;
		}
		else if (TGE::input::g_KeyTable[VK_LEFT]) {
			ptrThis->m_fXpos -= _delta;
		}
		else if (TGE::input::g_KeyTable['G']) {

			TGE::input::g_KeyTable['G'] = false;

			//열쇠와 좌표가 같은지?
			if (
				pMap->m_posKey[0] == (int)ptrThis->m_fXpos &&
				pMap->m_posKey[1] == (int)ptrThis->m_fYpos
				)
			{
				pMap->m_nstatusKey = 0;
				ptrThis->m_nStatus_HaveKey++;
			}
			
		}
		else if (TGE::input::g_KeyTable['U']) {
			
			TGE::input::g_KeyTable['U'] = false;
			if (ptrThis->m_nStatus_HaveKey >= 1) //열쇠를 가지고있다?
			{
				int _x = (int)ptrThis->m_fXpos;
				int _y = (int)ptrThis->m_fYpos;
				//근처에 문이있는지 검사 
				if (
					(pMap->m_posExit[0] == _x && pMap->m_posExit[1] == _y-1) ||
					(pMap->m_posExit[0] == _x && pMap->m_posExit[1] == _y+1) ||
					(pMap->m_posExit[0] == _x-1 && pMap->m_posExit[1] == _y) ||
					(pMap->m_posExit[0] == _x+1 && pMap->m_posExit[1] == _y)
					
					) {
					pMap->m_nstatusExit = 0;//문열림
				}
			}
		}
		
		//막힌곳인가?
		if (pMap->m_pBackBuf[(int)ptrThis->m_fYpos * 80 + (int)ptrThis->m_fXpos].Attributes == 240 ||
			pMap->m_pBackBuf[(int)ptrThis->m_fYpos * 80 + (int)ptrThis->m_fXpos].Attributes == 144 
			)
		{
			ptrThis->m_fXpos = _oldx;
			ptrThis->m_fYpos = _oldy;

		}
		//문이있는가?
		else if ( pMap->m_posExit[0] == (int)ptrThis->m_fXpos && pMap->m_posExit[1] == (int)ptrThis->m_fYpos)
		{
			if (pMap->m_nstatusExit) {
				ptrThis->m_fXpos = _oldx;
				ptrThis->m_fYpos = _oldy;
			}
		}

		//포탈에 들어갔는가?
		if (pMap->m_posPortal[0] == (int)ptrThis->m_fXpos && pMap->m_posPortal[1] == (int)ptrThis->m_fYpos)
		{
			g_nFsm = 20;
		}

	}

	void draw(void* pObj)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		WorldMap::S_OBJ* pMap = (WorldMap::S_OBJ*)ptrThis->m_pMap;

		TGE::setCharacter(TGE::g_chiBuffer, (int)ptrThis->m_fXpos, (int)ptrThis->m_fYpos,
			0x0020,
			0x00F0
		);
	}



}

