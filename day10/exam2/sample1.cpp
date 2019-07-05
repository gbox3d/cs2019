#include "..\..\..\cstudy\engine\tge.h"

void sample1()
{
	puts("sample 1 start ");

	int score[3][4] = {
		{1,2,3,4} ,
		{10,20,30,40},
		{11,12,13,14}
	};

	//[За(y)][ї­(x)]
	printf_s("%d \n",score[1][0]);
	puts("--------------------------------------");
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			printf_s("%d \n", score[row][col]);
		}
	}
	puts("--------------------------------------");
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			printf_s("%d \n", score[row][col]);
		}
	}
}

