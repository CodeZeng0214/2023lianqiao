#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1010;
int l[N], r[N], p[N];//�ֱ�����������������͸��ڵ�
int dist[N];//��������

void Dfs (int x, int d)
{
	dist[x] = d;
	if (l[x] != -1) Dfs(l[x], d + 1);
	if (r[x] != -1) Dfs(r[x], d + 1);
}

int GetLca(int a, int b)//��ɽ���󹫹�����
{
	if (dist[a] > dist[b]) swap(a, b);
	while (dist[b] > dist[a]) b = p[b];
	while (a != b) a = p[a], b = p[b];
	return a;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		memset(p, -1, sizeof p);
		memset(l, -1, sizeof l);
		memset(r, -1, sizeof r);
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			l[i] = x;
			r[i] = y;
			if (x != -1) p[x] = i;
			if (y != -1) p[y] = i;
		}//����������

		Dfs(1, 0);

		while (m--)
		{
			int a, b;
			cin >> a >> b;
			cout << dist[a] + dist[b] - 2 * dist[GetLca(a, b)] << endl;
		}
	}
	return 0;
}