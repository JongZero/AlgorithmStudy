#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];	// dp에는 n원의 동전으로 k원을 만들 수 있는 경우의 수를 누적시켜 준다.

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	dp[0] = 1;	// 0을 만들 수 있는 경우의 수를 1로 둔다.
	for (int i = 0; i < n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = t; j <= k; j++)
		{
			dp[j] += dp[j - t];		// t가 2일 때, 3원을 만들 수 있는 경우의 수는 (이전에 t가 1일 때 경우의 수를 다 담아놨다고 친다.)
									// 1원을 만들 수 있는 경우의 수 = 1
									// 2원을 만들 수 있는 경우의 수 = 1 + 0원을 만들 수 있는 경우의 수
									// 3원을 만들 수 있는 경우의 수 = 1 + 1원을 만들 수 있는 경우의 수
									// 이유는 1원을 만들 수 있는 경우의 수에서 2원짜리 동전을 더해 3원을 만들 수 있기 때문이다.
		}
	}
	cout << dp[k];
}