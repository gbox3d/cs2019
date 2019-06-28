// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int main()
{
	int num1, num2, _result;

	num1 = 1;
	num2 = 2;
	printf_s("num1=%d , num2 = %d \n", num1,num2);
	_result = num1 < num2;
	printf_s("num1 < num2 = %d \n", _result);
	_result = num1 > num2;
	printf_s("num1 > num2 = %d \n", _result);

	printf_s("(num1 > 0) && (num2 <= 2 ) = %d \n", (num1 > 0) && (num2 <= 2 )  );
	printf_s("(num1 > 0) || (num2 < 2 ) = %d \n", (num1 > 0) || (num2 < 2));
	printf_s("(num2 < 2 ) = %d, !(num2 < 2 ) = %d \n",  (num2 < 2), !(num2 < 2));
	//  1 <  num2 < 5
	printf_s("1 <  num2 < 5 = %d \n", (1 < num2)&& (num2 < 5) );
	// (num1 < 5) OR(또는) (num1 > 10)
	printf_s("(num1 < 5) OR (num1 > 10) = %d \n", (num1 < 5) || (num1 > 10));
	printf_s("(num1 < 0) OR (num1 > 10) = %d \n", (num1 < 0) || (num1 > 10));

	printf_s("(num1 < 0) OR (num1 > 10) = %d \n", !((num1 < 0) || (num1 > 10)));
	printf_s("(num1 >= 0) AND (num1 <= 10) = %d \n", ((num1 >= 0) && (num1 <= 10)));


	return 0;
    
}

