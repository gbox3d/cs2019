#include "..\..\..\cstudy\engine\tge.h"

void sample3()
{
	HANDLE _hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	//80 * 25
	for (int i = 0; i < 2000; i++) {
		TGE::g_chiBuffer[i].Char.AsciiChar = ' ';
		TGE::g_chiBuffer[i].Attributes = 0x00f0;
	}


	TGE::g_chiBuffer[0].Char.AsciiChar = ' ';
	TGE::g_chiBuffer[0].Attributes = 0x00a0;

	TGE::g_chiBuffer[79].Char.AsciiChar = ' ';
	TGE::g_chiBuffer[79].Attributes = 0x00a0;

	//(x,y) => y*80 + x
	TGE::g_chiBuffer[81].Char.AsciiChar = ' '; //80*1 + 1 => (1,1)
	TGE::g_chiBuffer[81].Attributes = 0x00c0;

	int _matObj1[4][4] = {
		0,1,0,0,
		1,1,1,0,
		0,1,0,0,
		1,1,1,1

	};
	//0,0
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (_matObj1[y][x] == 1) {
				TGE::g_chiBuffer[y*80+x].Char.AsciiChar = ' ';
				TGE::g_chiBuffer[y*80+x].Attributes = 0x00c0;
			}
		}
	}
	//10,0
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (_matObj1[y][x] == 1) {
				int _nIndex = (y+0) * 80 + (x+10);
				TGE::g_chiBuffer[_nIndex].Char.AsciiChar = ' ';
				TGE::g_chiBuffer[_nIndex].Attributes = 0x00c0;
			}
		}
	}
	//5,4
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (_matObj1[y][x] == 1) {
				int _nIndex = (y + 4) * 80 + (x + 5);
				TGE::g_chiBuffer[_nIndex].Char.AsciiChar = ' ';
				TGE::g_chiBuffer[_nIndex].Attributes = 0x00c0;
			}
		}
	}


	TGE::updateBuffer(_hStdout, TGE::g_chiBuffer);
}