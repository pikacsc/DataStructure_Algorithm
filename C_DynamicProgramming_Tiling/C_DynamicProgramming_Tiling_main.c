/*
Dynamic Programming

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define Problem_11727 // select problem


#ifdef Problem_11726
/*
Ÿ�ϸ� ����_1
https://www.acmicpc.net/problem/11726

2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1, 000)

���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10, 007�� ���� �������� ����Ѵ�.

ex1)
input : 2
output : 2

ex2)
input : 9
output : 55
*/

int d[1001];

//��ȭ��
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
Ÿ�ϸ� ����_2
https://www.acmicpc.net/problem/11727

2��n ���簢���� 1��2, 2��1�� 2��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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


//��ȭ��
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