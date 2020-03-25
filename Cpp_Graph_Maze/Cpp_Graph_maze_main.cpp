#include "common.h"
#include "Maze.h"
#include "Player.h"


int main()
{
	//커서 안보이게 하기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//미로초기화
	Maze maze(25);
	if (!maze.Init())
	{
		std::cout << "미로 초기화 실패";
		exit(1);
	}

	//플레이어 초기화
	Player player(g_startX, g_startY);
	maze.SetPlayer(&player);
	player.SetMap(&maze);
	player.Init();
	

	int lastTickCount = GetTickCount();
	int currentTickCount = 0;
	int deltaTick = 0;
	int frame = 0;
	const int WAIT_TICK = 1000 / 30; // 1000 == 1초
	while (1)
	{
		currentTickCount = GetTickCount();
		deltaTick = currentTickCount - lastTickCount;
		if (deltaTick >= WAIT_TICK) // 1/30 초에 한번 실행
		{
			system("cls");
			//std::cout << "Delta TickCount : " << deltaTick << std::endl;
			lastTickCount = currentTickCount;
			player.Update(deltaTick);
			maze.Render();
		}
	}

	return 0;
}