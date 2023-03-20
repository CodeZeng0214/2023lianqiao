#include<bits/stdc++.h>
using namespace std;

int f[20005];

int Find(int x)
{
	if (f[x] != x) return (f[x] = Find(f[x]));//如果当前节点不是末尾节点，则继续查找下去，并且将最后的根节点赋给经过的节点
	return f[x];
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);//这种方式比cin快
		f[Find(x)] = Find(y);//添加集合关系
	}
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		if (Find(m) == Find(n))
		{
			puts("Yes");
		}
		else
		{
			puts("No");//这种方式比cout快
		}
	}
	return 0;
}