#include<bits/stdc++.h>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;
int f[N][N], g[N][N];//f代表铁路

int n, m;

int floyd(int d[N][N])
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	return d[1][n];
}

//朴素版Dijkstra
int dist[N];
bool st[N];
int Dijkstra(int d[N][N])
{
	if (d[1][n] == 1) return 1;
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);

	dist[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int u = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (u == -1 || dist[j] < dist[u]))
			{
				u = j;
			}
		}
		st[u] = true;

		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], dist[u] + d[u][j]);
	}
	return dist[n];
}

const int N = 410, M = 160010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];
//初始化SPFA
void Add(int a, int b, int c) 
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void SpfaInit()
{
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof f);
	memset(h, -1, sizeof h), idx = 0; 
	memset(dist, 0x3f, sizeof dist);   
	memset(st, 0, sizeof st);   //将邻接表初始化

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j && f[i][j] == 1)
			{
				Add(i, j, 1);
				Add(j, i, 1);
			}
		}
	}
}
//SPFA
int SPFA()
{
	queue<int> q;
	dist[1] = 0;
	st[1] = true;
	q.push(1);
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int j = h[t]; ~j; j = ne[j])
		{
			int x = e[j];
			if (dist[x] > dist[t] + w[j])
			{
				dist[x] = dist[t] + w[j];
				if (!st[x]) q.push(x), st[x] = true;
			}
		}
	}
	return dist[n];
}

int main()
{
	cin >> n >> m;
	memset(f, INF, sizeof f);
	memset(g, INF, sizeof f);//floyd算法初始化无边为无穷大，自环为0

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		f[a][b] = f[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j && f[i][j] != 1)
			{
				g[i][j] = 1;
			}
		}
	}

	int ans = max(floyd(f), floyd(g));
	if (ans == INF) ans = -1;
	cout << ans;
	return 0;
}