#include<bits/stdc++.h>
using namespace std;

const int N = 5010;
int n;
int c[N], f[N][N];

int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> c[i];
	}
	n = unique(c, c + n) - c;//unique��������ȥ��������ظ����У�
							//������ȥ����������ĩԪ�ص�ַ��
							//��ȥc������Ԫ�ص�ַ�����Եó�ȥ��������鳤��
	for (int len = 2; len <= n; len++)//����DP�ӳ��ȿ�ʼö��
	{
		for (int i = 0; i + len - 1 < n; i++)//˼��f[i][i] = 0;  
		{
			int j = i + len - 1;
			if (c[i] != c[j]) f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
			else f[i][j] = f[i + 1][j - 1] + 1;
		}
	}
	cout << f[0][n - 1];
	return 0;
}