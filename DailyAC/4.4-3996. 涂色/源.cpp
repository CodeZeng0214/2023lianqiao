#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
int n;
int c[N], f[N][N];

int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> c[i];
	}
	n = unique(c, c + n) - c;//unique函数可以去除数组的重复序列，
							//并返回去除后的数组的末元素地址，
							//减去c（即首元素地址）可以得出去除后的数组长度
	for (int len = 2; len <= n; len++)//区间DP从长度开始枚举
	{
		for (int i = 0; i + len - 1 < n; i++)//思考f[i][i] = 0;  
		{
			int j = i + len - 1;
			if (c[i] != c[j]) f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
			else f[i][j] = f[i + 1][j - 1] + 1;
		}
	}
	cout << f[0][n - 1];
	return 0;
}