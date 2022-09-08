#include <bits/stdc++.h>
using namespace std;

int t, k, dp[10001];	// dp에는 최솟값을 계속 갱신, 갱신은 동전의 가치에 따라서
						// ex) k = 10, n = 1,3,5
							// 아래에서 중요한 점은 k가 0일 때 최소값 0으로 놓는다는 것이다.
							// n이 1일 때 최소값
							// k		0	1	2	3	4	5	6	7	8	9	10
							// 최소값		0	1	2	3	4	5	6	7	8	9	10
							
							// n이 3일 때 최소값(*이 갱신된 최소값)
							// k		0	1	2	3	4	5	6	7	8	9	10
							// 최소값		0	1	2	1*	4	5	2*	7	8	3*	10

							// n이 5일 때 최소값
							// k		0	1	2	3	4	5	6	7	8	9	10
							// 최소값		0	1	2	1	4	1*	2	7	8	3	2*

							// 따라서 점화식을 dp[i] = dp[i - n] + 1로 놓을 수 있고, 매번 최소값을 갱신해준다.
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	fill(dp, dp + 10001, 1000000000);
	dp[0] = 0;
	cin >> t >> k;
	for (int q = 0; q < t; q++)
	{
		int n;
		cin >> n;
		for (int i = n; i <= k; i++)
		{
			dp[i] = min(dp[i], dp[i - n] + 1);
		}
	}
	if (dp[k] == 1000000000) cout << -1;
	else cout << dp[k];
}