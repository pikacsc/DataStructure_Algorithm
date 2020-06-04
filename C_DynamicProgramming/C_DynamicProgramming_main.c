/*
Dynamic Programming

피보나치 수열

*/
#include <stdio.h>

// 피보나치 수열


int d[100];
// 피보나이 수열의 점화식 : D[i] = D[i -1] + D[i - 2]
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
	printf("%d ", dp(10));// 10번째까지의 피보나치 수열
	return 0;
}