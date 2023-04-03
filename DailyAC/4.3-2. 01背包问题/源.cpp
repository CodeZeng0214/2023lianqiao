#include<bits/stdc++.h>
using namespace std;

const int N = 1010, V = 1010;
int f[N][V];
int n, v;
int g[N], w[N];

void DP()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (g[i] <= j)
			{
				f[i][j] = max(f[i - 1][j], f[i - 1][j - g[i]] + w[i]);
			}
			else
			{
				f[i][j] = f[i - 1][j];
			}
		}
	}
}

int main()
{
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i] >> w[i];
	}
	DP();
	cout << f[n][v];
	return 0;
}