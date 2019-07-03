// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char _szBuf[256] = "문제인 트럼프 김정은";
	char* _szTokens[32];
	char* pNextToken=NULL;

	_szTokens[0] = strtok_s(_szBuf, " ", &pNextToken);

	puts(_szTokens[0] );
	puts(pNextToken);

	_szTokens[1] = strtok_s(NULL, " ", &pNextToken);
	puts(_szTokens[1]);
	puts(pNextToken);

	_szTokens[2] = strtok_s(NULL, " ", &pNextToken);
	puts(_szTokens[2]);
	puts(pNextToken);

	strcpy_s(_szBuf,sizeof(_szBuf) ,"insert 2 test");
	
	char _token[256];
	strcpy_s(_token, sizeof(_token), strtok_s(_szBuf, " ", &pNextToken));
	puts(_token);

	int num;
	char szTemp[256];
	sscanf_s(pNextToken, "%d %s", &num, szTemp, sizeof(szTemp));
	//strcpy_s(_token, sizeof(_token), strtok_s(NULL, " ", &pNextToken));
	//puts(_token);

	printf_s("%d %s", num, szTemp, sizeof(szTemp));


	return 0;
    
}
