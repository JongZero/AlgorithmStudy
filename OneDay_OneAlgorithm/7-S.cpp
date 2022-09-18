#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
string a;
int n, dp[2501][2501], dp2[2501];

int func(int idx)
{
	if (idx == n) return 0;
	int& d = dp2[idx];
	if (d != INF) return d;
	for (int i = 1; idx + i <= n; i++)
	{
		if (dp[idx][i]) d = min(d, func(idx + i) + 1);
	}
	return d;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	fill(dp2, dp2 + 2501, INF);

	cin >> a;
	n = a.size();

	for (int i = 0; i < n; i++)
		dp[i][1] = 1;

	/*
	for (int c = 0; c < n; c++)
	{
		// È¦¼ö
		for (int i = 1; i <= 1250; i++)
		{
			int s = c - i;
			int e = c + i;
			if (s < 0 || e >= n) break;
			if (a[s] == a[e])
			{
				dp[s][e] = 1;
				//cout << s << ", " << e << "´Â ÆÓ¸°µå·ÒÀÌ´Ù.\n";
			}
			else break;
		}
		// Â¦¼ö
		for (int i = 0; i <= 1250; i++)
		{
			int s = c;
			int e = s + i;
			int s2 = e + 1;
			int e2 = s2 + i;
			if (e > n || s2 > n || e2 > n) break;

			dp[s][e2] = 1;
			int w = e2;
			for (int q = s; q <= e; q++, w--)
			{
				if (a[q] != a[w])
				{
					dp[s][e2] = 0;
					break;
				}
			}
			if (dp[s][e2])
			{
				//cout << s << ", " << e2 << "´Â ÆÓ¸°µå·ÒÀÌ´Ù.\n";
			}
		}
	}
	*/

	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			dp[i][2] = 1;
		}
	}
	for (int _size = 3; _size <= n; _size++) {
		for (int j = 0; j + _size <= n; j++) {
			if (a[j] == a[j + _size - 1] && dp[j + 1][_size - 2]) dp[j][_size] = 1;
		}
	}

	cout << func(0);
}