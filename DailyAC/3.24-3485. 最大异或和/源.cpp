//https://www.bilibili.com/video/BV1yA4y1Z74t/?spm_id_from=333.337.search-card.all.click&vd_source=caecf80374a9146fe3069ef72b4bd1c4
//trie���Բο��������Ƶ����

#include<bits/stdc++.h>
using namespace std;

const int n = 3100010;
int n, m;
int tr[n][2], cnt[n], idx;//����trie�����ݽṹ��tr�����N����2�����λѡ0����ѡ1��ÿ�������ֵ����һ��Ψһ�����֣�cnt�������ֳ��ֵĴ���
int s[n];//ǰ׺��������

void Insert(int x, int v)//֧��ɾ�������ӵ�trie
{
	int p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1;//ȡ���ڼ�λ
		if (!tr[p][u]) tr[p][u] = ++idx;
		p = tr[p][u];
		cnt[p] += v;
	}
}

int Query(int x)//��ѯ���ֵ
{
	int res = 0, p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int u = x >> i & 1;
		if (cnt[tr[p][!u]]) p = tr[p][!u], res = res * 2 + 1;//������ҵ����Ϊ1�ľ�ת���Ǹ���㣬����һ������ֵ
		else p = tr[p][u], res *= 2;//�Ҳ�������ͬ�Ľ�㣬��һ��    //�Ҳ��ҵ�����cnt������飬����ǽ��ֵ
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
	Insert(s[0], 1);//������ʼ������Ϊ�����飬��00000����������
	for (int i = 1; i <= n; i++)
	{
		if (i - m - 1 >= 0) Insert(s[i - m - 1], -1);//��������ɾȥǰ���ֵ
		ans = max(ans, Query(s[i]));
		Insert(s[i], 1);
	}

	cout << ans;
	return 0;
}