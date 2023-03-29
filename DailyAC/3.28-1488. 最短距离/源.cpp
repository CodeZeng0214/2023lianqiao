//#define CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int n, m;

typedef pair<int, int> PII;

const int n = 100010, m = 200020;
int h[n], w[m], e[m], ne[m], idx;
int dist[n];
bool st[n];

void Add(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}

void Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;//超级源点的下标为0，从超级源点开始做单源最短路**
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0,0 });

	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();
		
		int ver = t.second, distance = t.first;
		if (st[ver]) continue;
		st[ver] = true;

		for (int j = h[ver]; ~j; j = ne[j])
		{
			int x = e[j];
			if (dist[x] > distance + w[j])
			{
				dist[x] = distance + w[j];
				heap.push({ dist[x],x });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);

	while (m--)
	{
		int a, b, c;
		//scanf("%d%d%d", &a, &b, &c);
		cin >> a >> b >> c;
		Add(a, b, c);  //无向图**
		Add(b, a, c);
	}

	int k;
	cin >> k;
	while (k--)
	{
		int num;
		cin >> num;
		Add(0, num, 0);//超级源点与各源点的距离为0，且有向**
	}
	Dijkstra();

	int q;
	cin >> q;
	while (q--)
	{
		int num2;
		cin >> num2;
		cout << dist[num2] << endl;//任意点到多源点的最短距离**
	}
	return 0;
}