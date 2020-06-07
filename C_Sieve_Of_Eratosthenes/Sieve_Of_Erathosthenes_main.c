/*
The Sieve of Erathosthenes 
에라토스테네스의 체

대량의 소수를 한꺼번에 판별할 수 있는 알고리즘

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int number = 100000; //범위
int a[100001]; //수들을 넣을 배열

// 간단한 소수 판별 알고리즘
bool isPrimeNumber(int _x)
{
	int end = (int)sqrt(_x);

	for (int i = 2; i <= end; i++)
	{
		if (_x % i == 0)
		{
			return false;
		}
	}
	return true;
}

//에라토스테네스의 체
void primeNumberSieve()
{
	//초기화, 배열을 2부터 시작해서 정해진 범위까지 채워넣기
	for (int i = 2; i <= number; i++)
	{
		a[i] = i;
	}

	//합성수들을 지우기, 합성수 : 1과 자기자신 이외의 약수의 개수가 3개 이상인 자연수
	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0) //이미 지워진 수는 제외
		{
			continue;
		}

		/*
		j 에는 아래와 같이 * 2 되는 수가 들어간다

		i + i == 2 + 2 == i x 2 == 2 x 2
		i + i == 3 + 3 == i x 2 == 3 x 2
		i + i == 4 + 4 == i x 2 == 4 x 2
		…
		소수는 1과 자기 자신이외에 나누어 떨어지는 수가 없으므로
		2 x 2, 3 x 2, 4 x 2 등등 j 에 해당하는 수들은 합성수가 된다
		따라서 j 에 해당하는 수 들을 다 지워버리고 남는 수들은 소수가 된다
		*/
		for (int j = i + i; j <= number; j += i)
		{
			a[j] = 0; // 합성수들을 지우기
		}
	}

	for (int i = 2; i <= number; i++)
	{
		if (a[i] != 0) //지워진 수들을 제외하고 출력, 소수들을 출력
		{
			printf("%d ", a[i]);
		}
	}


}


int main()
{
	//printf("%d", isPrimeNumber(97));
	primeNumberSieve();
	return 0;
}