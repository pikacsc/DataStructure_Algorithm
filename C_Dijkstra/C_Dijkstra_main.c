/*
다익스트라 알고리즘

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 1000 //무한, 인접해있지 않은 경우 무한으로 처리, 
//여기서는 가중치를 다 더해서 나올수 없는 큰수 1000으로 하였음

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
//지하철 노선도
#define VERTEX_COUNT 13
int adj[VERTEX_COUNT][VERTEX_COUNT] =
{
	{INF, 9, INF, 8, INF, INF, 6, 10, INF, INF, INF, INF, INF},      // 0. 종로3가 : 종로5가, 종각, 을지로3가, 을지로4가
	{9, INF, 8, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},   // 1. 종로5가 : 종로3가, 동대문
	{INF, 8, INF, INF, INF, INF, INF, INF, 7, INF, INF, INF, INF},   // 2. 동대문 : 종로5가, 동대문역사문화공원
	{8, INF, INF, INF, 10, INF, INF, INF, INF, INF, INF, INF, INF},  // 3. 종각 : 종로3가, 시청
	{INF, INF, INF, 10, INF, 7, INF,  INF, INF, 11, INF, INF, INF},  // 4. 시청 : 종각, 을지로 입구, 서울역 
	{INF, INF, INF, INF, 7, INF, 8,  INF, INF, INF, INF, INF, INF},  // 5. 을지로입구 : 시청, 을지로3가
	{6, INF, INF, INF, INF, 8, INF,  6, INF, INF, INF, INF, 7},      // 6. 을지로3가 : 종로3가, 을지로입구, 을지로4가, 충무로
	{10, INF, INF, INF, INF, INF, 6, INF, 10, INF, INF, INF, INF},   // 7. 을지로4가 : 종로3가, 을지로3가, 동대문역사문화공원
	{INF, INF, 7, INF, INF, INF, INF, 10, INF, INF, INF, INF, 13},   // 8. 동대문역사문화공원 : 동대문, 을지로4가, 충무로
	{INF, INF, INF, INF, 11, INF, INF,  INF, INF, INF, 9, INF, INF}, // 9. 서울역 : 시청, 회현
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, 9, INF, 7, INF},   // 10. 회현 : 서울역, 명동
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 7, INF, 7},   // 11. 명동 : 회현, 충무로
	{INF, INF, INF, INF, INF, INF, 7, INF, 13, INF, INF, 7, INF}     // 12. 충무로 : 을지로3가, 동대문역사문화공원, 명동
};

enum eStation
{
	종로3가,
	종로5가,
	동대문,
	종각,
	시청,
	을지로입구,
	을지로3가,
	을지로4가,
	동대문역사문화공원,
	서울역,
	회현,
	명동,
	충무로
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
	bool visited[VERTEX_COUNT] = { 0 }; //방문기록
	int distance[VERTEX_COUNT]; //시작점에서 각정점까지의 최소 가중치(최단거리) 기록
	ROUTEPAIR routePairs[VERTEX_COUNT] = { 0 };
	
	//최소가중치 기록 배열 초기화
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		distance[i] = INF;
	}
	//distance[_startV] = 0;

	//주변 정점들과의 최소 가중치 기록하기
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

		for (int i = 0; i < VERTEX_COUNT; i++) //방문하지 않고, 최소 가중치 기록중 제일 낮은 가중치를 가지는 정점 찾기
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
		
		//기준 정점 초기화 및 방문 처리
		curretV = minIdx; 
		visited[curretV] = true;

		//방문한 정점을 기준으로 최소 가중치 배열 수정
		for (int i = 0; i < VERTEX_COUNT; i++)
		{
			if (!visited[i])
			{
				if (distance[curretV] + adj[curretV][i] < distance[i]) //이전경로 가중치 + 인접경로(새경로) 가중치
				{
					//경로 저장
					routePairs[curretV].ChildV = i;
					routePairs[i].ParentV = curretV;
				
					distance[i] = distance[curretV] + adj[curretV][i]; // 더 빠른 경우 초기화
				}
			}
		}
	
	}

	//반드시 adj 0번째 배열을 _start로 해야 아래로직이 무한루프 돌지 않고 잘동작함
	//_start 가 adj[0] 이 아닐 경우, 무한루프

	//경로 보기
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
			printf("%s 시작\n", vertexToStationName(routeStack[i]));
		}
		else if (i == 0)
		{
			printf("%s 도착\n", vertexToStationName(routeStack[i]));
		}
		else
		{
			printf("%s 방문\n", vertexToStationName(routeStack[i]));
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
	case 종로3가:
		return "종로3가";
	case 종로5가:
		return "종로5가";
	case 동대문:
		return "동대문";
	case 종각:
		return "종각";
	case 시청:
		return "시청";
	case 을지로입구:
		return "을지로입구";
	case 을지로3가:
		return "을지로3가";
	case 을지로4가:
		return "을지로4가";
	case 동대문역사문화공원:
		return "동대문역사문화공원";
	case 서울역:
		return "서울역";
	case 회현:
		return "회현";
	case 명동:
		return "명동";
	case 충무로:
		return "충무로";
	default:
		return "없음";
	}
}


int main()
{
	Dijkstra(종로3가, 동대문역사문화공원);
	
	return 0;
}