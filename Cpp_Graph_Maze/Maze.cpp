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
			if (x % 2 == 0 || y % 2 == 0) // ¦��
			{
				continue;
			}
			if (y == m_destPos.y && x == m_destPos.x) // ������
			{
				continue;
			}
			if (y == m_iSize - 2)
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road; // ���� �� ���� �ձ�
				continue;
			}
			if (x == m_iSize - 2)
			{
				m_ppMazeMap[y + 1][x] = e_BlockType::Road; // ���� �� ���� �ձ�
				continue;
			}
			if (int_rand(0, 2) == 0) //���� ���ڰ� 0�ΰ��, ������ ���� �ձ�
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road; 
				xCount++; //���������� ���� ��츦 �������
			}
			else //�ƴ� ���, ���������� ���� ����� �� �߿� �ϳ��� �� ���η� �ı�
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
			if (x % 2 == 0 || y % 2 == 0) //x�� ¦���̰ų�, y�� ¦�� �϶�
			{
				continue; //���� �ʱ�
			}
			if (y == m_destPos.y && x == m_destPos.x) //������
			{
				continue; //���� �ʱ�
			}
			if (y == m_iSize - 2) //���� ��ġ���� ���������� ���� ������ �̷θ� �ѷ��� ������ ������
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road;  //���������� �ձ�
				continue;
			}
			if (x == m_iSize - 2) //���� ��ġ���� ���������� ���� ������ �̷θ� �ѷ��� ������ ������
			{
				m_ppMazeMap[y + 1][x] = e_BlockType::Road; //���������� �ձ�
				continue;
			}
			if (int_rand(0, 1) == 0) //���� ������ 50% Ȯ���� ������ �Ǵ� �Ʒ����� �ձ�
			{
				m_ppMazeMap[y][x + 1] = e_BlockType::Road; // ������ ���� �ձ�
			}
			else
			{
				m_ppMazeMap[y + 1][x] = e_BlockType::Road; // �Ʒ��� ���� �ձ�
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


//�̷� �� ����
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
			if (x % 2 == 0 || y % 2 == 0) // ¦���� ������ ä���, Ȧ���� ��� ä���
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

//�̷� ������
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
			std::cout << "��";
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