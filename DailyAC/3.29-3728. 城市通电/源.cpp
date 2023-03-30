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