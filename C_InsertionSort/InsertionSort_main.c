// Insertion Sort �� ��Ҹ� ������ ��ġ�� �����Ѵ�

/*
������ ���ڵ��� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1, 10, 5, 8, 7, 6, 4, 3, 2, 9

_ 1 _ 10, 5, 8, 7, 6, 4, 3, 2, 9 => 10 �� �� ��ġ ����, ���ڸ� j++

_ 1 _ 10 _ 5, 8, 7, 6, 4, 3, 2, 9 => 5 �� �� ��ġ ����, 10 ���� ����

_ 1 _ 5 _ 10 _ 8, 7, 6, 4, 3, 2, 9 => 8 �� �� ��ġ ����, 10 ���� ����

_ 1 _ 5 _ 8 _ 10 _ 7, 6, 4, 3, 2, 9 => 7 �� �� ��ġ ����, 8 ���� ����
...

1, 2, 3, 4, 5, 6, 7, 8, 9, 10

����ð�
���� ���ĵ� ���¶��, ���ľ˰��� �� ���� ������

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void printArr(int arr[]);
void InsertionSort(int []);

int main(void)
{
	int arr[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	
	printArr(arr);
	InsertionSort(arr);
	printf("\n");
	printArr(arr);
	return 0;
}


void InsertionSort(int arr[])
{
	int i, j, temp;
	for (i = 0; i < 9; i++)
	{
		j = i;
		if (j >= 9) break;
		while (arr[j] > arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j+i];
			arr[j + i] = temp;
			j--;
		}
	}
}

void printArr(int arr[])
{
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}