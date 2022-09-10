#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];	//dp에는 최소값을 계속 갱신, n의 가치에 따라 갱신... 1원일 때 1~k원을 만들 수 있는 최소, 3원일 때 1~k원을 만들 수 있는 최소

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, 987654321);
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - t] + 1);
		}
	}
	if (dp[k] == 987654321) cout << -1;
	else cout << dp[k];
}