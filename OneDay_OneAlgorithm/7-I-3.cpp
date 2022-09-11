#include <bits/stdc++.h>
using namespace std;

int dp[10001];	//dp에는 p원을 써서 얻을 수 있는 최대 칼로리를 저장해놓는다.

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
				dp[j] = max(dp[j], dp[j - p] + c);	// 300원을 써서 300 칼로리 얻을 수 있다면
													// 600원을 썼을 때 dp[600]과 300원을 썼을 때 얻을 수 있는 최대 칼로리 + 300 과 최소비교를 한다.
			}
		}
		cout << dp[m] << '\n';
	}
}