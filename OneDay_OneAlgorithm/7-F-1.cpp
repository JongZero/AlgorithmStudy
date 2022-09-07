#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int n, dp[MAX + 1];
int prevv[MAX + 1];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + MAX + 1, MAX);
	cin >> n;
	dp[1] = 0;
	prevv[1] = -1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = min(dp[i - 1] + 1, dp[i]);
		prevv[i] = i - 1;
		if (i % 3 == 0)
		{
			if (dp[i / 3] + 1 < dp[i])
				prevv[i] = i / 3;
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
		if (i % 2 == 0)
		{
			if (dp[i / 2] + 1 < dp[i])
				prevv[i] = i / 2;
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
	}
	cout << dp[n] << '\n';
	for (int i = n; i != -1; i = prevv[i])
	{
		cout << i << ' ';
	}
}
