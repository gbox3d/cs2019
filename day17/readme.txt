exam1
화면 리사이징
메뉴 -> size320,size640 추가
ID -> IDM_SIZE_320, IDM_SIZE_640

현재 화면 크기 얻는 함수
현재 윈도우 크기와 위치 얻는 함수
---------------------------------------------------
exam2
키보드 마우스 입력

WM(Windows Message)

32비트 데이터에서
LOWORD => 하위 16비트
HIWORD => 상위 16비트

16비트 데이터에서
LOBYTE => 하위 8비트
HIBYTE => 상위 8비트
-----------------------------------------------------
exam3
서브 클래싱
-------------------------------------------
exam4
GDI+
device context => 윈도우에 그리기 기능을 수행하기위한 오브잭트 
=>선,점, 체우기 도형,폰트 , 이미지 등등
필요 모듈 => Gdiplus.lib 

plus엔진 사용하기

plusengine.h plusengine.cpp

framework.h 에 추가(순서 주의)
#include "..\\..\\..\\cstudy\engine\irrlicht\include\irrlicht.h"
#include "..\\..\\..\\cstudy\engine\plusEngine.h"

winMain 함수의 메씨지 루프부분을 다음으로 교체
plusEngine::GDIPLUS_Loop(.....)


DrawImage(g_pImage, //gdi+ 이미지객체 포인터 
		Rect(250, 100, 16, 16), //그려질영역
		0, 0, 16, 16, //원본에서 가져올영역
		UnitPixel //단위지정
	);

-------------------------------------------













