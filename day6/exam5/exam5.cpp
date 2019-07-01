// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int _sum(int a, int b)
{
	int result = a + b;
	return result;
}

int _sub(int a, int b)
{
	int result = a - b;
	return result;
}

int _mul(int a, int b)
{
	int result = a * b;
	return result;
}
int _div(int a, int b)
{
	int result = a / b;
	return result;
}

int main()
{
	int a, b;
	char _operator;

	scanf_s("%d %c %d", &a, &_operator, sizeof(_operator), &b); // 3 + 5 
	printf_s("%d,%c,%d\n", a, _operator, b);
	switch (_operator)
	{
	case '+':
	{	
		printf_s("두수의 합은 : %d\n",_sum(a,b));
	}
		break;
	case '-':
	{	
		printf_s("두수의 차는 : %d\n",_sub(a,b));
	}
	break;
	case '*':
	{	
		printf_s("두수의 곱은 : %d\n", _mul(a,b));
	}
	break;
	case '/':
	{	
		printf_s("두수의 몫은 : %d\n", _div(a,b));
	}
	break;
	default:
		break;
	}

    
}

