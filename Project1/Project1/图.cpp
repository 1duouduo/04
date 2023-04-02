#include <iostream>
using namespace std;
//深度优先遍历（DFS）
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
//广度优先遍历（BFS）
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
//最小代价生成树prim算法
void Prim(int n, float MGraph[][n], int v0, float& sum)
{
	int lowCost[n], vSet[n];
	//lowcost[] ，顶点到另一点的长度，某一顶点到自身的长度为无穷大，没有直接一条边相连的两顶点长度为无穷大
	int v, k, min;
	for (int i = 0; i < n; i++)
	{
		lowCost[i] = MGraph[v0][i];//MGraph[][] 图的存储结构
		vSet[i] = 0;
	}
	v = v0;//v0，构造的生成树的起始顶点
	vSet[v] = 1;
	sum = 0;
	//构建生成树的主要过程
	for (int i = 0; i < n - 1; i++)
	{
		min = INF;//INF：无穷大
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
//Kruskal算法
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
//Dijkstra算法
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
//Floyd 算法
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
//拓扑排序
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
//逆拓扑排序
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