/*
Breadth First Search( �ʺ� �켱 Ž�� )
Ž���� �� �� �ʺ� �켱���� �Ͽ� Ž���� ����, 
Queue �� ����
�������� ����ġ�� ��� �����Ҷ� �ִܰ�θ� ã�µ� ����� �� ����
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

bool visited[VERTEX_COUNT]; //�湮���

void BFS(int _start)
{
	std::queue<int> q;
	q.push(_start); //��ó�� ���� vertex �� �ֱ�
	visited[_start] = true; //���� vertex �湮 ó�� ���ֱ�
	while (!q.empty())
	{
		int y = q.front(); //queue ���� front(���� ���� ���� vertex) ������
		q.pop();
		printf("%d �湮\n", y);
		for (int x = 0; x < VERTEX_COUNT; x++)
		{
			//��ݲ��� vertex �� ������ vertex���� �ϳ��� ��������
			if (adj[y][x] && !visited[x]) //�����Ѵ� && �湮���ߴ�
			{
				q.push(x);
				visited[x] = true; //�湮ó��
			}
		}
	}
}

int main()
{
	BFS(0);
	return 0;
}