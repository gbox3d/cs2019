// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void showData(int _buf[],int nBufLength)
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (_buf[i] == -1) break;
		printf_s("%d ", _buf[i]);
	}
}

void pushData(int _buf[], int nBufLength, int _data)
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (_buf[i] == -1) {
			_buf[i + 1] = -1;
			_buf[i] = _data;
			break;
		}
	}
}
int main()
{
	int nBuf[256] = {-1};
	int nBufLength = sizeof(nBuf) / sizeof(int);

	nBuf[0] = 3;
	nBuf[1] = -1;

	int _cmd;
	int _bLoop = 1;
	while (_bLoop)
	{
		printf_s("\nCmd>"); scanf_s("%d", &_cmd);
		switch (_cmd)
		{
		case 0:
			_bLoop = 0;
			printf_s("프로그램을 종료 합니다. \n");
			break;
		case 1:
			showData(nBuf, nBufLength);
			break;
		case 2:
			pushData(nBuf, nBufLength,3);
			break;
		case 3:
			//popData(nBuf, nBufLength);
			break;
		default:
			break;
		}
	}
	
	return 0;
}
