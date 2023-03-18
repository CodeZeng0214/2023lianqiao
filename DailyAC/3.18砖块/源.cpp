#include<bits/stdc++.h>
using namespace std;


char Updata(char r)
{
	if (r == 'B') return 'W';
	if (r == 'W') return 'B';
}

bool Check(char c)
{
	vector<int> res;
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] != c)
		{
			str[i] = Updata(str[i]);
			str[i + 1] = Updata(str[i + 1]);
			res.push_back(i);
		}
	}
	if (str.back() != c)
	{
		return false;
	}
		cout << res.size() << endl;
		for (int x : res) cout << x + 1 << " ";
		if (res.size()) cout << endl;
		return true;
}

string str;
int n;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> str;
		if (!Check('B') && !Check('W'))
		{
			cout << -1 << endl << 0 << endl;
		}
	}
	return 0;
}