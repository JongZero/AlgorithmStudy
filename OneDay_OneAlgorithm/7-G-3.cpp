#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, dp[100001];	// dp에는 계속해서 최소값을 갱신한다. n이 1,3,5라면 1에서 dp갱신, 3에서 dp갱신...

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 100001, INF);
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - t] + 1);
		}
	}
	if (dp[k] == INF) cout << -1;
	else cout << dp[k];
}