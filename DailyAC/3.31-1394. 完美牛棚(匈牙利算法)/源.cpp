#include<bits/stdc++.h>
using namespace std;

int n, m;

const int N = 210, M = 40010;
int h[N], e[M], ne[M], idx, match[N];
bool st[N];

void Add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool Dfs(int u)
{
	for (int j = h[u]; ~j; j = ne[j])
	{
		int x = e[j];
		if (st[x]) continue;
		st[x] = true;
		if (!match[x] || Dfs(match[x]))
		{
			match[x] = u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	
	memset(h, -1, sizeof h);
	//不要忘记初始化，不然会死循环
	
	for (int i = 1; i <= n; i++)
	{
		int s;
		cin >> s;
		while (s--)
		{
			int x;
			cin >> x;
			Add(i, x);
		}

	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(st, 0, sizeof st);
		if (Dfs(i)) ans++;
	}
	cout << ans;
	return 0;
}