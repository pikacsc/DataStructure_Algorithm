/*
���ͽ�Ʈ�� �˰���

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 1000 //����, ���������� ���� ��� �������� ó��, 
//���⼭�� ����ġ�� �� ���ؼ� ���ü� ���� ū�� 1000���� �Ͽ���

//example 1
//#define VERTEX_COUNT 7
//int adj[VERTEX_COUNT][VERTEX_COUNT] =
//{
//	{INF, 5, 10, 9, INF, INF, INF},  // A : B, C, D
//	{5, INF, 3, INF, INF, 11, INF},  // B : A, C, F
//	{10, 3, INF, 7, 3, 10, INF},     // C : A, B, D, E, F
//	{9, INF, 7, INF, INF,7, 12},     // D : A, C, F, G
//	{INF, INF, 3, INF, INF, 4, INF}, // E : C, F 
//	{INF, 11, 10, 7, 4, INF, 2},     // F : B, C, D, E, G
//	{INF, INF, INF, 12, INF, 2, INF} // G : D, F
//};


//example 2 
//����ö �뼱��
#define VERTEX_COUNT 13
int adj[VERTEX_COUNT][VERTEX_COUNT] =
{
	{INF, 9, INF, 8, INF, INF, 6, 10, INF, INF, INF, INF, INF},      // 0. ����3�� : ����5��, ����, ������3��, ������4��
	{9, INF, 8, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},   // 1. ����5�� : ����3��, ���빮
	{INF, 8, INF, INF, INF, INF, INF, INF, 7, INF, INF, INF, INF},   // 2. ���빮 : ����5��, ���빮���繮ȭ����
	{8, INF, INF, INF, 10, INF, INF, INF, INF, INF, INF, INF, INF},  // 3. ���� : ����3��, ��û
	{INF, INF, INF, 10, INF, 7, INF,  INF, INF, 11, INF, INF, INF},  // 4. ��û : ����, ������ �Ա�, ���￪ 
	{INF, INF, INF, INF, 7, INF, 8,  INF, INF, INF, INF, INF, INF},  // 5. �������Ա� : ��û, ������3��
	{6, INF, INF, INF, INF, 8, INF,  6, INF, INF, INF, INF, 7},      // 6. ������3�� : ����3��, �������Ա�, ������4��, �湫��
	{10, INF, INF, INF, INF, INF, 6, INF, 10, INF, INF, INF, INF},   // 7. ������4�� : ����3��, ������3��, ���빮���繮ȭ����
	{INF, INF, 7, INF, INF, INF, INF, 10, INF, INF, INF, INF, 13},   // 8. ���빮���繮ȭ���� : ���빮, ������4��, �湫��
	{INF, INF, INF, INF, 11, INF, INF,  INF, INF, INF, 9, INF, INF}, // 9. ���￪ : ��û, ȸ��
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, 9, INF, 7, INF},   // 10. ȸ�� : ���￪, ��
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF, 7},   // 11. �� : ȸ��, �湫��
	{INF, INF, INF, INF, INF, INF, 7, INF, 13, INF, INF, 7, INF}     // 12. �湫�� : ������3��, ���빮���繮ȭ����, ��
};

enum eStation
{
	����3��,
	����5��,
	���빮,
	����,
	��û,
	�������Ա�,
	������3��,
	������4��,
	���빮���繮ȭ����,
	���￪,
	ȸ��,
	��,
	�湫��
};


char vertexIndexToChar(int _vertexIndex);

char* vertexToStationName(int _vertexIndex);


typedef struct _tagRoutePair
{
	int ParentV;
	int ChildV;
} ROUTEPAIR;

void Dijkstra(int _startV, int _endV)
{
	bool visited[VERTEX_COUNT] = { 0 }; //�湮���
	int distance[VERTEX_COUNT]; //���������� ������������ �ּ� ����ġ(�ִܰŸ�) ���
	ROUTEPAIR routePairs[VERTEX_COUNT] = { 0 };
	
	//�ּҰ���ġ ��� �迭 �ʱ�ȭ
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		distance[i] = INF;
	}
	//distance[_startV] = 0;

	//�ֺ� ��������� �ּ� ����ġ ����ϱ�
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		if (adj[_startV][i] != INF)
		{
			distance[i] = adj[_startV][i];
		}
	}
	visited[_startV] = true;
	routePairs[_startV].ParentV = _startV;

	int curretV = _startV; 
	for(int i = 0; i < VERTEX_COUNT - 1; i++)
	{
		int min = INF;
		int minIdx = curretV;

		for (int i = 0; i < VERTEX_COUNT; i++) //�湮���� �ʰ�, �ּ� ����ġ ����� ���� ���� ����ġ�� ������ ���� ã��
		{
			if (!visited[i]) 
			{
				if (min > distance[i])
				{
					min = distance[i];
					minIdx = i; 
				}
			}
		}
		
		//���� ���� �ʱ�ȭ �� �湮 ó��
		curretV = minIdx; 
		visited[curretV] = true;

		//�湮�� ������ �������� �ּ� ����ġ �迭 ����
		for (int i = 0; i < VERTEX_COUNT; i++)
		{
			if (!visited[i])
			{
				if (distance[curretV] + adj[curretV][i] < distance[i]) //������� ����ġ + �������(�����) ����ġ
				{
					//��� ����
					routePairs[curretV].ChildV = i;
					routePairs[i].ParentV = curretV;
				
					distance[i] = distance[curretV] + adj[curretV][i]; // �� ���� ��� �ʱ�ȭ
				}
			}
		}
	
	}

	//�ݵ�� adj 0��° �迭�� _start�� �ؾ� �Ʒ������� ���ѷ��� ���� �ʰ� �ߵ�����
	//_start �� adj[0] �� �ƴ� ���, ���ѷ���

	//��� ����
	int routeStack[VERTEX_COUNT] = { 0 };
	int RoutesCount = 0;
	routeStack[RoutesCount++] = _endV;
	int now = _endV;
	while(1)
	{
		if (routePairs[now].ParentV == _startV)
		{
			routeStack[RoutesCount++] = _startV;
			break;
		}
		now = routePairs[now].ParentV;
		routeStack[RoutesCount++] = now;
	}

	for (int i = RoutesCount - 1; i >= 0; i--)
	{
		
		if (i == RoutesCount - 1)
		{
			printf("%s ����\n", vertexToStationName(routeStack[i]));
		}
		else if (i == 0)
		{
			printf("%s ����\n", vertexToStationName(routeStack[i]));
		}
		else
		{
			printf("%s �湮\n", vertexToStationName(routeStack[i]));
		}
	}

}

char vertexIndexToChar(int _vertexIndex)
{
	return (char)_vertexIndex + 65;
}

char* vertexToStationName(int _vertexIndex)
{
	enum eStation e = _vertexIndex;
	switch (e)
	{
	case ����3��:
		return "����3��";
	case ����5��:
		return "����5��";
	case ���빮:
		return "���빮";
	case ����:
		return "����";
	case ��û:
		return "��û";
	case �������Ա�:
		return "�������Ա�";
	case ������3��:
		return "������3��";
	case ������4��:
		return "������4��";
	case ���빮���繮ȭ����:
		return "���빮���繮ȭ����";
	case ���￪:
		return "���￪";
	case ȸ��:
		return "ȸ��";
	case ��:
		return "��";
	case �湫��:
		return "�湫��";
	default:
		return "����";
	}
}


int main()
{
	Dijkstra(����3��, ���빮���繮ȭ����);
	
	return 0;
}