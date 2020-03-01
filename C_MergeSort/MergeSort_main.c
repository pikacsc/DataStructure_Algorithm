// Merge Sort �ϴ� ������ ������ ���߿� ���ļ� �����Ѵ�.

/*
{ 7, 6, 5, 8, 3, 5, 9, 1, };


 67   58    35   19



  5678     1359


     13556789


�� ������ ���� �ʺ�� N ��, ���̴� 3�ۿ� �ȵȴ�, 
�� ���̴� 2�� ������ �ϴ� 8�� �α� 3�̴� 


����ӵ�
O(N *logN)


��Ȯ�� ������ ������ ������, N*logN �� Ȯ���� �����Ѵ�




*/
#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

void printArr(int* arr, int size);


int main()
{
	int array[8] = { 7, 6, 5, 8, 3, 9, 1, };
	int size = sizeof(array) / sizeof(int);
	printArr(array, size);
	printf("\nAfter Merge Sorting\n");
	merge_sort(array, 0, size -1);
    printArr(array, size);

	return 0;
}

void printArr(int* arr, int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



