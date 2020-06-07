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
			i == 2, j == 4
			i == 2, j == 6
			i == 2, j == 8
			i == 2, j == 10
			i == 2, j == 12
			i == 2, j == 14
			i == 2, j == 16
			i == 2, j == 18

			i == 3, j == 6
			i == 3, j == 9
			i == 3, j == 12
			i == 3, j == 15
			i == 3, j == 18
			i == 3, j == 21
			i == 3, j == 24
			i == 3, j == 27
			...
			아래 for문을 돌리면 위와 같은 값들로 초기화된다, 잘보면 소수의 배수들이자 합성수
			라는 것을 알 수 있다
			이미 지워진 수는 넘어가고, 지워지지 않은 수들(소수)을 기준으로 배수들을 찾아서
			지워준다
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