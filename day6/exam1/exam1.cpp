// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    //std::cout << "Hello World!\n";
	int i = 0;
	int dan = 7;
	for (i = 1; i <= 9; i++)
	{
		printf_s("%d*%d = %d \n",dan,i, i*7);
	}

	return 0;
}



