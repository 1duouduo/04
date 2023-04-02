#include <iostream>
using namespace std;
//������ȱ�����DFS��
void DFS(int v, AGraph* G)
{
	visit[v] = 1;
	Visit(v);
	ArcNode* G= G->adjList[v].first;
	while (q = !NULL)
	{
		if (visit[q->adjV] == 0)
			DFS(q->adjV, G);
		q = q->next;
	}
}
//������ȱ�����BFS��
void BFS(AGraph* G, int v, int visit[maxSize])
{
	ArcNode* p;
	int que[maxSize], front = 0, rear = 0;
	int j;
	Visit(v);
	visit[v] = 1;
	rear = (rear + 1) % maxSize;
	que[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % maxSize;
		j = que[front];
		p = G->adjList[j].first;
		while (p != NULL)
		{
			if (visit[p->adjV] == 0)
			{
				Visit(p->adjV);
				visit[p->adjV] = 1;
				rear = (rear + 1) % maxSize;
				que[rear] = p->adjV;
			}
			p = p->next;
		}
	}
}
//��С����������prim�㷨
void Prim(int n, float MGraph[][n], int v0, float& sum)
{
	int lowCost[n], vSet[n];
	//lowcost[] �����㵽��һ��ĳ��ȣ�ĳһ���㵽����ĳ���Ϊ�����û��ֱ��һ���������������㳤��Ϊ�����
	int v, k, min;
	for (int i = 0; i < n; i++)
	{
		lowCost[i] = MGraph[v0][i];//MGraph[][] ͼ�Ĵ洢�ṹ
		vSet[i] = 0;
	}
	v = v0;//v0�����������������ʼ����
	vSet[v] = 1;
	sum = 0;
	//��������������Ҫ����
	for (int i = 0; i < n - 1; i++)
	{
		min = INF;//INF�������
		for (int j = 0; j < n; j++)
		{
			if (vSet[j] == 0 && lowCost[j] < min)
			{
				min = lowCost[j];
				k = j;
			}
			vSet[k] = 1;
			v = k;
			sum += min;
			for (int j = 0; j < n; j++)
				if (vSet[j] == 0 && MGraph[v][j] < lowCost[j])
					lowCost[j] = MGraph[v][j];
		}
	}
}
//Kruskal�㷨
int getRoot(int p)
{
	while (p != v[p])
		p = v[p];
	return p;
}
typedef struct
{
	int a, b;
	int w;
}Road;
Road road[maxSize];
void Kruskal(Road road[], int n, int e, int& sum)
{
	int a, b;
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		a = getRoot(road[i].a);
		b = getRoot(raod[i].b);
		if (a != b)
		{
			v[a] = b;
			sum += road[i].w;

		}
	}
}
//Dijkstra�㷨
void Dijktra(int n, float MGraph[][n], int v0, int dist[], int path[])
{
	int set[maxSize];
	int min, v;
	for (int i = 0; i < n; i++)
	{
		dist[i] = MGraph[v0][i];
		set[i] = 0;
		if (MGraph[v0][i] < INF)
			path[i] = v0;
		else
			path[i] = -1;
	}
	set[v0] = 1;
	path[v0] = -1;
	for (int i = 0; i < n - 1; i++)
	{
		min = INF;
		for (int j = 0; j < n; i++)
		{
			if (set[j] == 0 && dist[j] < min)
			{
				v = j;
				min = dist[j];
			}

		}
		set[v] = 1;
		for (int j = 0; j < n; j++)
		{
			if (set[j] == 0 && dist[v] + MGraph[v][j] < dist[j])
			{
				dist[j] = dist[v] + MGraph[v][j];
				path[j] = v;
			}
		}
	}
}
//Floyd �㷨
void Floyd(int n, float MGraph[][n], int Path[][n])
{
	int i, j, v;
	int A[n][n];
	for (i= 0; j < n; i++)
		for (j = 0; j < n; j++)
		{
			A[i][j] = MGraph[i][j];
			Path[i][j] = -1;
		}
	for (v = 0; v < n; v++)
		for(j = 0; j < n; i++)
			for(j = 0; j <n ;j++)
				if (A[i][j] > A[i][v] + A[v][j])
				{
					A[i][j] = A[i][v] + A[v][j];
					Path[i][j] = v;
				}
}
//��������
int TopSort(AGraph* G)
{
	int i, j, n = 0;
	int stack[maxSize], top = -1;
	ArcNode* p;
	for (i = 0; i < G->n; i++)
	{
		if (G->adjList[i].count == 0)
			stack[++top] = i;
	}
	while (top != -1)
	{
		i = stack[top--];
		n++;
		cout << i << " ";
		p = G->adjList[i].first;
		while (p != NULL)
		{
			j = p->adjV;
			(G->adjList[j].count)--;
			if (G->adjList[j].count == 0)
				stack[++top] = j;
			p = p->next;
		}

	}
	if (n == G->n)
		return 1;
	else
		return 0;

}
//����������
void DFS(int v, AGraph* G)
{
	visit[v] = 1;
	ArcNode* q = G->adjList[v].first;
	while (q != NULL)
	{
		if (visit[q->adjV] == 0)
			DFS(q->adjV, G);
		q = q->next;
	}
	Visit(v);
}
int main()
{

}