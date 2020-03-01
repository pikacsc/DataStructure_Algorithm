// Quick Sort 특정한 값(Pivot)을 기준으로 큰 숫자와 작은 숫자를 나눈다

/*
다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하시오.


3 7 8 1 5 9 6 10 2 4


수행속도
O(N *logN)

그러나 피벗값에 따라서 최악 시간 복잡도로 O(n^2) 이 나올수 있다

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