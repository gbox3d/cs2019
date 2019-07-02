// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void showData(int _buf[],int nBufLength)
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (_buf[i] == -1)
		{
			if (i <= 0) 
			{
				printf_s("데이터가 없습니다. \n");
			}
			break;
		}
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

int popData(int _buf[], int nBufLength)
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (_buf[i] == -1) {
			if(i > 0)
			{
				int _r = _buf[i - 1];
				_buf[i - 1] = -1;
				return _r;
			}		
			else
			{
				printf_s("지워질 데이터가 없습니다.\n");
			}
			break;
		}
	}
	return -1;
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
		printf_s("\n(1.show 2.push 3.pop)Cmd>"); scanf_s("%d", &_cmd);
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
		{
			int _num;
			printf_s("\ninput number =>"); scanf_s("%d", &_num);
			pushData(nBuf, nBufLength, _num);
		}	
			break;
		case 3:
			printf_s("pop : %d \n", popData(nBuf, nBufLength) );
			break;
		default:
			break;
		}
	}
	
	return 0;
}
