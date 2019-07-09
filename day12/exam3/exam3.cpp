// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "..\..\..\cstudy\engine\tge.h"

struct S_GameObject {

	char* m_szName;
	int m_nDamage;
	int m_nHitPoint;
	double m_fSpeed;
	double m_fXpos, m_fYpos;
};

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


int main()
{
	S_GameObject* pObject;
	

	return 0;
}


