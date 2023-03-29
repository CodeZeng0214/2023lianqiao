#include<bits/stdc++.h>
using namespace std;

int n;
char str[1000010];
int ne[1000010];

//求出next数组
void GetNext(char s[])
{
	ne[1] = 0;
	for (int i = 2, j = 0; i <= n; i++) 
	{
		while (j && s[i] != s[j + 1]) j = ne[j];
		if (s[i] == s[j + 1]) j++;
		ne[i] = j;
	}

	//自己的求法，求得不对
	/*while (i < N)
	{
		if (j == 0 || s[i] == s[j])
		{
			ne[++i] = ++j;
		}
		else
		{
			j = ne[j];
		}
	}*/
}


int main()
{
	int n = 1;
	while (1)
	{
		cin >> n;
		if (!n) break;
		cin >> str + 1;//可以将字符串从数组下标一开始录入
		cout << str;
		GetNext(str);//KMP算法的next数组
		cout << "Test case #" << n++ << endl;
		for (int i = 1; i <= n; i++)
		{
			int t = i - ne[i];
			if (i % t == 0 && i / t > 1)
			{
				cout << i << " " << i / t << endl;
			}
		}
		cout << endl;
	}
	return 0;
}


////int a[100005];
//
//int main()
//{
//	int N;
//	int n = 1;
//	while(1)
//	{
//		cin >> N;
//		if (!N) break;
//		cin >> str;
//		cout << "Test case #" << n++ << endl;
//		//for (int i = 0; i < N / 2; i++)
//		//{
//		//	int res = 0;
//		//	s = str.substr(0, i + 1);
//		//	while (++res)
//		//	{
//		//		if ((i + 1) * res > N) break;
//		//		if (s != str.substr((i + 1) * res, i + 1))
//		//		{
//		//			a[(i + 1) * res - 1] = i + 1;
//		//			break;
//		//		}
//		//	}
//		//}
//		//for (int i = N - 1; i >= 0; i--)
//		//{
//		//	if (a[i])//遇到有数的
//		//	{
//		//		continue;
//		//	}
//		//	else
//		//	{
//		//		a[i - 1] += a[i];
//		//	}
//		//}
//		//for (int i = 0; i < N; i++)
//		//{
//		//	if (a[i] == 0 || (i + 1) % a[i])//不能整除
//		//	{
//		//		continue;
//		//	}
//		//	else
//		//	{
//		//		cout << i + 1 << " " << a[i] << endl;
//		//	}
//		//}
//
//		for (int i = 1; i < N; i++)
//		{
//			for (int j = 0; j < (i + 1) / 2; j++)
//			{
//				if ((i + 1) % (j + 1)) continue;
//				int res = (i + 1) / (j + 1);
//				s = str.substr(0, j + 1);
//				bool same = true;
//				while (res--)
//				{
//					if (s != str.substr((j + 1) * res, j + 1))
//					{
//						same = false;
//						break;
//					}
//				}
//				if (same)
//				{
//					cout << i + 1 << " " << (i + 1) / (j + 1) << endl;
//					break;
//				}
//			}
//		}
//		cout <<endl;
//	}
//	return 0;
//}