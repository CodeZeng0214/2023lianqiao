#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


const int n = 6, m = 6;
int g[n][m];
int n, m, k;
unordered_set<int> s;//利用哈希表可以得出不重复的数的个数
int dx[4]{ -1,0,1,0 }, dy[4]{ 0,1,0,-1 };//依次为上，右，下，左

void Dfs(int x, int y, int u, int num)
{
	if (u == k) s.insert(num);
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a > 0 && a <= n && b <= m && b > 0) Dfs(a, b, u + 1, num * 10 + g[a][b]);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> g[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			Dfs(i, j, 0, g[i][j]);
		}
	}
	cout << s.size();
	return 0;
}