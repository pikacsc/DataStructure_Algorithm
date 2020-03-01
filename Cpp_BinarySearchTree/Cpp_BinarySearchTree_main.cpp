#include <iostream>
#include "MyBST.h"

int main()
{
	MyBST bst;
	bst.Insert(10);
	bst.Insert(4);
	bst.Insert(13);
	bst.Insert(6);
	bst.Insert(5);
	bst.Insert(7);
	bst.Insert(11);
	bst.Insert(20);
	bst.Insert(17);
	bst.Print2D();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	bst.DisplayAll();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Iterator" << std::endl;
	MyBST::iterator iter = bst.IterBegin();
	MyBST::iterator iterEnd = bst.IterEnd();

	for (iter = bst.IterBegin(); iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}