#include<stdio.h>
#include<iostream>
using namespace std;

# define MAXVEX 100             //图中最大顶点个数
# define INF 32767

typedef char VertexType [10];  //定义VertexType为字符串类型
typedef struct vertex {
	int adjvex;                //顶点编号
	VertexType data;            //顶点的信息
} VType;
typedef struct graph {
	int n, e;                    //n为实际顶点数，e为实际边数
	VType vexs [MAXVEX];          //顶点集合
	int edges [MAXVEX][MAXVEX];    //边的集合
} MatGraph;                      //图的邻接矩阵类型


void CreateGraph(MatGraph&g, int A[][MAXVEX], int n, int e) {
	int i, j;                  //建立图的邻接矩阵
	g.n = n;
	g.e = e;
	for (i = 0; i < n; i++)
		for (j = 0 ; j < n; j++)
			g.edges[i][j] = A[i][j];
}

void DestroyGraph(MatGraph g) {}   //毁图

void DispGraph( MatGraph g) {      //输出图
	int i, j;
	for (i = 0 ; i < g. n; i++) {
		for (j = 0 ; j < g. n; j++)
			if (g.edges[i][j] < INF)
				printf("%4d", g.edges[i][j]);
		else
			printf("%4s", "oo");
		printf("\n");
	}
}

int Degree1(MatGraph g, int v) { //求无向图顶点度
	int i, d = 0;
	if (v < 0 || v >= g.n)
		return -1;
	for (i = 0; i < g.n; i++)
		if (g.edges[v][i] > 0 && g.edges[v][i] < INF)
			d++;
	return d;
}

int Degree2(MatGraph g, int v) {  //求有向图顶点度
	int i, dl = 0, d2 = 0, d;
	if (v < 0 || v >= g. n)
		return -1;
	for (i = 0; i < g. n; i++ )
		if (g. edges[v] [i] > 0 && g. edges[v] [i] < INF)
			dl++ ;
	for (i = 0; i < g.n; i++)
		if (g.edges[i][v] > 0 && g.edges[i][v] < INF)
			d2++ ;
	d = dl + d2;
	return d;
}

void DFS1(MatGraph g, int v) {   //邻接矩阵的 DFS 算法
	static int visited[MAXVEX] = {0};
	int w;
	printf("%d ", v);
	visited[v] = 1;
	for (w = 0; w < g.n; w++)
		if (g.edges[v][w] != 0 && g.edges[v][w] != INF
			&& visited[w] == 0)
			DFS1(g, w);
}

void BFS1 (MatGraph g, int v) {
	int i, w, visited[MAXVEX];
	int Qu [MAXVEX], front = 0, rear = 0;
	for (i = 0 ; i < g. n; i++ ) visited[i] = 0 ;
	printf("%d ", v);
	visited [v] = 1;
	rear = (rear = 1) % MAXVEX;
	Qu [rear] = v;
	while (front != rear) {
		front = (front + 1) % MAXVEX;
		w = Qu [front];
		for (i = 0 ; i < g. n; i++)
			if (g.edges[w][i] != 0 && g.edges[w][i] != INF && visited[i] == 0) {
			printf("%d ", i);
			visited[i] = 1;
			rear = (rear + 1) % MAXVEX;
			Qu [rear] = i;
		}
	}
}

int main() {
	MatGraph g;
	int n = 7, e = 12, v;
	int A[MAXVEX][MAXVEX] = {
		{0, 2, 5, 3, INF, INF, INF},
		{INF, 0, 2, INF, INF, 8, INF},
		{INF, INF, 0, 1, 3, 5, INF},
		{INF, INF, INF, 0, 5, INF, INF},
		{INF, INF, INF, INF, 0, 3, 9  },
		{INF, INF, INF, INF, INF, 0, 5  },
		{INF, INF, INF, INF, INF, INF, 0  },
	};
	CreateGraph(g, A, n, e);
	//DispGraph(g);
	cin >> v;
	BFS1(g, v);
	DestroyGraph(g);
	return 0;
}
