#include "MergeSort.h"


static int sg_sorted[8];


static int IntHalf(int source);

void merge(int* list, int left, int mid, int right)
{
	int i = 0; //정렬된 왼쪽 리스트에 대한 인덱스
	int j = 0; //정렬된 오른쪽 리스트에 대한 인덱스
	int k = 0; // 정렬될 리스트에 대한 인덱스
	int l = 0;

	i = left;
	j = mid + 1;
	k = left;


	//분할 정렬된 list의 합병
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			sg_sorted[k++] = list[i++];
		}
		else
		{
			sg_sorted[k++] = list[j++];
		}
	}

	//남아 있는 값들을 일괄 복사
	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			sg_sorted[k++] = list[l];
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			sg_sorted[k++] = list[l];
		}
	}

	//원본배열에 정렬된 배열값들을 복사
	for (l = left; l <= right; l++)
	{
		list[l] = sg_sorted[l];
	}

}

void merge_sort(int* list, int left, int right)
{
	int mid = 0;
	
	if (left < right)
	{
		mid = IntHalf(left + right);
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}



static int IntHalf(int source)
{
	return (int)(source * 0.5);
}