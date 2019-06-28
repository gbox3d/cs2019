// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
{
	
	char a, b,c;
	//scanf_s("%c  %c",&a,sizeof(a),&b,sizeof(b));
	
	printf_s("문자 3개 입력하세요 : ");	
	scanf_s("%c\n", &a, sizeof(a));	
	scanf_s("%c\n", &b, sizeof(b));
	scanf_s("%c", &c, sizeof(c));

	//sscanf_s
	printf_s("=> %c %c %c\n",a,b,c);

}

