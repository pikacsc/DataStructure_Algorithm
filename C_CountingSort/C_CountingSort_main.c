/*
������� (Counting Sort) - ũ�⸦ �������� ������ ����

������ 5���� �ڿ��� �����͵��� �������� ���� �ϼ���
1 3 2 4 3 2 5 3 1 2 3 4 4 3 5 1 2 3 5 2 3 1 4 3 5 1 2 1 1 1

���� ������ �ִ� ��쿡 ���ؼ� ������ ���� �˰����̴�
�ð� ���⵵�� O(N) �̴�

*/

#include <stdio.h>
#include <stdlib.h>

void CountingSort(int _start, int _limit, int _length, int* arr);

int main()
{
	int arr[] = { 2, 3, 2, 4, 3, 2, 5, 3, 2, 2, 3, 4, 4, 3, 5, 2, 2, 3, 5, 2, 3, 2, 4, 3, 5, 2, 2, 2, 2, 2 };

	int length = sizeof(arr) / sizeof(int);


	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\n After Counting Sort \n\n");
	CountingSort(2, 5, length, arr);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n\nDong Bin Na's Code\n");

	//GuideCode
	int count[5];
	
	for (int i = 0; i < 5; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < 30; i++ )
	{
		count[arr[i] - 1]++;
	}

	for (int i = 0; i < 5; i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				printf("%d ", i + 1);
			}
		}
	}

	return 0;
}


void CountingSort(int _start, int _limit, int _length, int* _arr)
{
	int* count = (int*)calloc((_limit - _start) + 1, sizeof(int));
	
	for (int i = 0; i < _length; i++)
	{
		count[_arr[i] - _start]++;
	}

	for (int i = 0, j = _start; i < _length; i++)
	{
		if (count[j - _start] != 0)
		{
			_arr[i] = j;
			
		}
		else
		{
			_arr[i] = ++j;
		}
		count[j - _start]--;
	}


	free(count);
}