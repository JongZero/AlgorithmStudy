#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] += dp[j - t];
		}
	}
	cout << dp[k];
}