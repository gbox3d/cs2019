// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\\cstudy\engine\irrlicht\include\irrlicht.h"
#include "..\..\\..\\cstudy\engine\tge.h"

int main()
{
	HANDLE hStdout;
	irr::core::vector2df test;

	
	

	TGE::startTGE(&hStdout);
	bool bLoop = true;


	//TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);

	//TGE::setCharacter(TGE::g_chiBuffer, (int)test.X, (int)test.Y, 0x0020, 0x00f0);

	//test += irr::core::vector2df(2, 2);
	//TGE::setCharacter(TGE::g_chiBuffer, (int)test.X, (int)test.Y, 0x0020, 0x00c0);

	
	test = irr::core::vector2df(40, 12);//x:40,y:12
	irr::core::vector2df vDir(1, 0);
	irr::f32 fAngle = 0.0;
	while (bLoop)
	{
		if (TGE::input::g_KeyTable[VK_RETURN])
		{
			bLoop = false;
		}
		else if (TGE::input::g_KeyTable[VK_SPACE])
		{
			irr::core::vector2df _vDir = vDir;
			_vDir.rotateBy(fAngle);

			TGE::input::g_KeyTable[VK_SPACE] = false;
			test += _vDir;
		}
		else if(TGE::input::g_KeyTable[VK_LEFT])
		{
			TGE::input::g_KeyTable[VK_LEFT] = false;
			fAngle += 5;			
		}

		
		TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);
		TGE::setCharacter(TGE::g_chiBuffer, (int)test.X, (int)test.Y, 0x0020, 0x00f0);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

		TGE::setCursor(hStdout, 0, 25);
		printf_s("%4.3f                       ", fAngle);
		//puts("엔터키를 누루면 종료합니다.");

	}

	TGE::endTGE();

}
