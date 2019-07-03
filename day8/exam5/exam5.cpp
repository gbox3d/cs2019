// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char szBuf[256] = "Hello World";
	char szBuf2[256] = "korea";

	printf_s("문자열 크기 : %d \n", strlen(szBuf));

	puts(szBuf);
	puts(szBuf2);

	//szBuf == szBuf2
	if (strcmp(szBuf, szBuf2) == 0 )
	{
		puts("일치합니다.");
	}
	else 
	{
		puts("일치하지않습니다.");
	}
	


	puts("--------------------------");
	// buf2 => buf  copy , szBuf = szBuf2
	/*for (size_t i = 0; i < strlen(szBuf2)+1; i++)
	{
		szBuf[i] = szBuf2[i];
	}*/

	strcpy_s(szBuf, sizeof(szBuf), szBuf2);

	puts(szBuf);

	puts(szBuf2);

	int isEquel = true;
	for (int i = 0; i < strlen(szBuf); i++)
	{
		if (szBuf[i] != szBuf2[i])
		{
			isEquel = false;
			break;
		}
	}
	if (isEquel)
	{
		puts("일치합니다.");
	}
	else
	{
		puts("일치하지않습니다.");
	}

	strcat_s(szBuf, sizeof(szBuf), "-forever");
	puts(szBuf);

    //std::cout << "Hello World!\n";
	return 0;
}

