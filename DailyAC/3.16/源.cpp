#include<bits/stdc++.h>

using namespace std;

int a[200005];
int v[200005];

void add(int l, int r)//һά���ģ��
{
	a[l] += 1;
	a[r + 1] -= 1;
}

int main()
{
	/*int t, n, flag, temp;
	cin >> t;
	while (t)
	{
		cin >> n;
		flag = 0;
		temp = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			v[i] = 0;
			temp = a[i];
			while (temp)
			{
				if (a[i - (a[i] - temp)] > temp)
				{
					break;
				}
				if (i - (a[i] - temp) >= 1)
				{
					v[i - (a[i] - temp)] = 1;
				}
				else
				{
					break;
				}
				temp--;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		t--;
	}*/

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if (!x)
			{
				continue;
			}
			if (x >= i)
			{
				add(1, i);
			}
			else
			{
				add(i - x + 1, i);
			}
		}
		for (int i = 1; i <= n; i++) a[i] += a[i - 1];
		for (int i = 1; i <= n; i++)
		{
			//����ǰ׺�������������0�ͱ�ʾû�з���0��1���������Ϊ0���Ƿ�����0��1�����
			if (a[i] != 0) cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
}