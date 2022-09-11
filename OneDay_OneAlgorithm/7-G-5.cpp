#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];	// dp에는 n원의 가치의 동전으로 k원이 되게 하는 최소 동전의 개수를 계속 갱신
const int INF = 987654321;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, INF);
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - t] + 1);		// t가 3일 때, 3원을 만들 수 있는 최소 개수는 0원을 만들 수 있는 최소 개수 + 1이다.
													// 마찬가지로 6원을 만들 수 있는 최소 개수는 3원을 만들 수 있는 최소 개수 + 1(3원짜리 동전 2개)이다.
													// 그러나 +1 한 것이 무조건 최소는 아닐 수 있다. 따라서 최소 비교를 해줘야 한다.
		}
	}
	if (dp[k] == INF) cout << -1;
	else cout << dp[k];
}