#include<bits/stdc++.h>

using namespace std;

int n;
//int a[100005];
long long s[100005];
int main()
{
	/*int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum = 0;*/
	long long ans = 0;
	int x = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	if (s[n] % 3)
	{
		ans = 0;
	}
	else
	{
		long long temp = 0;
		for (int i = 1; i < n - 1; i++)
		{
			if (s[i] == s[n] / 3)
			{
				temp++;
			}
			if (s[i + 1] == s[n] / 3 * 2)
			{
				ans += temp;
			}
		}
		/*for (int i = 1; i <= n; i++)
		{
			sum1 += a[i];
			sum3 = 0;
			if (sum1 == sum / 3)
			{
				for (int j = n; j > i; j--)
				{
					if (j - i <= 1)
					{
						break;
					}
					sum3 += a[j];
					if (sum1 == sum3)
					{
						sum2 = sum - sum1 - sum3;
						if (sum1 == sum2)
						{
							ans += 1;
						}
					}
				}
			}
		}*/
	}
	if (n <= 2)
	{
		ans = 0;
	}
	cout << ans;
	return 0;
}