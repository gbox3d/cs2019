// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int a,b;
	int* pA;
	int* pB;

	a = 3;
	b = 4;

	pA = &a;
	*pA = b; // a=b

	printf_s("%d %d\n",*pA,a);


	a = b;
	pA = &a;
	*pA = b;

	return 0;
}

