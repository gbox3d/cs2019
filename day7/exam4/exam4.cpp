// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void displayMap(int _Map[])
{
	for (int iy = 0; iy < 8; iy++)
	{
		for (int ix = 0; ix < 8; ix++)
		{
			int _cell = _Map[(iy * 8) + ix];
			if (_cell == 0) { printf_s(" "); }
			else if (_cell == 1) { printf_s("#"); }
			else if (_cell == 2) { printf_s("@"); }
			else if (_cell == 3) { printf_s("A"); }
		}
		printf_s("\n");
	}
}

void putChar(int _Map[],int x,int y,int c)
{
	_Map[(y * 8) + x] = c;
}

int main()
{
	int _Map[] = 
	{
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,2,0,0,1,
		1,0,0,2,2,0,0,1,
		1,0,0,2,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

	//주인공 오브잭트 정의 
	int player_x, player_y;
	player_x = 2;
	player_y = 2;
	
	system("cls");
	int _bLoop = 1;
	while (_bLoop)
	{
		puts("0.exit\n1.display map\n2.putChar");
		printf_s("cmd>");
		int _cmd; scanf_s("%d", &_cmd);
		switch (_cmd)
		{
		case 0: _bLoop = 0; puts("종료합니다."); break;
		case 1: //display
		{
			system("cls"); 
			putChar(_Map, player_x, player_y, 3);  //플레이어 위치 갱신 
			displayMap(_Map); 
		}
		break;
		case 2: 
		{
			int _x, _y;
			printf_s("input x y=>"); scanf_s("%d %d", &_x, &_y);
			putChar(_Map, _x,_y, 3);
		}
		break; //putObject
		case 3: 
		{
			putChar(_Map,player_x,player_y, 0);
			player_x += 1;
		}
			break; //move east
		case 4:
		{	
			putChar(_Map, player_x, player_y, 0);
			player_x -= 1;
		}
		break; //move west
		case 5:
		{
			putChar(_Map, player_x, player_y, 0);
			player_y += 1;
		}
		break; //move south
		case 6:
		{
			putChar(_Map, player_x, player_y, 0);
			player_y -= 1;
		}
		break; //move north

		default:
			break;
		}
	}

	
}

