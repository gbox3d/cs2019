// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

void test();
void sample1();
void sample2();
void sample3();

extern int globalNumber;

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
		else if (!strcmp("showValue", TGE::g_szTokens[0])) {
			printf_s("%d \n", globalNumber);
		}	
		else if (!strcmp("call", TGE::g_szTokens[0])) {
			if (!strcmp("test", TGE::g_szTokens[1])) {
				test();
			}
			else if (!strcmp("sample1", TGE::g_szTokens[1])) {
				sample1();
			}
			else if (!strcmp("sample2", TGE::g_szTokens[1])) {
				sample2();
			}
			else if (!strcmp("sample3", TGE::g_szTokens[1])) {
				sample3();
			}
		}

	}

	return 0;
}

