// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char* ptr=NULL;
	//char ptr[256];

	ptr = (char *)malloc(256);

	if (ptr != NULL) {
		gets_s(ptr, 256);
		printf_s("%s \n", ptr);
		free(ptr);
	}
	else {
		puts("메모리 확보에 실패 했습니다.");
	}
	

	return 0;
}
