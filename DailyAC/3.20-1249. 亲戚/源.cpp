#include<bits/stdc++.h>
using namespace std;

int f[20005];

int Find(int x)
{
	if (f[x] != x) return (f[x] = Find(f[x]));//�����ǰ�ڵ㲻��ĩβ�ڵ㣬�����������ȥ�����ҽ����ĸ��ڵ㸳�������Ľڵ�
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
		scanf("%d%d", &x, &y);//���ַ�ʽ��cin��
		f[Find(x)] = Find(y);//��Ӽ��Ϲ�ϵ
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
			puts("No");//���ַ�ʽ��cout��
		}
	}
	return 0;
}