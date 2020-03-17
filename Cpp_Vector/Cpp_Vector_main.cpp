#include <iostream>
#include "CVector.h"

int main()
{
	CVector<int> vector_int;
	
	
	
	vector_int.reserve(100);

	for (int i = 0; i < 100; ++i)
	{
		vector_int.push_back(i + 1);
	}

	/*for (int i = 0; i < vector_int.size(); ++i)
	{
		std::cout << vector_int[i] << std::endl;
	}*/

	CVector_Iterator<int> iter = vector_int.iterBegin();
	CVector_Iterator<int> iterEnd = vector_int.iterEnd();
	
	for (iter; iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}
	return 0;
}