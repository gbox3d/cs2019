교재 156p
scanf 심화

scanf_s("형식문자열",&변수,변수바이트크기,...<반복>....)
=> 또는
scanf_s("형식문자열",&변수,sizeof(변수),...<반복>....)

scanf를 연달아 쓰는경우 발생하는 문제
=> 키보드 입력 특성상 개행도 문자 입력으로 처리
=> 중간 중간 입력이 빠지는 문제발생

-----------------------------------------------
구글에서 유니코드표 찾기
=> 검색창에서 "유니코드표" 
=> 유니코드 관련 위키백과
=> hipanpal,(http://www.hipenpal.com/tool/characters-to-unicode-charts-in-korean.php?unicode=0)
------------------------------------------------
조건문
=> 조건식에 대한 연산자 => >,<,=, &&, ||, ! 
=> num1 연산자 num2 = 계산결과 => 1+2=3
=> 1 > 0 = true(1) , 1 < 0 = false(0)
=> 관계 연산자 => <,>,=,>=,<=,!=,==
=> 논리 연산자 => &&(논리곱),||(논리합), !(부정)

선택문
=> if(조건식) { 조건식이 참 이면 실행 }

exam3 => 숫자 맞추기 게임 => 정해진숫자가 맞는지 비교하여 승리 여부 판단

예제 6-2, 179p

if(...) 
	printf_s(...);	

else 
	printf_s(...);

=> 한줄만 있을 경우는 { }생략 가능

다중 선택문=> switch(정수값) { case 1:,case 2:....default:}
exam4 => switch문 예제

------------------------
자동 완성 핫키 => ctrl + space
------------------------

exam5 
반복문 => 반복적인 일처리를 가능하게 해주는 문법
=> 반복 구간을 정하고 조건으로 제어한다.

while( 반복을 계속할지말지 조건 ) 
{
	반복구간
}
=> 간단한 턴재 게임 인터페이스 구현

-----------------------------------------
exam6

증감 연산자 => a 를 1씩 증가 시키는 방법
=> a = a+1 => a = a + 5
=> a += 5(a=a+5)
=> 1씩 증가 시키는 경우 => a++ , ++a 
=> a = a - 1 => a -= 1 => a--(1씩 감소하는 경우)
------------------------------------------
터미널 폰트 컬러링

GetStdHandle,
CONSOLE_SCREEN_BUFFER
SetConSoleTextAttribute => 글자 색을 바꾸는 함수

배경 / 폰트 
0000 / 0000
8421 / 8421
IRGB / IRGB

=> 0xf4 => 하얀 바탕에 어두운 빨간글씨
=> 0x0a => 검은 바탕에 녹색 글씨













