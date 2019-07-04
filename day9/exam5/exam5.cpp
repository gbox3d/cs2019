// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arraySum(int *pArray,int nLength,int b[])
{
	int _sum = 0;
	printf_s("array size : %d\n", sizeof(pArray)  );
	
	for (int i = 0; i < nLength; i++)
	{
		//_sum += *(pArray + i);
		//_sum += pArray[i];
		_sum += *(pArray++);

	}


	*pArray = NULL;
	b = NULL;
	
	printf_s("array[3]_size %d \n",sizeof(b));

	return _sum;
}

int main()
{
	int a[3];
	int* pA;
	pA = a;
	//a = pA; //error
	printf_s("%p %p \n",pA,a );
	a[0] = 10; a[1] = 11; a[2] = 15;
	*(a+1) = 21; //a[1] = 21;

	printf_s("array size %d ,sum : %d \n",
		sizeof(a), 
		arraySum(a,sizeof(a)/sizeof(int),a)
	);

}




