#include <iostream>
#include "CQueue.h"

int main(void)
{
	// ASCHII 65 : A 
	// ASCHII 90 : Z
	////TestCode
	CQueue<char> queue;

	for (int i = 65; i <= 90; i++)
	{
		queue.push((char)i); //
	}

	queue.printQueue();

	std::cout << "\n\npop() : " << queue.pop() << " removed\n\n" << std::endl;

	queue.printQueue();

	std::cout << "\n\npop() : " << queue.pop() << " removed\n\n" << std::endl;

	queue.printQueue();

	queue.push('A');

	std::cout << "\n\npush() : " << 'A' << std::endl << std::endl;

	queue.printQueue();
	
	queue.push('B');

	std::cout << "\n\npush() : " << 'B' << std::endl << std::endl;

	queue.printQueue();


	/*
	CQueue<char> queue;
	int input = 0;
	char charInput = 0;
	while (1)
	{
		std::cout << "1.front()" << std::endl;
		std::cout << "2.back()" << std::endl;
		std::cout << "3.empty()" << std::endl;
		std::cout << "4.size()" << std::endl;
		std::cout << "5.push()" << std::endl;
		std::cout << "6.pop()" << std::endl;
		std::cout << "7.printQueue" << std::endl;
		std::cout << "0.Quit" << std::endl;
		std::cout << "input>>";
		std::cin >> input;
		if (input == 0)
		{
			break;
		}
		else if (input == 1)
		{
			std::cout << "front() : " << queue.front() << std::endl;
		}
		else if (input == 2)
		{
			std::cout << "back() : " << queue.back() << std::endl;
		}
		else if (input == 3)
		{
			std::cout << "is queue empty? : " << queue.empty() ? "TRUE" : "false";
			std::cout << std::endl;
		}
		else if (input == 4)
		{
			std::cout << "size : " << queue.size() << std::endl;
		}
		else if (input == 5)
		{
			std::cout << "input string data" << std::endl;
			std::cin >> charInput;
			queue.push(charInput);
		}
		else if (input == 6)
		{

			std::cout << "pop () : " << queue.pop() << " removed" << std::endl;
		}
		else if (input == 7)
		{
			queue.printQueue();
		}
	}
	*/

	return 0;
}
