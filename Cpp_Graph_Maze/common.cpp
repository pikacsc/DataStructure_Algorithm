#include "common.h"


int int_rand(int _start, int _end)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> dice(_start, _end);
	return dice(mersenne);
}