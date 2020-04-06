#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <queue>
#include <stack>
#include <random>

constexpr int g_startX = 1;
constexpr int g_startY = 1;

enum class e_BlockType
{
	Road,
	Wall
};

enum class e_ConsoleColor
{
	black_BlackBG = 0, //road
	red_BlackBG = 4,   //goal
	white_BlackBG = 15,//player 
	blue_BlueBG = 17   //wall
};

int int_rand(int _start, int _end);