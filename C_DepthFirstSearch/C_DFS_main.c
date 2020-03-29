#include <stdio.h>
#include <stdbool.h>

/*
Depth First Search( 깊이 우선 탐색 )
맹목적으로 각 vertex를 탐색할 때 주로 사용
더이상 탐색할 수 없을때까지 깊게 파고 들듯이 탐색함
stack 또는 재귀호출이 사용됨
*/

#define VERTEX_COUNT 8

int adj[VERTEX_COUNT][VERTEX_COUNT] =
{
	{0, 1, 1, 0, 0, 0, 0, 0}, //v0  : v1, v2
	{1, 0, 0, 1, 1, 0, 0, 0}, //v1  : v0, v3, v4
	{1, 0, 0, 0, 0, 1, 1, 0}, //v2  : v0, v5, v6
	{0, 1, 0, 0, 0, 0, 0, 1}, //v3  : v1, v7
	{0, 1, 0, 0, 0, 0, 0, 1}, //v4  : v1, v7
	{0, 0, 1, 0, 0, 0, 0, 1}, //v5  : v2, v7
	{0, 0, 1, 0, 0, 0, 0, 1}, //v6  : v2, v7
	{0, 0, 0, 1, 1, 1, 1, 0}  //v7  : v3, v4, v5, v6
};
bool visited[VERTEX_COUNT]; //방문기록

void DFS_Recursive(int _start)
{
	visited[_start] = true;  //방문
	printf("%d 방문\n", _start);
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		if (adj[_start][i] == 1 && !visited[i]) //인접했다 && 방문안했다 
		{
			DFS_Recursive(i); //재귀호출, 인접한 vertex를 인자로 대입
		}
	}
}


int main()
{
	DFS_Recursive(0);
	return 0;
}