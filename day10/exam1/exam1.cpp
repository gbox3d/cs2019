// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

void test()
{
	puts("it is test function!");
}

int main()
{
	int bLoop = true;

	while (bLoop)
	{
		char szBuf[256];
		gets_s(szBuf);
		int tokenNum = TGE::Tokenize(szBuf);
		if (!strcmp("exit", TGE::g_szTokens[0])) {
			bLoop = false;
			puts("exit");
		}
		else if (!strcmp("call", TGE::g_szTokens[0])) {
			if (!strcmp("test", TGE::g_szTokens[1])) {
				test();
			}
		}

	}

	return 0;
}

