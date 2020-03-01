// Quick Sort 특정한 값(Pivot)을 기준으로 큰 숫자와 작은 숫자를 나눈다

/*
다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하시오.


3 7 8 1 5 9 6 10 2 4


수행속도
O(N *logN)

그러나 피벗값에 따라서 최악 시간 복잡도로 O(n^2) 이 나올수 있다

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