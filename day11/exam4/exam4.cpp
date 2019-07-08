// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void d()
{
	printf_s("함수 포인터 \n");
}

int main()
{
	int a;
	double b;
	char c;

	void* ptr;

	ptr = &a;
	*(int *)ptr = 1;
	printf_s("%d \n", *(int *)ptr);

	ptr = &b;
	*(double*)ptr = 3.5;
	printf_s("%lf \n", *(double*)ptr);

	ptr = &c;
	*(char*)ptr = 'A';
	printf_s("%c \n", *(char*)ptr);

	ptr = d;

	((void (*)())ptr)();


	return 0;
}
