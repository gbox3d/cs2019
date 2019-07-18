// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <stdlib.h>
#include <WinSock2.h>
#include  <Ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

#define SERVER "192.168.0.15"
#define BUFLEN 512
#define PORT 3333

int main()
{
	sockaddr_in si_other;
	int s, slen;
	slen = sizeof(si_other);

	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf_s("WSAStartup() error code : %d\n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == SOCKET_ERROR) {		
		printf_s("socket() error code : %d\n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	memset((char*)& si_other, 0, slen);

	InetPton(AF_INET, TEXT(SERVER), &si_other.sin_addr.s_addr);
	//si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);

	while (1)
	{
		puts("메씨지를 보내세요.");
		gets_s(message);
		sendto(s, message, strlen(message), 0, (sockaddr*)& si_other, slen);

	}
}
