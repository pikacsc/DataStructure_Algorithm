#include <iostream>

int number = 4;
int INF = 100000000;

// �ڷ� �迭�� �ʱ�ȭ
int a[4][4] =
{
	{0, 5, INF, 8},
	{7, 0,	9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};


void floydWarshall()
{
	int oldCost = 0;
	int newCost = 0;
	
	// ��� �׷����� �ʱ�ȭ
	//X���� Y�ΰ��� �ּҺ�� VS X���� '���İ��³��'�� ���� ��� + ���1 ���� Y�� ���� ���
	for (int stopover = 0; stopover < number; stopover++) //stopover : ������, ���İ��� ���
	{
		for (int start = 0; start < number; start++)
		{
			for (int goal = 0; goal < number; goal++)
			{
				if (stopover < number&& start != goal && start != stopover && goal != stopover)
				{
					oldCost = a[start][goal]; //X���� Y�ΰ��� �ּҺ��

					//X���� '���İ��³��'�� ���� ��� + ���1 ���� Y�� ���� ���
					newCost = a[start][stopover] + a[stopover][goal]; 
					
					//���߿� �� ���� ����� �ֱ�
					a[start][goal] = oldCost > newCost ? newCost : oldCost; 
				}
			}
		}
	}
}

void PrintGraph(int (*_a)[4])
{
	for (int start = 0; start < number; start++)
	{
		for (int goal = 0; goal < number; goal++)
		{
			if (a[start][goal] == INF)
			{
				printf("INF ");
			}
			else
			{
				printf("%d ", a[start][goal]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

int main()
{
	PrintGraph(a);

	floydWarshall();
	printf("after FloydWarshall \n");
	PrintGraph(a);
	
	return 0;
}