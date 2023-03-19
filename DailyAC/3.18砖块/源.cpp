#include<bits/stdc++.h>
using namespace std;

string str;
int n;

char Updata(char r)
{
	if (r == 'B') return 'W';
	if (r == 'W') return 'B';
}

bool Check(char c)
{
	vector<int> res;
	string s = str; //因为可能存在两次CHECK，为了避免第二次判定时，str被修改，需要这个s作为暂存
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] != c)
		{
			s[i] = Updata(s[i]);
			s[i + 1] = Updata(s[i + 1]);
			res.push_back(i);
		}
	}
	if (s.back() != c)
	{
		return false;
	}
	cout << res.size() << endl;
	for (int x : res) cout << x + 1 << " ";
	if (res.size()) cout << endl;
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> str;
		if (!Check('B') && !Check('W'))
		{
			cout << -1 << endl;
		}
	}
	return 0;
}