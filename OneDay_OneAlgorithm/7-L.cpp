#include <bits/stdc++.h>
using namespace std;

int n, hp[21], dp[101];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	//dp[0] = -987654321;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> hp[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int t = 0;
		cin >> t;
		for (int j = 100; j > hp[i]; j--)	// j > hp[i]인 이유는 hp를 다 써버리면 무조건 0이기 때문에 >= hp[i]로 다 써버리는 경우까지 구할 필요가 없기 때문이다.
		{
			dp[j] = max(dp[j], dp[j - hp[i]] + t);
		}
	}
	//if (dp[100] <= 0)
	//	cout << 0;
	//else cout << dp[100];
	cout << dp[100];
}