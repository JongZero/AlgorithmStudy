#include <bits/stdc++.h>
using namespace std;

int n;
int dp[12];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		dp[0] = 1;
		int t;
		cin >> t;
		for (int j = 1; j <= t; j++)
		{
			for (int k = 1; k <= j; k++)
				dp[j] += dp[j - k];
		}
		cout << dp[t] << '\n';
		memset(dp, 0, sizeof(dp));
	}
}