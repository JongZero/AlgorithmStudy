#include <bits/stdc++.h>
using namespace std;

int MAX = 1e9;
int n, dp[1000001], prevv[1000001];	// dp에는 n일 때 최솟값

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	fill(dp, dp + 1000001, MAX);

	cin >> n;
	dp[0] = 0;
	dp[1] = 0;	// 1로 놓는다.
	for (int i = 2; i <= n; i++)
	{
		dp[i] = min(dp[i], dp[i - 1] + 1);
		prevv[i] = i - 1;
		if (i % 3 == 0)
		{
			if (dp[i / 3] + 1 < dp[i])
				prevv[i] = i / 3;
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) 
		{
			if (dp[i / 2] + 1 < dp[i])
				prevv[i] = i / 2;
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		//cout << i << " : " << dp[i] << '\n';
	}
	cout << dp[n] << '\n';
	for (int i = n; i != 1; i = prevv[i])
	{
		cout << i << ' ';
	}
	cout << 1;
}