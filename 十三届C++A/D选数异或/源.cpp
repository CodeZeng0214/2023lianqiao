#include<bits/stdc++.h>
using namespace std;

int a[100005];
int f[100005];
map<int, int> Hash;

//a^b=x; a^x=b

int main()
{
	int n, m, x;
	int l, r;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = max(f[i - 1], Hash[a[i] ^ x]);//��ǰi������������Ե�������±�����
		Hash[a[i]] = i;
	}
	while (m--)
	{
		cin >> l >> r;
		if (f[r] >= l)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}