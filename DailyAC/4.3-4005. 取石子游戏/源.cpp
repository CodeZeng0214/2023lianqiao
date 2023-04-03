#include<bits/stdc++.h>
using namespace std;

const int N = 100;
bool f[N];//打表的函数，代表n的时候先手是否存在必胜的策略

int n, k;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		
		//打表模拟来寻找规律
		f[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			int b[3] = { 1,2,k };
			for (int x : b)
			{
				if (i >= x && !f[i - x])
				{
					f[i] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			//cout << f[i] << " ";
		}

		if (k % 3)
		{//对于k%3!=0的情况，n<k与n>k的情况可合并
			if (n % 3) puts("Alice");//判断若n%(2+1)等于0则后手必胜，否则先手必胜。
			else puts("Bob");
		}
		else
		{
			n %= k + 1;//对于k%3==0的情况, n<k与n>k的情况可合并,n与n%(k+1)的结果相同
			if (n == k || n % 3) puts("Alice");//n==k此情形先手必胜胜，否则先手必胜。
			else puts("Bob");//若不相等，判断若n%(2+1)，等于0则后手必
		}
	}
	return 0;
}