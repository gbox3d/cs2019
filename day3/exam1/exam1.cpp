// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>



int main()
{
	printf_s("========================\n");
	printf_s("Hello World!\n");
	printf_s("%d \n",10);
	printf_s("%d / %d \" \\ \n",10,20);
	printf_s("은하철도 %d \n", 990 + 9);
	printf_s("은하철도 990 + 9 \n");
	//http://www.hipenpal.com/tool/characters-to-unicode-charts-in-korean.php?unicode=69
	printf_s("\\ , \" \x41 \x22 \n");

	
    //std::cout << "Hello World!\n"; 
	return 0;
}
