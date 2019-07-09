github.com 에 로그인 하세요 
=> New 버튼을 클릭
=> 새로운 "원격" 저장소 를 생성하세요.
(어제는 "로컬" 저장소를 만들었었죠.)
=> 저장소 이름을 정해주세요.
=> public 선택
=> create repository 버튼 클릭!
=> cmd(명령프롬프트)창 열고=> C:\cs2019\test 디랙토리로 이동
=> git status => 깃상태확인
=> nothing to commit, working tree clean 메씨지로 이상없음 확인
=> 원격 저장소 위치를 지정
=> git remote add orgin "저장소 주소(url)"
=> "본인의 저장소" 주소를 입력하세요.
=> 무소식이 희소식(성공하면 아무런 메씨지가 없음)
=> git push -u origin master
=> 로그인 창에서 본인의 github 아이디로 로그인
=> 새로운 원격 branch 가 생성되고 파일이 업로드됨

---------------------------------------------------
=> git remote add origin 주소를 잘못치시것 때문에..
=> git remote remove origin 주소를 지운다.
--------------------------------------------------

=> 새로운 파일만들기(test directory에) => test.cpp
=> cmd창에서 파일 이동시키기 => move 명령어 사용
=> cd .. => 상위 폴더(디랙토리)로 나가기
=> move 이동시킬파일이름 이동시킬위치
=> move hello.txt ./test 
=> cd test 확인
=> 다시 상위로 옮기려면=> move ./hello.txt ../
-------------------------------------------------------

새로운 파일 저장소에 신규 등록

test.cpp 를 신규 등록하기
=> git add test.cpp   <= 스테이징 처리
=> git commit test.cpp -m "test.cpp추가함"
=> git commit . -m "모두 올리기.." => 커밋이 안된 모든 파일 커밋
=> *.* , . => 모든 파일
=> *.cpp
=> hello.* => 확장자에 무관하게 파일이름이 hello인것 모두

=> -m "이부분은 여러분이 알아서 자유롭게 아무말이나 쓰셔도되요."
=> 이미 이전에 저장소 url을 등록했습니다.
(git remote add orgin "저장소 url") => add 한번만 해도됨.
=> git push => 결론은 무엇?
=> 앞으로는 add,commit,push 만 하면된다.
=> git add 파일이름
=> git commit 파일이름 -m "커밋에 대한 간략한 설명(영문3자이상)"
=> git push 

=> 예를 다시 (1.txt)
=> git add 1.txt
=> git commit 1.txt -m "1.txt올리기."
=> git push

=> push=> 밀어내기 => 로컬에 있는 파일을 원격(네드웍) 밀어낸다.

=> 커밋만 하면 github에 올라가지않는다.
=> push 를 해야 github에 파일이 올라간다(적용된다).
=> -m "..."

--------------------------------------------
내용 갱신 => update
=> add???? 해야함??? => add 는 인덱싱된 상태.
=> X
=> commit 부터 시작
=> 
------
=> git commit test.cpp -m "저녁에를 \n 오전으로 바꿈 "
=> git push


------------------------------------
branch : master
=> 평행세계

=> 여러개의 버전 관리용도
=> 'dev_1' 이라는 브랜치 만들기 
=> git branch dev_1
=> 브랜치간 이동(방금 만든 브랜치로 이동) 
=> git checkout dev_1
=> git status =>브랜치(가지) 이동 확인
=> git add 3.txt 
=> git commit 3.txt -m "..."


git push origin master =>
=> 여기서 origin 원격 저장소 위치의 이름(별명)
=> 여기서 master 푸쉬 대상이되는 브랜치
=> 그렇다면!! 우리가 원하는것 => dev_1 푸쉬 하고싶어요.

=>git push -u origin dev_1 => master 대신에 dev_1 으로 푸쉬

=>dev_2 가지 만들고 4.txt 파일 추가 하고

=>git push -D origin

---------------------------------------------------

test 폴더 지우고 
git clone 저장소url 

스테이징=>커밋=>원격저장소지정 => 업로드(push)

----------------------------------------


git clone https://github.com/gbox3d/cs2019.git
=> 제 작업 폴더가 복사 됩니다.
=> 하위에 폴더를 하나 만들고 클론됩니다.

'vscode' 설치해 주세요.


------------------------------

vs2017,2019 => 시작화면 => 새프로잭트 만들기 클릭!

콘솔 응용프로그램
=> 이름 : test
=> 위치 : C:\cs2019\study\day2\
=> 솔루션이름 : test

컴파일된(exe) 실행파일 =>
=> Debug 폴더로 이동 => exe 찾아 실행

기존 솔루션에 새프로잭트 추가
=> 솔루션 탐색기에서 솔루션 이름에 대고 마우스 우클릭
=> 메뉴에서 '추가' 선택
=> 새 프로잭트 선택
=> 다이얼로그에서 이름을 정한다.(예 exam2)

vs 업그레이드 확인
=>시작메뉴=> visual studio installer 실행










































