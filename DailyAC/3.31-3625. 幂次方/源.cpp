#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL x, n;
const LL M = 233333;

int qmi(int a, int b, int q)
{
	int res = 1 % q;//����q=1;
	while (b)
	{
		if (b & 1)/*�ж�b��ĩλ�Ƿ�Ϊ1��Ϊ1Ϊ��*/ res = (LL)res * a % q;
		a = (LL)a * a % q;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin >> x >> n;
	x %= M;
	cout << qmi(x, n, M);
	return 0;
}