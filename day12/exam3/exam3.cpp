// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "gameobject.h"
#include "..\..\..\cstudy\engine\tge.h"


int main()
{
	S_GameObject* pObject;
	pObject = (S_GameObject*)malloc( sizeof(S_GameObject) );
	const char* szName = "orcFighter";
	initGameObject(pObject,szName,strlen(szName));

	printf_s("%lf %d,%s", pObject->m_fSpeed, pObject->m_nDamage, pObject->m_szName);

	releseGameObject(pObject);

	return 0;
}


