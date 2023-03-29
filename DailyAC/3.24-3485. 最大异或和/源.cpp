//https://www.bilibili.com/video/BV1yA4y1Z74t/?spm_id_from=333.337.search-card.all.click&vd_source=caecf80374a9146fe3069ef72b4bd1c4
//trie可以参看上面的视频讲解

#include<bits/stdc++.h>
using namespace std;

const int n = 3100010;
int n, m;
int tr[n][2], cnt[n], idx;//定义trie的数据结构，tr数组的N代表，2代表该位选0或者选1，每个数组的值代表一个唯一的数字，cnt就是数字出现的次数
int s[n];//前缀异或和数组

void Insert(int x, int v)//支持删除和增加的trie
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1;//取出第几位
		if (!tr[p][u]) tr[p][u] = ++idx;
		p = tr[p][u];
		cnt[p] += v;
	}
}

int Query(int x)//查询最大值
{
	int res = 0, p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1;
		if (cnt[tr[p][!u]]) p = tr[p][!u], res = res * 2 + 1;//如果能找到异或为1的就转向那个结点，并算一下异或的值
		else p = tr[p][u], res *= 2;//找不到就相同的结点，算一下    //找不找到的用cnt这个数组，存的是结点值
	}
	return res;
}


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		s[i] = s[i - 1] ^ x;
	}

	int ans = 0;
	Insert(s[0], 1);//考虑起始，可以为空数组，即00000···，则
	for (int i = 1; i <= n; i++)
	{
		if (i - m - 1 >= 0) Insert(s[i - m - 1], -1);//滑动窗口删去前面的值
		ans = max(ans, Query(s[i]));
		Insert(s[i], 1);
	}

	cout << ans;
	return 0;
}