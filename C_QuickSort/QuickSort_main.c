// Quick Sort Ư���� ��(Pivot)�� �������� ū ���ڿ� ���� ���ڸ� ������

/*
������ ���ڵ��� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.


3 7 8 1 5 9 6 10 2 4


����ӵ�
O(N *logN)

�׷��� �ǹ����� ���� �־� �ð� ���⵵�� O(n^2) �� ���ü� �ִ�

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>


void printArr(int [], int);
void QuickSort(int*, int, int);
void swap(int* , int* );



int main(void)
{
	int arr[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	printArr(arr,sizeof(arr)/sizeof(arr[0]));
	
	QuickSort(arr,0,sizeof(arr) / sizeof(arr[0]) -1);

	printArr(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}


void printArr(int arr[],int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void QuickSort(int *data, int start, int end)
{
	if (start >= end) return;// data has only one element
	
	int key = start;// first element == key
	int i = start + 1;
	int j = end;

	while (i <= j) 
	{
		while (data[i] <= data[key])
		{
			i++;
		}
		while (data[j] >= data[key] && j > start)
		{
			j--;
		}
		if (i > j)
			swap(&data[j], &data[key]);
		else
			swap(&data[j], &data[i]);
	}
	QuickSort(data, start, j - 1);
	QuickSort(data, j + 1, end);

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}