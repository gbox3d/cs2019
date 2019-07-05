#include "..\..\..\cstudy\engine\tge.h"

int globalNumber = 7;

int * counter()
{
	static int _cnt = 0;
	_cnt++;
	globalNumber++;
	printf_s("counter : %d %p,%d\n",_cnt,&_cnt,globalNumber);
	return &_cnt;
}
void sample3()
{
	counter();
	counter();
	counter();
	counter();
	counter();
	int* ptrCnt = counter();

	(*ptrCnt) = (*ptrCnt) + 1;
	counter();
	globalNumber = 0;
	printf_s("globalNumber : %d \n", globalNumber);

	//printf_s("%d \n",_cnt);
}
