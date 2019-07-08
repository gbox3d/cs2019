// exam7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main(int argc,char **argv)
{
	printf_s("인자 갯수 %d\n", argc);

	for (int i = 0; i < argc; i++)
	{
		//puts(argv[i]);
		printf_s("%d번째 전달인자 %s\n", i + 1, argv[i]);
	}

	return 0;
}
