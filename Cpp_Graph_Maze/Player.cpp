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
	RightHand();
	return true;
}

static int s_lastIndex = 0;
static int s_sumTick = 0;
void Player::Update(int _iDeltaTick)
{
	if (s_lastIndex >= m_pointsVect.size())
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
