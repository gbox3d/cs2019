// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	FILE* fp;
	fopen_s(&fp, "test.txt", "r");

	if (fp == NULL) {
		puts("파일을 찾을수 없습니다.");
	}
	else {
		puts("파일 오픈 성공");

		char szBuf[256];
		fgets(szBuf, sizeof(szBuf), fp);
		puts(szBuf);

		fclose(fp);
	}

	fopen_s(&fp, "test2.txt", "w");
	if (fp == NULL) {
		puts("파일 열기 실패");
	}
	else {
		fputs("hello file write ",fp);
		fclose(fp);
		puts("파일 쓰기 성공!");
	}

	return 0;
}
