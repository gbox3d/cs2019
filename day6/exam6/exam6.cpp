// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
{	
	int nums[5]; 
	//int a, b, c, d, e;

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &(nums[i]));
	}
	printf_s("-------입력완료------\n");

	for (int i = 0; i < 5; i++) {
		printf_s("%d +", nums[i]);
	}

	int sum = 0;

	for (int i = 0; i < 5; i++) {
		sum = sum + nums[i];
	}
	printf_s("합은 : %d\n", sum);
    
}
