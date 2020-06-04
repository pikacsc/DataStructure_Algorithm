/*
Dynamic Programming

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define Problem_11727 // select problem


#ifdef Problem_11726
/*
타일링 문제_1
https://www.acmicpc.net/problem/11726

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1, 000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10, 007로 나눈 나머지를 출력한다.

ex1)
input : 2
output : 2

ex2)
input : 9
output : 55
*/

int d[1001];

//점화식
//D[n] = D[n - 1] + D[n - 2]
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

	return d[_x] = (dp(_x - 1) + dp(_x - 2)) % 10007;
}

#endif // Problem_11726





#ifdef Problem_11727
/*
타일링 문제_2
https://www.acmicpc.net/problem/11727

2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

ex1)
input : 2
output : 3

ex2)
input : 8
output : 171


ex3)
input : 12
output : 2731

*/



int d[1001];


//점화식
//D[n] = D[n - 1] + (D[n - 2]) * 2)
int dp(int _x)
{
	if (_x == 1)
	{
		return 1;
	}

	if (_x == 2)
	{
		return 3;
	}

	if (d[_x] != 0) //memoization
	{
		return d[_x];
	}

	return d[_x] = (dp(_x - 1) + dp(_x - 2) * 2) % 10007;
}
#endif // Problem_11727




int main()
{
	int x;
	scanf("%d", &x);
	printf("%d", dp(x));

}