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
		j ���� �Ʒ��� ���� * 2 �Ǵ� ���� ����

		i + i == 2 + 2 == i x 2 == 2 x 2
		i + i == 3 + 3 == i x 2 == 3 x 2
		i + i == 4 + 4 == i x 2 == 4 x 2
		��
		�Ҽ��� 1�� �ڱ� �ڽ��̿ܿ� ������ �������� ���� �����Ƿ�
		2 x 2, 3 x 2, 4 x 2 ��� j �� �ش��ϴ� ������ �ռ����� �ȴ�
		���� j �� �ش��ϴ� �� ���� �� ���������� ���� ������ �Ҽ��� �ȴ�
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