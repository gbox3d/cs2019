// exam2_gameclient.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "exam2_gameclient.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


int g_keyTable[1024];
S_GameObject g_MyGameObj;

S_GameObject g_GameObjs[32];

SOCKET g_hSocket = 0;
sockaddr_in si_ServerAddr;


void OnRender(double fDelta, Graphics* pGrp)
{
	
	if (fDelta > 0) {
		g_MyGameObj.m_Xpos -= g_keyTable[VK_LEFT] * fDelta * 25.0;
		g_MyGameObj.m_Xpos += g_keyTable[VK_RIGHT] * fDelta * 25.0;
		g_MyGameObj.m_Ypos -= g_keyTable[VK_UP] * fDelta * 25.0;
		g_MyGameObj.m_Ypos += g_keyTable[VK_DOWN] * fDelta * 25.0;


		if (g_hSocket != 0) {
			static double _accTick = 0;
			_accTick += fDelta;
			if (_accTick > 1.0)
			{
				_accTick = 0.0;
				memset(&si_ServerAddr, 0, sizeof(si_ServerAddr));
				InetPton(AF_INET, L"192.168.0.15", &si_ServerAddr.sin_addr.S_un.S_addr);
				si_ServerAddr.sin_family = AF_INET;
				si_ServerAddr.sin_port = htons(3333);

				//데이터 보내기 
				sendto(g_hSocket, (const char*)& g_MyGameObj, sizeof(S_GameObject), 0,
					(sockaddr*)& si_ServerAddr, sizeof(si_ServerAddr));

				//데이터 받기
				int slen = sizeof(si_ServerAddr);
				recvfrom(g_hSocket, (char*)& g_GameObjs, sizeof(S_GameObject) * 32, 0,
					(sockaddr*)& si_ServerAddr, &slen
				);

			}

		}

	}

	
	
	pGrp->Clear(Color::Black);
	pGrp->TranslateTransform(256, 256); //화면 중간을 원점으로(0,0)

	GraphicsState _gs;
	for (int i = 0; i < 32; i++)
	{
		if (g_GameObjs[i].m_nStatus != 0)
		{
			_gs = pGrp->Save();
			pGrp->TranslateTransform(g_GameObjs[i].m_Xpos,g_GameObjs[i].m_Ypos);
			Pen _pen(Color(255, 0, 0));
			pGrp->DrawEllipse(&_pen, -8, -8, 16, 16);

			pGrp->Restore(_gs);
		}
	}


	pGrp->ResetTransform();

}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

	for (int i = 0; i < 32; i++)
	{
		g_GameObjs[i].m_nStatus = 0; //not active
	}
	g_GameObjs[0].m_nStatus = 1;

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM2GAMECLIENT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM2GAMECLIENT));

    MSG msg;

	plusEngine::GDIPLUS_Loop(msg, Rect(0, 0, 512, 512),
		NULL, NULL, OnRender, NULL
	);

    
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM2GAMECLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM2GAMECLIENT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_KEYDOWN:
		g_keyTable[wParam] = 1;
		break;
	case WM_KEYUP:
		g_keyTable[wParam] = 0;
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
			case IDM_CONNECT:
			{
				WSADATA wsa;
				WSAStartup(MAKEWORD(2, 2), &wsa);
				g_hSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

			}
				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		if (g_hSocket) {
			closesocket(g_hSocket);
			WSACleanup();
		}
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
