#include<bits/stdc++.h>
using namespace std;

long long mod = 998244353;
long long ex[100005];
long long f[100005];

long long Qmi(long long a, long long b)
{
	long long base = a;
	long long res = 1;
	while (b) 
	{
		if (b & 1) res = res * a;
		a = a * a % mod;
		b >>= 1;
		res %= mod;
		a %= mod;
	}
	return res % mod;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long x, y;
		cin >> x >> y;
		long long xx = y - x;
		long long yy = y;
		swap(xx, yy);
		xx -= yy;
		yy = Qmi(yy, mod - 2);
		xx %= mod;
		xx *= yy;
		ex[i] = xx % mod;
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int r = (ex[i] * (f[i - 1] + 1) + 1);
		f[i] = r % mod + f[i - 1];
	}
	cout << f[n];
	return 0;
}

/*int main()
{
	int n;
	long long z = 1;
	long Mod = 998244353;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; i++)
	{
		z = z % Mod * ((((x[i] % Mod * y[i] % Mod) % Mod) * (Qmi(((y[i] - x[i]) % Mod * (y[i] - x[i]) % Mod) % Mod, Mod - 2, Mod)) % Mod) % Mod);
	}
	cout << z % Mod;
	return 0;
}*/