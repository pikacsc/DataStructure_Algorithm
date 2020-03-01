// Quick Sort Ư���� ��(Pivot)�� �������� ū ���ڿ� ���� ���ڸ� ������

/*
������ ���ڵ��� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.


3 7 8 1 5 9 6 10 2 4


����ӵ�
O(N *logN)

�׷��� �ǹ����� ���� �־� �ð� ���⵵�� O(n^2) �� ���ü� �ִ�

*/

#include <iostream>

void QuickSort(int* arr, int size);
void printArr(int* arr, int size);

void swap(int* a, int* b);

int main()
{
	int arr[] = { 3, 7, 8, 1, 5, 9, 6, 10, 2, 4 };
	int size = sizeof(arr) / sizeof(int);
	printArr(arr, size);
	QuickSort(arr, size);
}

void QuickSort(int* arr, int size)
{
	int pivot_i = 0;
	int pivot = arr[pivot_i];
	int start = 0;
	int end = size - 1;
	int l = pivot_i + 1;
	int r = end;

	while (pivot_i < size)
	{
		while (l < r)
		{
			while (arr[l] < pivot && l != r)
				l++;
			while (arr[r] > pivot && l != r)
				r--;
			if(l != r)
				swap(&arr[l], &arr[r]);
		}
		if (l == r)
		{
			if (pivot >= arr[l])
			{
				swap(&arr[pivot_i], &arr[l - 1]);
				pivot_i = 0;
				r = l - 1;
				l = pivot_i + 1;
			}
			else
			{
				pivot_i++;
				pivot = arr[pivot_i];
				l = pivot_i + 1;
				r = end;
			}
				
		}
	}

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}