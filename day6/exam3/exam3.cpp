// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int _nIndex = 0;
	while (1)
	{
		if (_nIndex > 10)
		{
			break;
		}
		if (_nIndex % 2) //2로 나누어 떨어지지않으면...
		{
			//홀수
			_nIndex++;
			continue;

		}
		/*else {
			printf_s("%d \n", _nIndex);
			_nIndex++;

		}*/
		printf_s("%d \n", _nIndex);		
		_nIndex++;
	}
	return 0;
}
