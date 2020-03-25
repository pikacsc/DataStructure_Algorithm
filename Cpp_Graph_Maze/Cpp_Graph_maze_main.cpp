#include "common.h"
#include "Maze.h"
#include "Player.h"


int main()
{
	//Ŀ�� �Ⱥ��̰� �ϱ�
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//�̷��ʱ�ȭ
	Maze maze(25);
	if (!maze.Init())
	{
		std::cout << "�̷� �ʱ�ȭ ����";
		exit(1);
	}

	//�÷��̾� �ʱ�ȭ
	Player player(g_startX, g_startY);
	maze.SetPlayer(&player);
	player.SetMap(&maze);
	player.Init();
	

	int lastTickCount = GetTickCount();
	int currentTickCount = 0;
	int deltaTick = 0;
	int frame = 0;
	const int WAIT_TICK = 1000 / 30; // 1000 == 1��
	while (1)
	{
		currentTickCount = GetTickCount();
		deltaTick = currentTickCount - lastTickCount;
		if (deltaTick >= WAIT_TICK) // 1/30 �ʿ� �ѹ� ����
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