// Insertion Sort 각 요소를 적절한 위치에 삽입한다

/*
다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하시오.

1, 10, 5, 8, 7, 6, 4, 3, 2, 9

_ 1 _ 10, 5, 8, 7, 6, 4, 3, 2, 9 => 10 이 들어갈 위치 선정, 제자리 j++

_ 1 _ 10 _ 5, 8, 7, 6, 4, 3, 2, 9 => 5 이 들어갈 위치 선정, 10 왼쪽 으로

_ 1 _ 5 _ 10 _ 8, 7, 6, 4, 3, 2, 9 => 8 이 들어갈 위치 선정, 10 왼쪽 으로

_ 1 _ 5 _ 8 _ 10 _ 7, 6, 4, 3, 2, 9 => 7 이 들어갈 위치 선정, 8 왼쪽 으로
...

1, 2, 3, 4, 5, 6, 7, 8, 9, 10

수행시간
거의 정렬된 상태라면, 정렬알고리즘 중 제일 빠르다

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