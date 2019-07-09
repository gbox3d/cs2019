// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\exam3\gameobject.h"
#include "..\..\..\cstudy\engine\tge.h"

int main()
{
	S_GameObject* pObjs[8];

	pObjs[0] = (S_GameObject*)malloc(sizeof(S_GameObject));
	initGameObject(pObjs[0], "player1", sizeof("player1"));

	pObjs[1] = (S_GameObject*)malloc(sizeof(S_GameObject));
	initGameObject(pObjs[1], "player2", sizeof("player2"));

	for (int i = 0; i < 2; i++)
	{
		printf_s("%s \n", pObjs[i]->m_szName);
	}

	for (int i = 0; i < 2; i++)
	{
		releseGameObject(pObjs[i]);
	}

	return 0;
}