// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int main()
{
	int num = 45; //정답
	int _input;
	printf_s("-- 숫자 맞추기 게임 -- \n 아무 숫자나 입력하세요 :");

	scanf_s("%d", &_input);

	if (num == _input) {
		printf_s("당신이 이겼습니다. \n");
	}
	//if (num != _input) {
	else {
		printf_s("당신이 졌습니다. \n");

		if (num < _input) {
			printf_s("hint! : 왜냐구요? 너무 크기 때문입니다. \n");
		}
		//if (num > _input) {
		else {
			printf_s("hint! : 왜냐구요? 너무 작기 때문입니다. \n");
		}
	}

	printf_s("게임종료 \n");
	return 0;
    
}

