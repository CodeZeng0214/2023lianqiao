#include<bits/stdc++.h>
using namespace std;

int n, m;
const int n = 200010, m = n;
int h[n], e[m], ne[m], idx;
int d[n];//��¼���
int tp[n];//��¼������������

struct Edge
{
	int a, b;
}edge[m];
int pos[n];//��¼������������������е�λ��

void Add(int a, int b)//���һ����a->b
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

bool Topsort()
{
	int tpSet = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (d[i] == 0) q.push(i);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		tp[tpSet++] = x;
		for (int j = h[x]; j != -1; j = ne[j])
		{
			int t = e[j];
			if (--d[t] == 0) q.push(t);
		}
	}
	return tpSet == n;
}

//�����������к����Ƿ�����
//int main()
//{
//	cin >> n >> m;
//	memset(d, 0, (n + 1) * 4);
//	memset(h, -1, (n + 1) * 4);
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		Add(a, b);
//		d[b]++;
//	}
//	if(!Topsort()) puts("NO");
//	else
//	{
//		puts("YES");
//		for (int i = 0; i < n; i++)
//		{
//			cout << tp[i] << " ";
//		}
//	}
//	return 0;
//}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		int cnt = 0;//��¼�����

		memset(h, -1, (n + 1) * 4);
		idx = 0;
		memset(d, 0, (n + 1) * 4);
		
		while (m--)
		{
			int f, a, b;
			cin >> f >> a >> b;
			if (f)
			{
				Add(a, b);
				d[b] ++;
			}
			else
			{
				edge[cnt++] = { a, b };
			}
		}
		if (!Topsort()) puts("NO");
		else
		{
			puts("YES");
			for (int i = 1; i <= n; i++)
				for (int j = h[i]; ~j; j = ne[j])
					cout << i << " " << e[j] << endl;
			for (int i = 0; i < n; i++) pos[tp[i]] = i;
			for (int i = 0; i < cnt; i++)
			{
				int a = edge[i].a, b = edge[i].b;
				if (pos[a] > pos[b]) swap(b, a);
				cout << a << " " << b << endl;
			}
		}
	}
	return 0;
}