// exam9.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
{
	
	int num = -1;
	printf_s("%d , %u\n", num, num); //출력 단계에서 부호 결정

	double _pi = 3.1415926;

	//printf_s("%d  \n", _pi);
	printf_s("%d  \n", (int)_pi);
	printf_s("%lf  \n", _pi);

	printf_s("\\  A\tB  \n");
	
	//유니코드 입력예
	printf_s("\x41 한글 \u2660 \u2665  \n");

	//10칸확보후 우측 정렬
	printf_s("%10d \n", 128);
	printf_s("%10d \n", 1280);
	printf_s("%10d \n", 12800);
	printf_s("%10d \n", 12800);
	//10칸확보후 좌측 정렬
	printf_s("%-10d *\n", 128);
	printf_s("%-10d *\n", 1280);
	printf_s("%-10d *\n", 12800);
	printf_s("%-10d *\n", 12800);
	//그냥 좌측정렬
	printf_s("%d *\n", 128);
	printf_s("%d *\n", 1280);
	printf_s("%d *\n", 12800);
	printf_s("%d *\n", 12800);

	printf_s("%lf *\n", 12.8);
	printf_s("%lf *\n", 1.280);
	printf_s("%lf *\n", .128);
	printf_s("%lf *\n", .0128);

	printf_s("%10.1lf *\n", 12.8);
	printf_s("%10.1lf *\n", 1.280);
	printf_s("%10.1lf *\n", .128);
	printf_s("%10.1lf *\n", .0128);

	printf_s("%-10.1lf *\n", 12.8);
	printf_s("%-10.1lf *\n", 1.280);
	printf_s("%-10.1lf *\n", .128);
	printf_s("%-10.1lf *\n", .0128);

	//유니코드 입력예
	printf_s("\x41 한글 \u2500 \u2510  \n");

	
}
