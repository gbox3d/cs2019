// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int val = 10;
	int* ip;

	ip = &val;

	printf_s("%d \n", *ip);

	val = 3;
	//*ip = 3;
	printf_s("%d \n", *ip);

	int** ipp;
	ipp = &ip;
	val = 2;

	printf_s("%d \n", **ipp);
	//val ,*ip, **ipp 같음 값


	return 0;
}
