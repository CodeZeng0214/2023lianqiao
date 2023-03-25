#include<bits/stdc++.h>
using namespace std;

int n, l;

const int N = 1010, M = 100010;//N代表点，M代表边

int h[N], e[M], ne[M], idx;//h数组存储最新的，结点的下一条边编号，e存储边的终点，
bool st[N];						//ne代表第idx条边的下一条边的idx。如果当前结点没有出边即为-1

void Add(int a, int b)//a为起点，b为终点
{
	e[idx] = b;//第idx条边的终点
	ne[idx] = h[a];//第idx条边的下一条边的idx。如果当前结点没有出边即为-1
	h[a] = idx++;//当前点有新的出边，更新为最后一次添加边的序号
}

//队列实现Bfs
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
			q.pop();//出队
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
	memset(h, -1, sizeof h);//初始化
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