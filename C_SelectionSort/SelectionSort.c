/*
다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하시오.


1, 10, 5, 8, 7, 6, 4, 3, 2, 9

Selection Sort(가장 작은것을 선택해서 제일 앞으로 보낸다)

1, 10, 5, 8, 7, 6, 4, 3, 2, 9

1, 2, 5, 8, 7, 6, 4, 3, 10, 9

1, 2, 3, 8, 7, 6, 4, 5, 10, 9

1, 2, 3, 4, 7, 6, 8, 5, 10, 9

1, 2, 3, 4, 5, 6, 8, 7, 10, 9

...

1, 2, 3, 4, 5, 6, 7, 8, 9, 10

수행시간 
== O(N^2)
== N * (N + 1) / 2
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>


void printArr(int arr[]);

int main(void)
{
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	printArr(arr);
	
	//DongBinNa Solution
	int min = 0;
	int temp = 0;
	int index = 0;
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		min = 9999;
		for (j = i; j < 10; j++)
		{
			if (min > arr[j]) 
			{
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}


	printf("\n after sort");

	printArr(arr);


	return 0;
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