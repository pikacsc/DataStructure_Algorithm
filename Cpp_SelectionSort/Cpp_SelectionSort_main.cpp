/*

SelectionSort(선택정렬) : 제일 작은 수를 맨 앞으로 보낸다

수행시간
== O(N^2)
== N * (N + 1) / 2
*/

#include <iostream>

void SelectionSort(int* arr, int size);
void printArr(int* arr, int size);

int main(void)
{
	int arr[] = { 4,5,3,1,2,6,10,9,8,7 };
	int size = sizeof(arr) / sizeof(int);
	printArr(arr, size);
	SelectionSort(arr, size);
	printArr(arr, size);

	return 0;
}


//move from min value position to first position
void SelectionSort(int* arr, int size)
{
	int min = 0;
	int temp = 0;
	int min_i = 0;

	for (int i = 0; i < size; i++) //1.first for loop, pointing first position
	{
		min = INT32_MAX; //2. to get min value, assign max value,
		for (int j = i; j < size; j++) //3. second for loop, pointing element to find min value in array
		{
			if (arr[j] < min) //3-1. compare each element with min value, true: min value change
			{
				min = arr[j];
				min_i = j;
			}
		}

		//4. change position from min value position to first position
		temp = arr[min_i];
		arr[min_i] = arr[i];
		arr[i] = temp;
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
