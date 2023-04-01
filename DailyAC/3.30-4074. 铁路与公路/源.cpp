#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

PII p[N];//城市的坐标属性

int wk[N], wc[N];//wk为架设电线每单位费用，wc为建立发电站
int fa[N];//记录每个点与集合相连后，该点连接的是集合中的哪个点

int n;

LL dist[N];
bool st[N];

vector<int> powerStation;//存储建立发电厂的城市
vector<PII> wireCity;//存储电线的城市两端

LL getDist(int a,int b)
{
	int dx = abs(p[a].first - p[b].first);
	int dy = abs(p[a].second - p[b].second);
	return (LL)(dx + dy) * (wk[a] + wk[b]);
}


LL prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;    //虚拟源点距离设为0
	LL ans = 0;

	for (int i = 1; i <= n; i++) dist[i] = wc[i];//已加入虚拟源点，初始所有城市到虚拟源点的边权

	for (int i = 0; i < n; i++)
	{
		int u = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (u == -1 || dist[j] < dist[u]))
			{
				u = j;
			}
		}
		st[u] = true;
		ans += dist[u];

		//如果当前的 u 点与集合中相连的另一个点不是虚拟源点，则说明这两个点都是城市，则存入电线方案中
		if (!fa[u]) powerStation.push_back(u);
		//如果集合中与 u 相连的那个点是虚拟源点，则说明 u 是建设发电站的城市，将其存入发电站方案中
		else 
		{
			wireCity.push_back({ fa[u],u });
		}
		for (int j = 1; j <= n; j++)//更新其它点架设电线的时最优
		{
			if (dist[j] > getDist(u, j))
			{
				dist[j] = getDist(u, j);
				fa[j] = u;
			}
		}
	}

	return ans;
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		p[i].first = x;
		p[i].second = y;
	}//读取城市坐标

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		wc[i] = x;
	}//存入每个城市建立发电厂的费用

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		wk[i] = x;
	}//存入每个城市架设单位电线的费用

	cout << prim() << endl;
	cout << powerStation.size() << endl;
	for (int x : powerStation)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << wireCity.size() << endl;
	for (auto x : wireCity)
	{
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}