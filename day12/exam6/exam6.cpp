// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	//enum season { spring, summer, fall, winter }; //0부터 시작
	enum season {spring=100,summer,fall,winter}; //100 부터 시작 

	int  a;
	season b;

	b = spring;
	a = spring;

	printf_s("%d , %d \n",a,b);

	a = 1;

	if (a == summer) {
		printf_s("여름입니다. \n");
	}
	else {
		printf_s("여름이 아닙니다. \n");
	}

    
}

