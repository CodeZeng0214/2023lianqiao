//#include <iostream>
//using namespace std;
//int a[200000];
//int main()
//{
//	int n;
//	long ans = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i+1; j < n; j++)
//		{
//			ans += a[i] * a[j];
//		}
//	}
//	cout << ans;
//	return 0;
//}
//上述解法超时，可以避免嵌套循环

#include <iostream>
using namespace std;
int a[200000];
long b[200000];
int main()
{
	int n;
	long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		b[0] += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		b[i + 1] = b[i] - a[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		ans += a[i] * b[i+1];
	}
	cout << ans;
	return 0;
}


//#include <bits/stdc++.h>
//#define LL long long 
//using namespace std;
//const int maxn = 1e6 + 10;
//const int mod = 1e9 + 7;
//const int INF = 1e9 + 10;
//const int N = 1e6;
//LL n;
//LL a[N];
//LL sum[N];
//int main() {
//	cin >> n;
//	for (LL i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum[i] = sum[i - 1] + a[i];
//	}
//	LL ans = 0;
//	for (LL i = 1; i <= n; i++) {
//		ans += a[i] * (sum[n] - sum[i]);
//	}
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}
