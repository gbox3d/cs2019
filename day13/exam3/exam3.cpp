// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
	FILE* fp;
	fopen_s(&fp, "player.dat", "r");

	if (fp) {
		puts("파일 오픈 성공");
		S_GameObject* pObj = (S_GameObject*)malloc(sizeof(S_GameObject));
		fread_s(pObj, sizeof(S_GameObject), sizeof(S_GameObject), 1, fp);
		
		printf_s("%lf,%lf,%d ,%d \n", pObj->m_xPos, pObj->m_yPos, pObj->m_nSkima, pObj->m_nId);

		fclose(fp);
		free(pObj);
	}
	
    
}

