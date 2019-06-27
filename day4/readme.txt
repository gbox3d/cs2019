문자(char) 데이터 처리, 84p
어제배웠던 데이터 다루는 법=> 숫자
=> 정수, 실수
=> int, double(float)
=> int(4byte), double(8byte) => bit,byte
=> char(1 byte)
=> word(2byte) => dword(4byte) => ddword(8)
=> 1001 => 8421 
=> (1,0,0,1) * (8,4,2,1) = (1*8)+(0*4)+(0*2)+(1*1) = 9
=> 0000 => 0
=> 1111 => 15(f) => 9..10 => 9..a b c d e f
=> 0000 0000 => 00 =>  
=> 1111 1111 => 00~ff => 1byte
=> ff => (128,64,32,16, 8,4,2,1) => 0~255
=> 1 byte=> 1 문자(아스키코드 기준)
=> 2 byte => 0~65535

--------------------------------------
파워쉘 사용하기
검색아이콘 클릭=> power shell입력
=> windows PowerShell앱실행=> cmd 사용법과 유사.
=> dir(ls), copy(cp),move(mv), del(rm)

---------------------------------------------
우측 솔루션 탐색기=>프로잭트=>헤더파일폴더=>pch.h오픈
=> #include <stdio.h>

----------------------------------------
char => '문자' => "문자열"
=> int(%d) double(lf%) 
=> char(%c)
const char *,char []=> 문자열
=> 출력=> %s
=> 입력 => scanf_s 
=> 3번째 인자에 입력버퍼의 바이트수 반드시 기입
=> scanf_s("%c",&_c,1) => 여기서 1은 1바이트를 뜻함

TCHAR => wide char vs mult byte
TCHAR => char->TCHAR , TCHAR->char
stl::string

=> sprintf => 문자열로 결과를 출력
=> sscanf => 키보드가 아닌 형식화된 문자열로 부터 입력









