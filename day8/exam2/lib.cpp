#include <stdio.h>

int getStringLength(char strTemp[],int nBufSize)
{
	int nCount = 0;
	for (int i = 0; i < nBufSize; i++)
	{
		if (strTemp[i] == 0x00)
		{
			break;
		}
		nCount++;		
	}
	return nCount;
}

void displayBuf(char strTemp[], int nBufSize)
{
	if (getStringLength(strTemp, nBufSize) <= 0)
	{
		puts("빈문자열입니다.");
	}
	else
	{
		puts(strTemp);
	}
}