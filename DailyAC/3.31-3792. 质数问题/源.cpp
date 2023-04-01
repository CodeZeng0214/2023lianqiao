#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int st[N];//��¼����
int prim[N];//��¼����
int cnt;//��������


void GetPrim(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!st[i]) prim[++cnt] = i;
		for (int j = 1; 1ll * i * prim[j] <= n; j++)
		{
			st[prim[j] * i] = 1;
			if (i % prim[j] == 0) break;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	GetPrim(N);

	while (T--)
	{
		int n, k;
		cin >> n >> k;


		//����
		/*for (int i = 1; i <= cnt; i++)
		{
			cout << prim[i] << " ";
		}
		cout << endl;*/

		int ans = 0;
		for (int i = 1; i < cnt; i++)
		{
			int x = prim[i] + prim[i + 1] + 1;
			if (x <= n && st[x] == 0)
			{
				ans++;
			}
		}
		if (ans >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}