#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2010, MOD = 998244353;
int c[N][N];//��Ϊ��
int n, m, k;

//���õ��ƣ�������ǣ�Ԥ����C�����������
void GetC1()
{
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= i && j <= k; j++)
		{
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}

//������
int Qmi(int a, int b, int MOD)
{
	int res = 1 % MOD;
	while (b)
	{
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

//�˷���Ԫ���������ϴ������
int f[N], g[N];
void init()
{
	f[0] = g[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (LL)f[i - 1] * i % MOD;
		g[i] = (LL)g[i - 1] * Qmi(i, MOD - 2, MOD) % MOD;
	}
}

LL GetC2(LL n, LL k,int MOD)
{
	return (LL)f[n] * g[k] % MOD * g[n - k] % MOD;
}

//¬��˹������������
LL Lucas(LL n, LL k, int MOD)
{
	if (m == 0)return 1;
	return Lucas(n / MOD, k / MOD, MOD) * GetC2(n % MOD, k % MOD, MOD) % MOD;
}


int main()
{
	cin >> n >> m >> k;

	GetC1();

	int ans = 1;
	ans = (LL)c[n - 1][k] * m % MOD;
	ans = (LL)ans * Qmi(m - 1, k, MOD) % MOD;
	cout << ans;
}