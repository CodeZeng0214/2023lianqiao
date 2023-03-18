#include <bits/stdc++.h>

using namespace std;

int N, K;
int ans;
int A[100005];
int R[100005];
int L[100005];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++)
	{
		if (A[i-1] <= A[i])
		{
			L[i] = L[i - 1] + 1;
		}
		else
		{
			L[i] = 1;
		}
	}
	for (int i = N; i >= 1; i--)
	{
		if (A[i] <= A[i+1])
		{
			R[i] = R[i + 1] + 1;
		}
		else
		{
			R[i] = 1;
		}
	}
	/*for (int i = 1; i <= N; i++)
	{
		cout << R[i];
	}
	cout << endl;*/
	for (int i = 2; i <= N - K; i++)
	{
		if (A[i - 1] <= A[i + K])
		{
			ans = max(ans, K + L[i - 1] + R[i + K]);
		}
		else
		{
			ans = K;
		}
	}
	cout << ans;
	return 0;
}