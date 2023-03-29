#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

const int n = 103;
int h[n];

int find(int x)
{
	int t = x % n;
	while (h[t] != -1 && h[t] != x)
		if (++t == n)
			t = 0;
	return t;
}//��д��ϣ��

int Base(string s,int b)
{
	int res = 0;
	for (auto x : s)
		res = res * b + x - '0';//��ΪxΪ�ַ������Լ�ȥ0���ַ��ͱ��ཫxתΪ����
	return res;
}

int main()
{
	string x, y;
	cin >> x >> y;
	memset(h, -1, sizeof h);//��д��ϣ��ʼ��
	unordered_set<int> hash;
	for (int i = 0; i < x.size(); i++)
	{
		string s = x;
		s[i] ^= 1;//0��1�İ�˹�����48��49���պ��������
		if (s.size() > 1 && s[0] == '0') continue;
		hash.insert(Base(s, 2));
	}
	for (int i = 0; i < y.size(); i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (y[i] - '0' != j)//����ת��Ϊ��˹����
			{
				string s = y;
				s[i] = j + '0';
				if (s.size() > 1 && s[0] == '0') continue;
				int n = Base(s, 3);
				if (hash.count(n))
				{
					cout << n << endl;
				}
			}
		}
	}
	return 0;
}