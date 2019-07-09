#pragma once

struct S_PlayerObject
{
	char m_szName[64];
	double m_fXpos, m_fYpos; //��ġ����

};

void initPlayerObject(S_PlayerObject* pObj, const char* pszName);
void releasePlayerObject(S_PlayerObject* pObj);
void applyPlayerObject(S_PlayerObject* pObj);
void DrawPlayerObject(S_PlayerObject* pObj, CHAR_INFO* pDrawBuff);

