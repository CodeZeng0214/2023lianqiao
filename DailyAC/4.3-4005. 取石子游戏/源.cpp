#include<bits/stdc++.h>
using namespace std;

const int N = 100;
bool f[N];//���ĺ���������n��ʱ�������Ƿ���ڱ�ʤ�Ĳ���

int n, k;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		
		//���ģ����Ѱ�ҹ���
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
		{//����k%3!=0�������n<k��n>k������ɺϲ�
			if (n % 3) puts("Alice");//�ж���n%(2+1)����0����ֱ�ʤ���������ֱ�ʤ��
			else puts("Bob");
		}
		else
		{
			n %= k + 1;//����k%3==0�����, n<k��n>k������ɺϲ�,n��n%(k+1)�Ľ����ͬ
			if (n == k || n % 3) puts("Alice");//n==k���������ֱ�ʤʤ���������ֱ�ʤ��
			else puts("Bob");//������ȣ��ж���n%(2+1)������0����ֱ�
		}
	}
	return 0;
}