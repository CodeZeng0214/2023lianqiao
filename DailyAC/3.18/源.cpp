#include<bits/stdc++.h>
using namespace std;

string str;

int main()
{
	int n;
	int ans = 0;
	int flag = 0;
	cin >> n >> str;
	for (int i = 0; i <= n; i++)
	{
		if (str[i] != 'x')
		{
			if (flag >= 2)
			{
				ans += (flag -= 2);
			}
			flag = 0;
		}
		else
		{
			flag++;
		}
	}
	cout << ans;
	return 0;
}