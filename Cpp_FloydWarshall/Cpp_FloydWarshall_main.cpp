#include <iostream>

int number = 4;
int INF = 100000000;

// 자료 배열을 초기화
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
	
	// 결과 그래프를 초기화
	//X에서 Y로가는 최소비용 VS X에서 '거쳐가는노드'로 가는 비용 + 노드1 에서 Y로 가는 비용
	for (int stopover = 0; stopover < number; stopover++) //stopover : 경유지, 거쳐가는 노드
	{
		for (int start = 0; start < number; start++)
		{
			for (int goal = 0; goal < number; goal++)
			{
				if (stopover < number&& start != goal && start != stopover && goal != stopover)
				{
					oldCost = a[start][goal]; //X에서 Y로가는 최소비용

					//X에서 '거쳐가는노드'로 가는 비용 + 노드1 에서 Y로 가는 비용
					newCost = a[start][stopover] + a[stopover][goal]; 
					
					//둘중에 더 적은 비용을 넣기
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