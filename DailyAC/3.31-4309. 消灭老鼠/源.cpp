#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

const int N = 1010;

unordered_set<double> h;

int main()
{
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	for (int i = 1; i <= n; i++)
	{
		double x, y, k;
		cin >> x >> y;
		if (x - x0 != 0)
		{
			k = (y - y0) / (x - x0);
		}
		else
		{
			k = 0x3f;
		}
		h.insert(k);
	}
	cout << h.size();
}