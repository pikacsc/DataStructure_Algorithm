/*
Breadth First Search( 너비 우선 탐색 )
탐색을 할 때 너비를 우선으로 하여 탐색을 수행, 
Queue 가 사용됨
간선들의 가중치가 모두 동일할때 최단경로를 찾는데 사용할 수 있음
*/

#include <iostream>
#include <queue>

constexpr int VERTEX_COUNT = 8;
constexpr int adj[VERTEX_COUNT][VERTEX_COUNT] =
{
	{0, 1, 1, 1, 0, 0, 0, 0}, //v0  : v1, v2, v3
	{1, 0, 0, 0, 1, 0, 0, 0}, //v1  : v0, v4
	{1, 0, 0, 0, 0, 1, 1, 0}, //v2  : v0, v5, v6
 	{1, 0, 0, 0, 0, 0, 0, 1}, //v3  : v0, v7
	{0, 1, 0, 0, 0, 0, 0, 0}, //v4  : v1
	{0, 0, 1, 0, 0, 0, 0, 0}, //v5  : v2
	{0, 0, 1, 0, 0, 0, 0, 0}, //v6  : v2
	{0, 0, 0, 1, 0, 0, 0, 0}  //v7  : v3
};

bool visited[VERTEX_COUNT]; //방문기록

void BFS(int _start)
{
	std::queue<int> q;
	q.push(_start); //맨처음 시작 vertex 를 넣기
	visited[_start] = true; //시작 vertex 방문 처리 해주기
	while (!q.empty())
	{
		int y = q.front(); //queue 에서 front(가장 먼저 넣은 vertex) 꺼내기
		q.pop();
		printf("%d 방문\n", y);
		for (int x = 0; x < VERTEX_COUNT; x++)
		{
			//방금꺼낸 vertex 와 인접한 vertex들을 하나씩 가져오기
			if (adj[y][x] && !visited[x]) //인접한다 && 방문안했다
			{
				q.push(x);
				visited[x] = true; //방문처리
			}
		}
	}
}

int main()
{
	BFS(0);
	return 0;
}