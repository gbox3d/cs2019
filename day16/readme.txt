win32 api

Applycation Programming Interface

win,unix(liux),macOSX,android => c => kernel

API => 커널과 통신하기위한것들의 모음 ,C/c++ =>C#,

=>wpf, mfc

프로잭트 생성
새프로잭트 => 데스크톱 어플리캐이션 
메뉴 만들기=> 리소스 폴더 => .rc 클릭
=> menu 폴더 => IDC_EXAM1 클릭
=> 메뉴 편집 => 속성(우측하단)

win32 GUI => 컨트롤 => CreateWindow
GetDlgItem
WM_COMMAND

--------------------------------------------------
비트 연산자
|, &, >> , <<

4비트 => 8421
8비트 => 1바이트 => 0000 0000 

=> 0000 0001 => 0x01
=> 1001 0110 => 
     8421 8421 =>   0x96

1000 >> 1  => 0100
        >> 2 => 0010
0001 << 1 => 0010
       << 2 => 0100

1010 or 0000 => 1010
1010 and 1111 => 1010

전처리기 => 컴파일러에게 지정해주는 값 
#define  

define 구문에따른 컴파일러 로직제어 구문
#ifdef  , # endif ,#elseif

프로잭트속성=> c/c++=> 전처리기 => 구문 (#define )선언
-------------------------------------------------------------------
exam5  win32 사칙연산 계산기

InvalidateRect => WM_PAINT 메씨지 발생 
--------------------------------------------------
exam6 
dialogBox
.rc => Dialog 폴더

hWnd -> dialog
hWnd-> WndProc
AboutDialog ->About


















