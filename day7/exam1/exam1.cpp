// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int gold[5] = { 120,130,100,110,90 };
	/*
	int gold[5];
	gold[0] = 120;
	gold[1] = 130;
	gold[2] = 100;
	gold[3] = 110;
	gold[4] = 90;
	*/

	printf_s("gold[0] : %d \n", gold[0]);
	printf_s("sizeof(gold) : %d , sizeof(int) :%d \n", sizeof(gold), sizeof(int));

	for (int i=0; i < sizeof(gold)/sizeof(int); i++)
	{
		printf_s("gold[%d] : %d \n",i, gold[i]);
	}

	return 0;
    //std::cout << "Hello World!\n";
}

