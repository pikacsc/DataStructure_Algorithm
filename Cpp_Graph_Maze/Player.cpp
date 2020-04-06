#include "Player.h"
#include "Maze.h"

Player::Player(int _x, int _y)
{
	m_Pos.x = _x;
	m_Pos.y = _y;
	m_Dir = (int)e_Dir::Up;
	m_Map = nullptr;
}

Player::~Player()
{
}

bool Player::Init()
{
	//RightHand();
	BFS();
	return true;
}

static int s_lastIndex = 0;
static int s_sumTick = 0;
void Player::Update(int _iDeltaTick)
{
	/*if (s_lastIndex >= m_pointsVect.size())
	{
		return;
	}
	s_sumTick += _iDeltaTick;

	if (s_sumTick >= 10)
	{
		s_sumTick = 0;
		m_Pos.y = m_pointsVect[s_lastIndex].y;
		m_Pos.x = m_pointsVect[s_lastIndex].x;
		s_lastIndex++;
	}*/

	if (s_lastIndex >= m_iStackCount)
	{
		return;
	}
	s_sumTick += _iDeltaTick;

	if (s_sumTick >= 10)
	{
		s_sumTick = 0;
		
		m_Pos.y = m_pointsStack.top().y;
		m_Pos.x = m_pointsStack.top().x;
		m_pointsStack.pop();
		s_lastIndex++;
	}
}

int Player::GetX()
{
	return m_Pos.x;
}

int Player::GetY()
{
	return m_Pos.y;
}

void Player::SetMap(Maze* _map)
{
	m_Map = _map;
}

void Player::RightHand()
{
	// 현재 바라보고 있는 방향을 기준으로, 좌표변화를 나타낸다.
	static int frontY[] = { -1, 0, 1, 0 };
	static int frontX[] = { 0, -1, 0, 1 };
	static int rightY[] = { 0, -1, 0, 1 };
	static int rightX[] = { 1, 0, -1, 0 };
	
	m_pointsVect.push_back(m_Pos);

	POINT destPos = m_Map->GetDestPos();
	while (destPos.y != m_Pos.y || destPos.x != m_Pos.x)
	{
		if (m_Map->GetBlockTypeByXY(m_Pos.x + rightX[m_Dir], m_Pos.y + rightY[m_Dir]) == e_BlockType::Road)
		{
			m_Dir = (m_Dir - 1 + 4) % 4;

			m_Pos.y += frontY[m_Dir];
			m_Pos.x += frontX[m_Dir];
			m_pointsVect.push_back(m_Pos);
		}
		else if (m_Map->GetBlockTypeByXY(m_Pos.x + frontX[m_Dir], m_Pos.y + frontY[m_Dir]) == e_BlockType::Road)
		{
			m_Pos.y += frontY[m_Dir];
			m_Pos.x += frontX[m_Dir];
			m_pointsVect.push_back(m_Pos);
		}
		else
		{
			m_Dir = (m_Dir + 1 + 4) % 4;
		}
	}
}

void Player::DFS()
{
	
}

void Player::BFS()
{
	static int deltaY[] = { -1, 0, 1, 0 };
	static int deltaX[] = {  0, -1, 0, 1 };
	int iMapSize = m_Map->GetMapSize();

	bool** ppbFound = new bool* [iMapSize]; 
	for (int i = 0; i < iMapSize; ++i)
	{
		ppbFound[i] = new bool[iMapSize];
		memset(ppbFound[i], 0, sizeof(bool) * iMapSize);
	}

	POINT** ppPosParent = new POINT * [iMapSize];
	for (int i = 0; i < iMapSize; ++i)
	{
		ppPosParent[i] = new POINT[iMapSize];
		memset(ppPosParent[i], 0, sizeof(POINT) * iMapSize);
	}

	std::queue<POINT> queue;

	queue.push(m_Pos);
	ppbFound[m_Pos.y][m_Pos.x] = true; // 첫시작점은 true 체크
	ppPosParent[m_Pos.y][m_Pos.x] = m_Pos; //첫시작점 기록

	while (queue.size() > 0)
	{
		POINT nowPos = queue.front();
		queue.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nextY = nowPos.y + deltaY[i];
			int nextX = nowPos.x + deltaX[i];

			if (nextX < 0 || nextX >= iMapSize || nextY < 0 || nextY >= iMapSize) //X 또는 Y 가 0 ~ 맵사이즈에서 벗어날때, 즉 0보다 작거나, 맵사이즈 보다 클때
			{
				continue;
			}
			if (m_Map->GetBlockTypeByXY(nextX, nextY) == e_BlockType::Wall)  // 인접하지 않을때
			{
				continue;
			}
			if (ppbFound[nextY][nextX] == true) // 이미 발견한 루트일때
			{
				continue;
			}

			queue.push(POINT{ nextX, nextY });
			ppbFound[nextY][nextX] = true; //발견했다는 사실을 true
			ppPosParent[nextY][nextX] = nowPos; //발견한 x,y좌표를 기록
		}
	}

	int tempY = m_Map->GetDestPos().y;
	int tempX = m_Map->GetDestPos().x;
	while (ppPosParent[tempY][tempX].y != tempY || ppPosParent[tempY][tempX].x != tempX)
	{
		POINT tempPos{ tempX,tempY };
		m_pointsStack.push(tempPos);
		tempY = ppPosParent[tempY][tempX].y;
		tempX = ppPosParent[tempY][tempX].x;
	}

	m_pointsStack.push(POINT{ tempX,tempY });
	m_iStackCount = static_cast<int>(m_pointsStack.size());

	//동적 이차원 배열들 자원해제
	for (int i = 0; i < iMapSize; ++i)
	{
		delete[] ppbFound[i];
		ppbFound[i] = nullptr;
	}
	delete[] ppbFound;
	ppbFound = nullptr;

	for (int i = 0; i < iMapSize; ++i)
	{
		delete[] ppPosParent[i];
		ppPosParent[i] = nullptr;
	}
	delete[] ppPosParent;
	ppPosParent = nullptr;
}
