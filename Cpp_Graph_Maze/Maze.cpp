#include "Maze.h"
#include "Player.h"

Maze::Maze(int _MazeSize)
	:m_iSize(_MazeSize)
{
	m_ppMazeMap = new e_BlockType*[_MazeSize];
	for (int i = 0; i < _MazeSize; ++i)
	{
		m_ppMazeMap[i] = new e_BlockType[_MazeSize];
		memset(m_ppMazeMap[i], 0, sizeof(e_BlockType) * _MazeSize);
	}

	m_destPos.y = _MazeSize - 2;
	m_destPos.x = _MazeSize - 2;
	m_Player = nullptr;
}

Maze::~Maze()
{
	for (int i = 0; i < m_iSize; ++i)
	{
		delete[] m_ppMazeMap[i];
		m_ppMazeMap[i] = nullptr;
	}
	delete[] m_ppMazeMap;
	m_ppMazeMap = nullptr;

	delete m_Player;
}

void Maze::GenerateMazeBySideWinder()
{
	for (int y = 0; y < m_iSize; y++)
	{
		int xCount = 1;
		for (int x = 0; x < m_iSize; x++)
		{
			if (x % 2 == 0 || y % 2 == 0) // 짝수
			{
				continue;
			}
			if (y == m_destPos.y && x == m_destPos.x) // 목적지
			{
				continue;
			}
			if (y == m_iSize - 2)
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road; // 가로 축 으로 뚫기
				continue;
			}
			if (x == m_iSize - 2)
			{
				m_ppMazeMap[y + 1][x] = e_BlockType::Road; // 세로 축 으로 뚫기
				continue;
			}
			if (int_rand(0, 2) == 0) //랜덤 숫자가 0인경우, 가로축 으로 뚫기
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road; 
				xCount++; //가로축으로 뚫은 경우를 세어놓음
			}
			else //아닌 경우, 가로축으로 뚫은 경우의 수 중에 하나를 찝어서 세로로 파기
			{
				int randomXindex = int_rand(0, xCount - 1); 
				m_ppMazeMap[y + 1][x - randomXindex * 2] = e_BlockType::Road;
				xCount = 1;
			}
		}
	}
}

void Maze::GenerateMazeByBinaryTree()
{
	for (int y = 0; y < m_iSize; y++)
	{
		for (int x = 0; x < m_iSize; x++)
		{
			if (x % 2 == 0 || y % 2 == 0) //x가 짝수이거나, y가 짝수 일때
			{
				continue; //뚫지 않기
			}
			if (y == m_destPos.y && x == m_destPos.x) //목적지
			{
				continue; //뚫지 않기
			}
			if (y == m_iSize - 2) //현재 위치에서 세로축으로 벽을 뚫으면 미로를 둘레를 뚫을수 있으면
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road;  //가로축으로 뚫기
				continue;
			}
			if (x == m_iSize - 2) //현재 위치에서 가로축으로 벽을 뚫으면 미로를 둘레를 뚫을수 있으면
			{
				m_ppMazeMap[y + 1][x] = e_BlockType::Road; //세로축으로 뚫기
				continue;
			}
			if (int_rand(0, 1) == 0) //난수 생성후 50% 확률로 오른쪽 또는 아래쪽을 뚫기
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road; // 오른쪽 길을 뚫기
			}
			else
			{
				m_ppMazeMap[y + 1][x] = e_BlockType::Road; // 아래로 길을 뚫기
			}

		}
	}
}

void Maze::SetPlayer(Player* _player)
{
	m_Player = _player;
}

POINT Maze::GetDestPos(void) const
{
	return m_destPos;
}

e_BlockType Maze::GetBlockTypeByPos(POINT _pos)
{
	return m_ppMazeMap[_pos.y][_pos.x];
}

e_BlockType Maze::GetBlockTypeByXY(int _iX, int _iY)
{
	return m_ppMazeMap[_iY][_iX];
}


//미로 벽 생성
bool Maze::Init()
{
	if (m_iSize % 2 == 0)
	{
		return false;
	}

	for (int y = 0; y < m_iSize; y++)
	{
		for (int x = 0; x < m_iSize; x++)
		{
			if (x % 2 == 0 || y % 2 == 0) // 짝수는 벽으로 채우고, 홀수는 길로 채우기
			{
				m_ppMazeMap[y][x] = e_BlockType::Wall; 
			}
			else
			{
				m_ppMazeMap[y][x] = e_BlockType::Road;
			}
		}
	}

	//GenerateMazeBySideWinder();
	GenerateMazeByBinaryTree();
	return true;
}

static int GetBlockColorNum(e_BlockType _blockType);

//미로 렌더링
void Maze::Render()
{
	for (int y = 0; y < m_iSize; y++)
	{
		for (int x = 0; x < m_iSize; x++)
		{
			if (y == m_Player->GetY() && x == m_Player->GetX())
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)e_ConsoleColor::white_BlackBG);
			}
			else if (y == m_destPos.y && x == m_destPos.x)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)e_ConsoleColor::red_BlackBG);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GetBlockColorNum(m_ppMazeMap[y][x]));
			}
			std::cout << "■";
		}
		std::cout << std::endl;
	}
	//set default color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int Maze::GetMapSize(void) const
{
	return m_iSize;
}

static int GetBlockColorNum(e_BlockType _blockType)
{
	switch (_blockType)
	{
	case e_BlockType::Road:
		return (int)e_ConsoleColor::black_BlackBG;
	case e_BlockType::Wall:
		return (int)e_ConsoleColor::blue_BlueBG;
	default:
		return (int)e_ConsoleColor::black_BlackBG;
	}
}