// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	double _pi = 3.14;
	int _nPi;

	_nPi = (int)_pi; //서로 다른 데이터 형

	printf_s("%d %lf \n", (int)(5 / 2),(double)((double)5 / (double)2));

	int num1 = 5;
	int num2 = 2;
	double num3 = num1 / num2;
	printf_s("%lf \n", num3);

	return 0;
    
}

