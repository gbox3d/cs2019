// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
{
	printf_s("캐릭터 직업을 고르세요. \n");
	printf_s("1. 파이터 \n");
	printf_s("2. 마법사 \n");
	printf_s("3. 치료사 \n");

	int _selectChr = 0;

	scanf_s("%d", &_selectChr );

	printf_s("선택한 번호 : %d \n", _selectChr);
	
	switch (_selectChr)
	{
	case 1:
		printf_s("파이터가 생성되었습니다. \n");
		break;
	case 2:
		printf_s("마법사가 생성되었습니다. \n");
		break;
	case 3:
		printf_s("치료사가 생성되었습니다. \n");
		break;
	default:
		printf_s("번호를 잘못 입력하셨어요. \n");
		break;
	}

	return 0;
}
