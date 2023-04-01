#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

PII p[N];//���е���������

int wk[N], wc[N];//wkΪ�������ÿ��λ���ã�wcΪ��������վ
int fa[N];//��¼ÿ�����뼯�������󣬸õ����ӵ��Ǽ����е��ĸ���

int n;

LL dist[N];
bool st[N];

vector<int> powerStation;//�洢�������糧�ĳ���
vector<PII> wireCity;//�洢���ߵĳ�������

LL getDist(int a,int b)
{
	int dx = abs(p[a].first - p[b].first);
	int dy = abs(p[a].second - p[b].second);
	return (LL)(dx + dy) * (wk[a] + wk[b]);
}


LL prim()
{
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;    //����Դ�������Ϊ0
	LL ans = 0;

	for (int i = 1; i <= n; i++) dist[i] = wc[i];//�Ѽ�������Դ�㣬��ʼ���г��е�����Դ��ı�Ȩ

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

		//�����ǰ�� u ���뼯������������һ���㲻������Դ�㣬��˵���������㶼�ǳ��У��������߷�����
		if (!fa[u]) powerStation.push_back(u);
		//����������� u �������Ǹ���������Դ�㣬��˵�� u �ǽ��跢��վ�ĳ��У�������뷢��վ������
		else 
		{
			wireCity.push_back({ fa[u],u });
		}
		for (int j = 1; j <= n; j++)//���������������ߵ�ʱ����
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
	}//��ȡ��������

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		wc[i] = x;
	}//����ÿ�����н������糧�ķ���

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		wk[i] = x;
	}//����ÿ�����м��赥λ���ߵķ���

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