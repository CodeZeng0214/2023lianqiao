#include<bits/stdc++.h>
using namespace std;

const int N = 21, M = 1000010, MOD = 1e9;
int n, m;
int f[N][M];//二维做法
int fa[M];//一维做法

int main()
{
	cin >> n;
	//一维做法
	//for (int i = 0, v = 1; i <= 21; i++, v *= 2)
	//{
	//	for (int j = 0; j <= n; j++)
	//	{
	//		if (!i || !j) //状态为 f[i][0] 和 f[0][j] 时，将其初始化为 1
	//		{   
	//			f[i][j] = 1;
	//			continue;
	//		}
	//		if (v > j)
	//		{
	//			f[i][j] = f[i - 1][j];
	//		}
	//		else
	//		{
	//			f[i][j] = (f[i - 1][j] + f[i][j - v]) % MOD;
	//		}
	//	}
	//}
	for (int i = 0, v = 1; i <= 21; i++, v *= 2)
	{
		for (int j = 0; j <= n; j++)
		{
			if (!j) //状态为 f[i][0] 和 f[0][j] 时，将其初始化为 1
			{
				fa[j] = 1;
				continue;
			}
			if (v > j)
			{
				fa[j] = fa[j];
			}
			else
			{
				fa[j] = (fa[j] + fa[j - v]) % MOD;
			}
		}
	}
	cout << fa[n];
	return 0;
}