// BubbleSort ���� �ִ� ���� ���ؼ� �� ���� ���� ������ ������

/*
������ ���ڵ��� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.


1, 10, 5, 8, 7, 6, 4, 3, 2, 9

1, 10, 5, 8, 7, 6, 4, 3, 2, 9 => 1 < 10 => no move

1, 10, 5, 8, 7, 6, 4, 3, 2, 9 => 10 > 5 => 5 move to 10 position

1, 5, 10, 8, 7, 6, 4, 3, 2, 9 => 10 > 8 => 8 move to 10 position

1, 5, 8, 10, 7, 6, 4, 3, 2, 9 => 10 > 8 => 8 move to 10 position
...

1, 5, 8, 7, 6, 4, 3, 2, 9, 10 => after one cycle, most right value is high

����ð�
n*(n+1) / 2
O(n*n)
SelectionSort�� ������, �����δ� BubbleSort�� �� ������
Sort �߿��� ���� ������

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