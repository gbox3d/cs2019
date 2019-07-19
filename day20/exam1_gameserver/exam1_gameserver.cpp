// exam1_gameserver.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <stdlib.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

struct S_GameObject {
	int m_nStatus;
	double m_Xpos;
	double m_Ypos;
	int m_nShape;
};

char g_szIpTables[32][64];
S_GameObject g_GameObjs[32];

int main()
{
	for (int i = 0; i < 32; i++)
	{
		g_GameObjs[i].m_nStatus = 0;
		strcpy_s(g_szIpTables[i],sizeof(g_szIpTables[i]), "");
	}
	

	SOCKET hServerSocket;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("WSAStartup %d \n", WSAGetLastError());
		return EXIT_FAILURE;
	}
	
	//소켓오픈 
	hServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (hServerSocket == INVALID_SOCKET) {
		printf("INVALID_SOCKET %d \n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	sockaddr_in si_severAddr;
	memset(&si_severAddr,0,sizeof(sockaddr_in));

	//서버역활을 하기위한 주소 정보 셋업
	si_severAddr.sin_family = AF_INET;
	si_severAddr.sin_port = htons(3333); //htons,리틀엔디언 => 빅엔디언
	si_severAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	if (
		bind(hServerSocket, (sockaddr*)& si_severAddr, sizeof(sockaddr_in)) == SOCKET_ERROR
		)
	{
		printf("bind error %d \n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	while (1)
	{
		sockaddr_in si_other;

		memset(&si_other, 0, sizeof(sockaddr_in));
		int slen = sizeof(sockaddr_in);

		puts("wait request...");
		fflush(stdout);
		char szBuf[1024];
		memset(szBuf, 0, sizeof(szBuf));

		int recv_len = recvfrom(hServerSocket, szBuf, sizeof(szBuf), 0,
			(sockaddr*)& si_other, &slen);

		char _szIp[256];
		inet_ntop(AF_INET, &si_other.sin_addr, _szIp, sizeof(_szIp));
		printf_s("from : %s : %d", _szIp, 
			ntohs(si_other.sin_port) //ntohs,빅엔디언 => 리틀엔디언
		);

		//겹치는것이 있는지 검사.
		int i;
		for ( i = 0; i < 32; i++) {
			
			if (strcmp(g_szIpTables[i], _szIp) == 0 || strcmp("", g_szIpTables[i])==0 )
			{
				break;
			}

		}
		//저장
		if (i < 32) { 
			S_GameObject* pObj = (S_GameObject*)szBuf;
			strcpy_s(g_szIpTables[i],sizeof(g_szIpTables[i]), _szIp);
			g_GameObjs[i].m_Xpos = pObj->m_Xpos;
			g_GameObjs[i].m_Ypos = pObj->m_Ypos;
			g_GameObjs[i].m_nStatus = 1;
			printf_s("x:%f y:%f\n", pObj->m_Xpos, pObj->m_Ypos);
		}

		sendto(hServerSocket, (char*)g_GameObjs, sizeof(S_GameObject) * 32, 0,
			(sockaddr*)&si_other, sizeof(si_other));

	}

	closesocket(hServerSocket);
	WSACleanup();

}
