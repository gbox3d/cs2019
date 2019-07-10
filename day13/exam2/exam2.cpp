// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

struct S_GameObject {
	int m_nSkima;
	double m_xPos, m_yPos;
	int m_nId;
	double m_fSpeed;
};

int main()
{
	S_GameObject* pObj;
	pObj = (S_GameObject*)malloc(sizeof(S_GameObject));

	pObj->m_nSkima = 1;
	pObj->m_xPos = 35.6;
	pObj->m_yPos = 7.89;
	pObj->m_nId = 1000;
	pObj->m_fSpeed = 2.5;

	FILE* fp;
	fopen_s(&fp, "player.dat", "w");
	if (fp) {
		puts("파일 오픈 성공");
		int nSize = fwrite(pObj, sizeof(S_GameObject), 1, fp);
		printf_s("반환값 : %d \n", nSize);
		fclose(fp);
	}
	else {
		puts("파일 오픈 실패");
	}
	
	free(pObj);
	return 0;
}
