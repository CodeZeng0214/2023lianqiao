#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str;
	for (int k = 1; k <= n; k++)
	{
		bool flag = false;
		for (int i = 0; i + k - 1 < n; i++)
		{
			for (int j = i + 1; j + k - 1 < n; j++)
			{
				bool same = true;
				for (int u = 0; u < k; u++)
				{
					if (str[i + u] != str[j + u])
					{
						same = false;
						break;
					}
				}
				if (same)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (!flag)
		{
			cout << k << endl;
			break;
		}
	}
	return 0;
}