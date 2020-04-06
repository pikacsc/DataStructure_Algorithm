#pragma once
#include "common.h"

class Player;

class Maze
{
public:
	Maze(int _MazeSize);
	~Maze();
private:
	const int			m_iSize;
	e_BlockType			**m_ppMazeMap;
	POINT				m_destPos;
	class Player*		m_Player;

public:
	//미로 만들기
	bool Init();


	//미로 렌더링
	void Render();

	int GetMapSize(void) const;

	void SetPlayer(Player* _player);

	POINT GetDestPos(void) const;

	e_BlockType GetBlockTypeByPos(POINT _pos);
	e_BlockType GetBlockTypeByXY(int _iX, int _iY);
private:
	void GenerateMazeBySideWinder();

	void GenerateMazeByBinaryTree();

};

