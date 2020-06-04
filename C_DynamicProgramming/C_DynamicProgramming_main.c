/*
Dynamic Programming

�Ǻ���ġ ����

*/
#include <stdio.h>

// �Ǻ���ġ ����


int d[100];
// �Ǻ����� ������ ��ȭ�� : D[i] = D[i -1] + D[i - 2]
int dp(int _x)
{
	if (_x == 1)
	{
		return 1;
	}
	if (_x == 2)
	{
		return 2;
	}
	if (d[_x] != 0) //memoization
	{
		return d[_x]; 
	}

	return dp(_x - 1) + dp(_x - 2);
}

int main(void)
{
	printf("%d ", dp(10));// 10��°������ �Ǻ���ġ ����
	return 0;
}