#include<bits/stdc++.h>
using namespace std;

int n, m, k, t;

const int N = 2010, M = 200010;

int h[N], e[M], w[N]/*时间*/, target[M]/*目标作物*/, ne[M], idx;//A*B=C存的点是AB，目标是C
int dist[N];
queue<int> q;
bool st[N];

void Add(int a, int b, int c)
{
	target[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void spfa()
{
	while (q.size())
	{
		auto x = q.front();
		q.pop();
		st[x] = false;
		for (int j = h[x]; ~j; j = ne[j])
		{
			int y = e[j], z = target[j];
			if (dist[z] > max(dist[x], dist[y]) + max(w[x], w[y]))//关键点DP的分析
			{
				dist[z] = max(dist[x], dist[y]) + max(w[x], w[y]);
				if (!st[z])
				{
					q.push(z);
					st[z] = true;
				}
			}

		}
	}
}

int main()
{
	cin >> n >> m >> k >> t;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	
	memset(dist, 0x3f, sizeof dist);

	while (m--)
	{
		int x;
		cin >> x;
		dist[x] = 0;
		q.push(x);
		st[x] = true;
	}//存入已知源点

	while (k--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Add(a, b, c);
		Add(b, a, c);
	}//存入生成关系

	spfa();
	
	cout << dist[t];

	return 0;
}