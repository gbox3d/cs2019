// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int a, b, c;

	a = 1000;
	b = 2000;
	c = 2100;

	printf_s("%p : %d ,%d \n", &a,*&a,a);	
	printf_s("%p : %d ,%d \n", &b,*&b, b);

	printf_s("%d %d %d \n",a,b,c);
	printf_s("%p %p %p \n",&a,&b,&c);

	int d[3];
	d[0] = 1000;
	d[1] = 2000;
	d[2] = 2100;

	printf_s("%d %d %d \n", d[0],d[1],d[2]);
	printf_s("%d %d %d \n", *&(d[0]), *&(d[1]), *&(d[2]) );

	printf_s("%p %p %p \n", &(d[0]), &(d[1]), &(d[2]) );

	int* ptr; //포인터 변수

	ptr = &a;

	printf_s("%p %p \n", &a, ptr);
	printf_s("%d %d \n", a, *ptr);

	ptr = &d[2];
	printf_s("%d \n", *ptr);



	return 0;
}
