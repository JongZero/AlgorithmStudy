#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];
vector<int> a;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	dp[0] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int now = a[i];
		for (int j = now; j < a[i + 1]; j++)
		{
			if (j % now == 0)
			{
				dp[j] = j / now;
			}
			else
			{
				dp[j] = dp[j - now];
			}
		}
	}
	int now = a.back();
	for (int i = a.back(); i <= k; i++)
	{
		if (i % now == 0)
		{
			dp[i] = i / now;
		}
		else
		{
			dp[i] = dp[i - now];
		}
	}
	cout << dp[k];
}