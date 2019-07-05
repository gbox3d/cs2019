#include "..\..\..\cstudy\engine\tge.h"

void sample3()
{
	HANDLE _hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int _matObj1[4][4] = {
		
	};

	/*
	TGE::g_chiBuffer[0].Char.AsciiChar = 'A';
	TGE::g_chiBuffer[0].Attributes = 0x00f0;

	TGE::g_chiBuffer[1].Char.AsciiChar = 'B';
	TGE::g_chiBuffer[1].Attributes = 0x00f0;
	*/

	/*
	for (int i = 0; i < 25; i++) {
		TGE::g_chiBuffer[i].Char.AsciiChar = 'A'+i;
		TGE::g_chiBuffer[i].Attributes = 0x00f0;
	}

	TGE::g_chiBuffer[79].Char.AsciiChar = '@';
	TGE::g_chiBuffer[79].Attributes = 0x00f0;

	TGE::g_chiBuffer[80].Char.AsciiChar = '#';
	TGE::g_chiBuffer[80].Attributes = 0x00f0;
	*/

	//80 * 25
	for (int i = 0; i < 2000; i++) {
		TGE::g_chiBuffer[i].Char.AsciiChar = ' ';
		TGE::g_chiBuffer[i].Attributes = 0x00f0;
	}



	/*for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			TGE::g_chiBuffer[y*80 + x].Char.UnicodeChar = _matObj1[y][x];
			TGE::g_chiBuffer[y * 80 + x].Attributes = 0x
		}
	}*/

	TGE::updateBuffer(_hStdout, TGE::g_chiBuffer);
}