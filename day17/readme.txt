exam1
ȭ�� ������¡
�޴� -> size320,size640 �߰�
ID -> IDM_SIZE_320, IDM_SIZE_640

���� ȭ�� ũ�� ��� �Լ�
���� ������ ũ��� ��ġ ��� �Լ�
---------------------------------------------------
exam2
Ű���� ���콺 �Է�

WM(Windows Message)

32��Ʈ �����Ϳ���
LOWORD => ���� 16��Ʈ
HIWORD => ���� 16��Ʈ

16��Ʈ �����Ϳ���
LOBYTE => ���� 8��Ʈ
HIBYTE => ���� 8��Ʈ
-----------------------------------------------------
exam3
���� Ŭ����
-------------------------------------------
exam4
GDI+
device context => �����쿡 �׸��� ����� �����ϱ����� ������Ʈ 
=>��,��, ü��� ����,��Ʈ , �̹��� ���
�ʿ� ��� => Gdiplus.lib 

plus���� ����ϱ�

plusengine.h plusengine.cpp

framework.h �� �߰�(���� ����)
#include "..\\..\\..\\cstudy\engine\irrlicht\include\irrlicht.h"
#include "..\\..\\..\\cstudy\engine\plusEngine.h"

winMain �Լ��� �޾��� �����κ��� �������� ��ü
plusEngine::GDIPLUS_Loop(.....)


DrawImage(g_pImage, //gdi+ �̹�����ü ������ 
		Rect(250, 100, 16, 16), //�׷�������
		0, 0, 16, 16, //�������� �����ÿ���
		UnitPixel //��������
	);

-------------------------------------------













