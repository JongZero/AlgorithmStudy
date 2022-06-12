#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n = 0;
	cin >> n;

	int scores[301] = {};
	int dp[301] = {};

	for (int i = 1; i <= n; i++)
	{
		cin >> scores[i];

		int prev = 0;
		int prev2 = 0;

		if (i - 2 > 0)
		{
			prev += dp[i - 2];
		}
		prev += scores[i];

		if (i - 3 > 0)
		{
			prev2 += dp[i - 3];
		}
		if (i - 1 > 0)
		{
			prev2 += scores[i - 1];
		}
		prev2 += scores[i];

		int tempMax = prev;
		if (prev < prev2)
			tempMax = prev2;

		dp[i] = tempMax;
	}

	std::cout << dp[n];

	return 0;
}