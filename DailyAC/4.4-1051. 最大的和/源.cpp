#include<bits/stdc++.h>
using namespace std;

const int N = 50010;

int f[N], g[N], s, num[N], INF = 1e9;//f,g�ֱ���ǰ/�������е�������������к�

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> num[i];
		f[0] = g[n + 1] = -INF;
		s = -INF;
		//s����i��β���������������ֵ
		for (int i = 1; i <= n; i++)//ǰ׺
		{
			s = max(num[i], s + num[i]);
			f[i] = max(f[i - 1], s);
		}
		s = -INF;
		for (int i = n; i >= 1; i--)//��׺
		{
			s = max(num[i], s + num[i]);
			g[i] = max(g[i + 1], s);
		}
		int ans = -INF;
		for (int i = 1; i <= n; i++)//�����ڵ�
		{
			ans = max(f[i] + g[i + 1], ans);
		}
		cout << ans << endl;
	}
	return 0;
}