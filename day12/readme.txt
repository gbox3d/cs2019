487p 구조체

구조체를 사용하는 이유
=> 여러가지 변수를 묶어서 처리 할수있다.
=> 데이터 관리를 체계적으로 할수있다.
=> 프로그램은 두가지 중요한 요소로가 있다.
=> 코드, 데이터
=> 코드 를 체계적으로 관리 하기 위한도구가 함수이면
데이터를 체계적으로 관리하기 위한 도구는 구조체이다.

=> 함수와 구조체가 묶여 있는것을 class 이다.

=> struct , 키워드 사용
=>
struct 구조체이름 {
	char *szName;
	int nAge;
	int fWeghit
	....
	....
	멤버변수 선언
}; <- 새미 콜론 주의

=> 구조체이름은 새로운 변수의 형식(int ,char )처럼 사용한다.
=> 구조체 선언은 .h(헤더 파일) , main 밖 전역 공간에서 선언한다.

510p. 공용체 ,exam5
=> 키워드로 union 사용. 
=> 구조체와 같은 방식으로 선언과 사용.

int =>
01020304

char =>
01 02 03 04  => m 사,big endian
04 03 02 01  => i 사 방식

열거형
=> enum

typedef
=> struct aaa {.....};
=> typedef struct aaa S_aaa;
=> 실제 형식명은 S_aaa => 구버전 c 스타일

=> struct S_aaa {....}; => 형식명을 바로 지정가능.
-----------------------------------------------------
exam_room 예제

위치 이동 => x,y

이동 속도 => speed => 실수 값 사용 
=> delta 값 계산.
=> sigma(delta * speed) = 초당 speed만큼 이동
=> 예제 참고
=> playerObject.cpp 파일내 applyPlayerObject 함수 참고

2D 와 1D 변환 공식 => y*width + x = 1차원 배열의 index
























