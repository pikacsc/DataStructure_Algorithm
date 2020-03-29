#include <stdio.h>
#include <stdbool.h>

/*
Depth First Search( ���� �켱 Ž�� )
�͸������� �� vertex�� Ž���� �� �ַ� ���
���̻� Ž���� �� ���������� ��� �İ� ����� Ž����
stack �Ǵ� ���ȣ���� ����
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
bool visited[VERTEX_COUNT]; //�湮���

void DFS_Recursive(int _start)
{
	visited[_start] = true;  //�湮
	printf("%d �湮\n", _start);
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		if (adj[_start][i] == 1 && !visited[i]) //�����ߴ� && �湮���ߴ� 
		{
			DFS_Recursive(i); //���ȣ��, ������ vertex�� ���ڷ� ����
		}
	}
}


int main()
{
	DFS_Recursive(0);
	return 0;
}