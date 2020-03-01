// Merge Sort 일단 반으로 나누고 나중에 합쳐서 정렬한다.

/*
{ 7, 6, 5, 8, 3, 5, 9, 1, };


 67   58    35   19



  5678     1359


     13556789


위 과정을 보면 너비는 N 개, 높이는 3밖에 안된다, 
즉 높이는 2를 밑으로 하는 8의 로그 3이다 


수행속도
O(N *logN)


정확히 반으로 나누기 때문에, N*logN 을 확실히 보장한다




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



