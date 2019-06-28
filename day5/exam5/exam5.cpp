// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char _cmd;
	int _bLoop = 1;
	while (_bLoop)
	{
		printf_s("커멘드를 입력하세요(도움말 h) : ");
		scanf_s("\n%c", &_cmd, sizeof(_cmd));

		switch (_cmd)
		{
		case 'q':
		{
			printf_s("프로그램을 종료 합니다.");	
			_bLoop = 0;
		}
			break;
		case 'h':
		{
			printf_s("===============================\
================================================== \n");
			printf_s("q : 나가기 \n");
			printf_s("c : 캐릭터 생성 \n");
			printf_s("s : 게임시작 \n");
			printf_s("i : 게임설정 \n");
			printf_s("========== \n");
		}
			break;
		case 'c':
		{
			int __cmd;
			printf_s("캐릭터를 생성합니다. \n");
			printf_s("직업을 선택하세요. \n");
			printf_s("1. 파이터 \n");
			printf_s("2. 마법사 \n");
			printf_s("3. 치료사 \n");
			scanf_s("\n%d", &__cmd);
			printf_s("%d 를 선택하셨습니다.\n", __cmd);

		}
			break;
		case 'i':

			break;
		default:
		{
			printf_s("\n커멘드를 확인해주세요.\n");
		}
			break;
		}
		/*
		if (_cmd == 'q')
		{}
		else if (_cmd == 'h') 
		{}
		else if (_cmd == 'c') 
		{}
		else 
		{}
			*/
		
	}
	return 0;
}

