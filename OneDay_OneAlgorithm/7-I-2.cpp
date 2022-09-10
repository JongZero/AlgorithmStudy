#include <bits/stdc++.h>
using namespace std;

int dp[10001];	// dp는 j원일 때 얻을 수 있는 최대 칼로리의 양

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);

	while (true)
	{
		int n, m1, m2;
		scanf("%d %d.%d", &n, &m1, &m2);
		int m = m1 * 100 + m2;
		if (n == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			int c, p1, p2;
			scanf("%d %d.%d", &c, &p1, &p2);
			int p = p1 * 100 + p2;
			for (int j = p; j <= m; j++)
			{
				dp[j] = max(dp[j], dp[j - p] + c);
			}
		}
		cout << dp[m] << '\n';
	}
}