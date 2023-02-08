#include <bits/stdc++.h>

using namespace std;

int n, x;
int h[100005];
int H[100005];

bool Check(int c)
{
	for (int i = 1; i + c - 1 < n; i++)
	{
		if (H[i + c - 1] - H[i - 1]<2*x)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> h[i];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		H[i] = H[i-1] + h[i];
	}
	int ans = 1; int r = n;
	while (ans < r)
	{
		int mid = (ans + r) / 2;
		if (Check(mid))
		{
			r = mid;
		}
		else
		{
			ans = mid + 1;
		}
	}
	cout << ans;
	return 0;
}

/*int main()
{
	int n, x;
	int ans;
	cin >> n >> x;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> h[i];
	}
	for (int i = 1, j = 0, sum = 0; i < n; ++i)
	{
		while (j < n && sum < 2 * x)
		{
			j++;
			sum += h[j];
		}
		ans = max(ans, j - i + 1);
		sum -= h[i];
	}
	cout << ans;
	return 0;
}*/