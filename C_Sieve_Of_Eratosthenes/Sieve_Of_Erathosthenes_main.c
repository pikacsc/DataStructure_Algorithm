/*
The Sieve of Erathosthenes 
�����佺�׳׽��� ü

�뷮�� �Ҽ��� �Ѳ����� �Ǻ��� �� �ִ� �˰���

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int number = 100000; //����
int a[100001]; //������ ���� �迭

// ������ �Ҽ� �Ǻ� �˰���
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

//�����佺�׳׽��� ü
void primeNumberSieve()
{
	//�ʱ�ȭ, �迭�� 2���� �����ؼ� ������ �������� ä���ֱ�
	for (int i = 2; i <= number; i++)
	{
		a[i] = i;
	}

	//�ռ������� �����, �ռ��� : 1�� �ڱ��ڽ� �̿��� ����� ������ 3�� �̻��� �ڿ���
	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0) //�̹� ������ ���� ����
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
			�Ʒ� for���� ������ ���� ���� ����� �ʱ�ȭ�ȴ�, �ߺ��� �Ҽ��� ��������� �ռ���
			��� ���� �� �� �ִ�
			�̹� ������ ���� �Ѿ��, �������� ���� ����(�Ҽ�)�� �������� ������� ã�Ƽ�
			�����ش�
		*/
		

		for (int j = i + i; j <= number; j += i)
		{
			a[j] = 0; // �ռ������� �����
		}
	}

	for (int i = 2; i <= number; i++)
	{
		if (a[i] != 0) //������ ������ �����ϰ� ���, �Ҽ����� ���
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