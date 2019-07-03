// exam7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int main()
{
	char _szBuf[256];
	char* pTempNext = NULL;
	int _bLoop = true;

	char dataBuffer[16] = {};

	//명령어 인자1 인자2 인자3
	while (_bLoop)
	{
		char _cmd[256];
		gets_s(_szBuf,sizeof(_szBuf));
		strcpy_s(_cmd, strtok_s(_szBuf, " ", &pTempNext));

		//if (!strcmp(_cmd, "exit")) 
		if (strcmp(_cmd, "exit") == 0 )
		{
			_bLoop = false;
			puts("종료합니다.");
		}
		else if (!strcmp(_cmd, "help")) 
		{
			printf_s("종료 : exit\n");
			printf_s("도움말 : help\n");
			printf_s("버퍼 내용 보여주기 : show\n");
			printf_s("버퍼 특정위치에 값넣기 : set position value\n");
		}
		else if (!strcmp(_cmd, "show"))
		{
			puts("-------------------------");
			for (int i = 0; i < 16; i++)
			{
				printf_s("%d ", dataBuffer[i]);
			}
			puts("\n-------------------------");

		}
		else if (!strcmp(_cmd, "set"))
		{
			//puts(pTempNext);
			int position;
			int data;
			position = atoi(strtok_s(NULL, " ", &pTempNext) );
			data = atoi(strtok_s(NULL, " ", &pTempNext));
			dataBuffer[position] = data;
		}
		else 
		{
			printf_s("%s 는 알수없는 명령어 입니다. \n",_cmd);
		}
	}

	return 0;
}

