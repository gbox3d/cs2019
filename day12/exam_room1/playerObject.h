#pragma once

struct S_PlayerObject
{
	char m_szName[64];
	double m_fXpos, m_fYpos; //위치정보
	double m_fSpeed;

};

void initPlayerObject(S_PlayerObject* pObj, const char* pszName);
void releasePlayerObject(S_PlayerObject* pObj);
void applyPlayerObject(S_PlayerObject* pObj, double _fDelta, int* pMap);
void DrawPlayerObject(S_PlayerObject* pObj, CHAR_INFO* pDrawBuff);

