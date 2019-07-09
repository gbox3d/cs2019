
#include "gameobject.h"
#include "..\..\..\cstudy\engine\tge.h"



//구조체를 초기화 하는 함수
void initGameObject(S_GameObject* _obj, const char* szName, int nNameSize)
{
	(*_obj).m_fSpeed = 5.0;
	_obj->m_fXpos = 0;
	_obj->m_nDamage = 10;
	_obj->m_fYpos = 0;
	_obj->m_nHitPoint = 100;

	_obj->m_szName = (char*)malloc(nNameSize + 1);
	strcpy_s(_obj->m_szName, nNameSize + 1, szName);
}

void releseGameObject(S_GameObject* _obj)
{
	free(_obj->m_szName);
}