// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "../..//..//cstudy/engine/tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	TGE::hideCursor(hStdout);

	bool bLoop = true;
	while (bLoop) {
		TGE::setCursor(hStdout, 0, 0);
		printf_s("%8d %8d %8x ", TGE::input::g_cdMousePos.X, TGE::input::g_cdMousePos.Y,
			TGE::input::g_dwButtonState);

		if (TGE::input::g_dwButtonState == 4) {
			bLoop = false;
		}

	}
	TGE::showCursor(hStdout);

	TGE::endTGE();
    
}
