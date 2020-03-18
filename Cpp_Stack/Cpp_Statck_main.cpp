#include <iostream>
#include "CStack.h"

int main()
{
	CStack<int> stackInt;

	for (int i = 0; i < 100; ++i)
	{
		stackInt.push(i + 1);
	}

	while (!stackInt.empty())
	{
		std::cout << stackInt.pop() << std::endl;
	}


	return 0;
}