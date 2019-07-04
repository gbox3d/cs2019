// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//1씩 증가 시키는 함수
void incNumber(int* _a) 
{	
	*_a = *_a + 1;
	//printf_s("passed a %d \n", _a);
}

int main()
{
	int a, b;
	a = 0;
	b = 4;
	printf_s("%d \n", a);//0

	incNumber(&a);
	printf_s("%d \n", a);//1
    
}
