#include <iostream>
#include "MyLinkedList.h"

int compare(const int& _iNum1, const int& _iNum2);

int main(void)
{	
	MyLinkedList<int> list(compare);

	list.push_back(2);
	list.push_back(7);
	list.push_back(3);
	list.push_back(4);
	list.push_back(1);
	list.push_back(6);
	list.push_back(5);
	list.push_back(8);
	
	MyLinkedList<int>::iterator iter = list.IterBegin();
	MyLinkedList<int>::iterator iterEnd = list.IterEnd();
	for (iter = list.IterBegin(); iter != iterEnd; ++iter)
	{
		std::cout << *iter << " ";
	}
	iter = list.IterBegin();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;


	return 0;
}

int compare(const int& _iNum1, const int& _iNum2)
{
	if (_iNum1 == _iNum2)
	{
		return 0;
	}
	else if (_iNum1 < _iNum2)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
