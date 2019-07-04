// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{	
	int a[5];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	printf_s("%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4]);

	*(a+0) = 6; //a[0]
	*(a + 1) = 7; // a[1]
	*(a + 2) = 8; // a[2]
	*(a + 3) = 9; // a[3]
	*(a + 4) = 10;// a[4]
	printf_s("%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4]);

	int* pA;
	pA = a;
	*(pA + 3) = 0;
	printf_s("%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4]);


	int a1, a2;
	a1 = 1;
	a2 = 2;
	int* pA1 = &a1;

	*(pA1 - 12) = 3; //error
	printf_s("%d \n",a2);
    
}
