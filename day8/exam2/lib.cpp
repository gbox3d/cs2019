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