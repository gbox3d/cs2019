// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

union S_MyUnion
{
	unsigned int m_dwWord;
	unsigned char m_ucByte[4];
};

int main()
{
	printf_s("union size : %d \n",sizeof(S_MyUnion));

	S_MyUnion testUnion;
	testUnion.m_dwWord = 0x01020304;
	printf_s("%u, %x \n",testUnion.m_dwWord,testUnion.m_dwWord);
	printf_s("%x,%x,%x,%x \n", testUnion.m_ucByte[0],
		testUnion.m_ucByte[1],
		testUnion.m_ucByte[2],
		testUnion.m_ucByte[3]
		); //little endian 방식
	//big endian

	return 0;
}
