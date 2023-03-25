#include<bits/stdc++.h>
using namespace std;

int n, l;

const int N = 1010, M = 100010;//N����㣬M�����

int h[N], e[M], ne[M], idx;//h����洢���µģ�������һ���߱�ţ�e�洢�ߵ��յ㣬
bool st[N];						//ne�����idx���ߵ���һ���ߵ�idx�������ǰ���û�г��߼�Ϊ-1

void Add(int a, int b)//aΪ��㣬bΪ�յ�
{
	e[idx] = b;//��idx���ߵ��յ�
	ne[idx] = h[a];//��idx���ߵ���һ���ߵ�idx�������ǰ���û�г��߼�Ϊ-1
	h[a] = idx++;//��ǰ�����µĳ��ߣ�����Ϊ���һ����ӱߵ����
}

//����ʵ��Bfs
int Bfs(int start)
{
	queue<int> q;
	memset(st, 0, sizeof st);
	q.push(start);
	st[start] = true;
	int ans = 0;
	for (int i = 0; i < l; i++)
	{
		int sz = q.size();
		while (sz--)
		{
			int t = q.front();
			q.pop();//����
			for (int j = h[t]; j != -1; j = ne[j])
			{
				int x = e[j];
				if (!st[x])
				{
					q.push(x);
					st[x] = true;
					ans++;
				}
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n >> l;
	idx = 0;
	memset(h, -1, sizeof h);//��ʼ��
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		while (m--)
		{
			int x;
			cin >> x;
			Add(x, i);
		}
	}
	int k;
	cin >> k;
	while (k--)
	{
		int qus;
		cin >> qus;
		cout << Bfs(qus) << endl;
	}
	return 0;
}