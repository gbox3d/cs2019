// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


#include <stdlib.h>
#include <WinSock2.h>
#include  <Ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

#define BUFLEN 256
#define PORT 3333


struct S_TESTPACKET {
	int m_nCheckSum;
	int m_nCode;
};

//데이터 받기 예제 
sockaddr_in g_listener_addr; //리스너 
SOCKET g_socket;

int main()
{
	int recv_len;
	char buf[BUFLEN];
	WSADATA wsa;

	WSAStartup(MAKEWORD(2, 2), &wsa);
	g_socket = socket(AF_INET, SOCK_DGRAM, 0);

	if (g_socket == INVALID_SOCKET) {
		printf_s("error socket : %d\n",WSAGetLastError());
	}

	g_listener_addr.sin_family = AF_INET;
	g_listener_addr.sin_port = htons(PORT);
	g_listener_addr.sin_addr.S_un.S_addr = INADDR_ANY;

	if (
		bind(g_socket, (sockaddr*)& g_listener_addr, sizeof(g_listener_addr)) == SOCKET_ERROR
		)
	{
		printf_s("error socket bind : %d\n", WSAGetLastError());
	}

	puts("bind success");

	while (1)
	{
		sockaddr_in si_other;
		int slen;
		slen = sizeof(si_other);

		puts("wait data...");
		fflush(stdout);
		memset(buf, 0, BUFLEN);
		recv_len = recvfrom(g_socket, buf, BUFLEN, 0, (sockaddr*)& si_other, &slen);

		char _szBuf[256];
		
		//주소 출력 
		inet_ntop(AF_INET, &si_other.sin_addr, _szBuf, sizeof(_szBuf));
		//printf_s("from :%s \n",_szBuf);
		//printf_s("data : %s \n", buf);

		S_TESTPACKET* pPacket = (S_TESTPACKET*)buf;
		if (pPacket->m_nCheckSum == 100) {
			puts("success");
			printf_s("code: %d  checksum :%d \n", pPacket->m_nCode, pPacket->m_nCheckSum);
		}
		else {
			puts("failed");
		}

	}

	closesocket(g_socket);
	WSACleanup();


	return 0;
}
