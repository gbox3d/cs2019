// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int sum(int a, int b)
{
	return a + b;
}

void callSum(int (*fp)(int, int),int a,int b)
{
	printf_s("%d \n", fp(a, b) );
}


int main()
{
	printf_s("%d \n", sum(1, 2));

	int (*fp)(int, int);

	fp = sum;
	printf_s("%d \n", fp(3, 5) );

	callSum(fp, 4,5);

	return 0;
}
