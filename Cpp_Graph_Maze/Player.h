#pragma once
#include "common.h"

class Maze;

class Player
{
	enum class e_Dir
	{
		Up = 0,
		Left = 1,
		Down = 2,
		Right = 3
	};
private:
	POINT		m_Pos;
	int		    m_Dir;
	class Maze*	m_Map;
	std::vector<POINT> m_pointsVect;
public:
	Player(int _x, int _y);
	~Player();

	bool Init();
	void Update(int _iDeltaTick);

	int GetX();
	int GetY();

	void SetMap(Maze* _map);

private:
	void RightHand();
};

