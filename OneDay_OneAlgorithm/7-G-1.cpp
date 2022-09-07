#include <bits/stdc++.h>
using namespace std;
const int MAX = 987654321;
int n, k, dp[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, MAX);
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - t] + 1);
		}
	}
	if (dp[k] == MAX) cout << -1;
	else cout << dp[k];
}