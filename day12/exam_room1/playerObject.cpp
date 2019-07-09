
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"

void initPlayerObject(S_PlayerObject *pObj,const char *pszName)
{
	pObj->m_fXpos = 0;
	pObj->m_fYpos = 0;
	pObj->m_fSpeed = 2.0;
	strcpy_s(pObj->m_szName, 64,pszName);
}

void releasePlayerObject(S_PlayerObject* pObj)
{

}

void applyPlayerObject(S_PlayerObject* pObj,double _fDelta,int *pMap)
{
	double _delta = (pObj->m_fSpeed * _fDelta);

	if (TGE::input::g_KeyTable[VK_UP]) {
		pObj->m_fYpos -= _delta;
		//TGE::input::g_KeyTable[VK_UP] = false;
	}
	else if (TGE::input::g_KeyTable[VK_DOWN]) {
		pObj->m_fYpos += _delta;
		//TGE::input::g_KeyTable[VK_DOWN] = false;
	}
	else if (TGE::input::g_KeyTable[VK_LEFT]) {
		int chkX = (int)(pObj->m_fXpos - 1);
		int chkY = (int)pObj->m_fYpos;
		if (pMap[chkY * 8 + chkX] != 1)
		{
			pObj->m_fXpos -= _delta;
		}
		
		//TGE::input::g_KeyTable[VK_LEFT] = false;
	}
	else if (TGE::input::g_KeyTable[VK_RIGHT]) {
		int chkX = (int)(pObj->m_fXpos + 1);
		int chkY = (int)pObj->m_fYpos;
		if (pMap[chkY * 8 + chkX] != 1)
		{
			pObj->m_fXpos += _delta;
		}
	}
	

}

void DrawPlayerObject(S_PlayerObject* pObj, CHAR_INFO *pDrawBuff)
{
	TGE::setCharacter(pDrawBuff, (int)pObj->m_fXpos, (int)pObj->m_fYpos,
		0x0020,
		0x00F0
	);
}

