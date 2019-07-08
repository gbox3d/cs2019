// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char* szBufs[4] = {};

	puts("4개의 단어를 입력하세요.");
	for (int i = 0; i < 4; i++)
	{
		char szTemp[256];
		gets_s(szTemp, 256);

		int nlength = strnlen_s(szTemp, sizeof(szTemp));

		szBufs[i] = (char *)malloc(nlength+1); //메모리 확보 
		if (szBufs[i] != NULL) {
			strcpy_s(szBufs[i], nlength + 1, szTemp);
		}
		else {
			puts("메모리가 부족합니다.");
		}
	}

	puts("--------------------");
	for (int i = 0; i < 4; i++)
	{
		if (szBufs[i] != NULL) {
			puts(szBufs[i]);
			free(szBufs[i]);
		}
	}
}
