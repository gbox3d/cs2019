// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int _ix, _iy;

	//좌측 정렬
	for (_iy = 0; _iy < 5; _iy++) 
	{
		for (_ix = 0; _ix < (5-_iy); _ix++)
		{
			printf_s("*");
		}
		printf_s("\n");

	}

	//우측 정렬
	for (_iy = 0; _iy < 5; _iy++)
	{
		for (_ix = 0; _ix < (_iy + 1); _ix++)
		{
			//printf_s("+");
			printf_s(" ");
		}
		for (_ix = 0; _ix < (5 - _iy); _ix++)
		{
			printf_s("*");
		}
		printf_s("\n");
	}


	return 0;
}

