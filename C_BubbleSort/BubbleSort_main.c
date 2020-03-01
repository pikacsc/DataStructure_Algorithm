// BubbleSort 옆에 있는 값과 비교해서 더 작은 값을 앞으로 보낸다

/*
다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하시오.


1, 10, 5, 8, 7, 6, 4, 3, 2, 9

1, 10, 5, 8, 7, 6, 4, 3, 2, 9 => 1 < 10 => no move

1, 10, 5, 8, 7, 6, 4, 3, 2, 9 => 10 > 5 => 5 move to 10 position

1, 5, 10, 8, 7, 6, 4, 3, 2, 9 => 10 > 8 => 8 move to 10 position

1, 5, 8, 10, 7, 6, 4, 3, 2, 9 => 10 > 8 => 8 move to 10 position
...

1, 5, 8, 7, 6, 4, 3, 2, 9, 10 => after one cycle, most right value is high

수행시간
n*(n+1) / 2
O(n*n)
SelectionSort와 같지만, 실제로는 BubbleSort가 더 느리다
Sort 중에서 가장 느리다

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void printArr(int arr[]);

int main(void)
{
	int arr[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	printArr(arr);

	////MySolution
	//for (int j = 0; j < 9; j++)
	//{
	//	for (int i = 0; i < 9; i++)
	//	{
	//		if (arr[i] > arr[i + 1])
	//		{
	//			//Swap
	//			int temp = arr[i];
	//			arr[i] = arr[i + 1];
	//			arr[i + 1] = temp;
	//		}
	//	}
	//}

	int i, j, temp;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	


	printf("\n after sort \n");
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