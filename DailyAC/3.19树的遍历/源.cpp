#include<bits/stdc++.h>
using namespace std;

const int N = 35;

int a[N], b[N], p[N];
vector<int> level[N];

void Build(int al, int ar, int bl, int br, int d)
{
	if (al > ar) return;
	int val = a[ar];
	level[d].push_back(val);
	int k = p[val];
	Build(al, al + k - 1 - bl, bl, k - 1, d + 1);//遍历左子树
	Build(al + k - bl, ar - 1, k + 1, br, d + 1);//遍历右子树
	return;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];//后序遍历
	for (int i = 1; i <= n; i++) cin >> b[i];//中序遍历
	for (int i = 1; i <= n; i++) p[b[i]] = i;//中序遍历的位置

	Build(1, n, 1, n - 1, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int x : level[i]) cout << x << " ";
	}

	return 0;
}