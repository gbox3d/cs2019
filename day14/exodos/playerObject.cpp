
#include "..\..\..\cstudy\engine\tge.h"
#include "worldmap.h"
#include "playerObject.h"

namespace PlayerObject {
	void init(void* pObj, void* pMap)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		ptrThis->m_fXpos = 0;
		ptrThis->m_fYpos = 0;
		ptrThis->m_fSpeed = 2.0;
		ptrThis->m_pMap = pMap;
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

		if (TGE::input::g_KeyTable[VK_UP]) {
			int chkX = (int)(ptrThis->m_fXpos);
			int chkY = (int)(ptrThis->m_fYpos-1);
			if (pMap->m_pBackBuf[chkY * 80 + chkX].Attributes == 0)
			{
				ptrThis->m_fYpos -= _delta;
			}
		}
		else if (TGE::input::g_KeyTable[VK_DOWN]) {
			int chkX = (int)(ptrThis->m_fXpos);
			int chkY = (int)(ptrThis->m_fYpos + 1);
			if (pMap->m_pBackBuf[chkY * 80 + chkX].Attributes == 0)
			{
				ptrThis->m_fYpos += _delta;
			}
		}
		else if (TGE::input::g_KeyTable[VK_RIGHT]) {

			int chkX = (int)(ptrThis->m_fXpos+1);
			int chkY = (int)(ptrThis->m_fYpos);
			if (pMap->m_pBackBuf[chkY * 80 + chkX].Attributes == 0)
			{
				ptrThis->m_fXpos += _delta;
			}
			
		}
		else if (TGE::input::g_KeyTable[VK_LEFT]) {
			int chkX = (int)(ptrThis->m_fXpos - 1);
			int chkY = (int)(ptrThis->m_fYpos);
			if (pMap->m_pBackBuf[chkY * 80 + chkX].Attributes == 0)
			{
				ptrThis->m_fXpos -= _delta;
			}
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

