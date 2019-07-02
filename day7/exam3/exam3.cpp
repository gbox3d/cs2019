// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int nBuf[256];
int nLastIndex = -1;
void printData()
{
	for (int i = 0; i <= nLastIndex; i++)
	{
		printf_s("%d ", nBuf[i]);
		
	}
}
void pushData(int _data)
{
	nLastIndex++;
	nBuf[nLastIndex] = _data;
}
int popData()
{
	int _r=-9999;
	if (nLastIndex < 0) { printf_s("데이터가 없음."); }
	else 
	{
		_r = nBuf[nLastIndex];
		nLastIndex--;
	}
	return _r;
}
int main()
{
	int _bLoop = 1;
	while (_bLoop)
	{
		int _cmd; printf_s("\n Cmd>"); scanf_s("%d", &_cmd);
		switch (_cmd) 
		{
		case 0: _bLoop = 0; printf_s("종료합니다.\n"); break;
		case 1: {int _num; printf_s("input num =>"); scanf_s("%d", &_num); pushData(_num); }  break; //push
		case 2: {printf_s("pop : %d\n",popData()); } break; //pop
		case 3: printData(); break; //show
		}

	}
}
