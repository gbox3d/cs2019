#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

void test()
{
	puts("it is test function!");
}

void sample1()
{
	int a = 1;
	printf_s("%p\n", &a);
	{
		int a = 2;
		printf_s("%p\n", &a);
		{
			int a = 3;
			printf_s("%p\n", &a);
			{
				int a = 4;
				printf_s("%p\n", &a);
				{
					a = 5;
					printf_s("%p\n", &a);
					printf_s("%d\n", a);
				}
				printf_s("%d\n", a);
			}
			printf_s("%d\n", a);
		}
		printf_s("%d\n", a);
	}
	printf_s("%d\n", a);
}