#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[100004];	// dp에는 XXX 무게에서 얻을 수 있는 최대 가치
int ret;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--)
		{
			dp[j] = max(dp[j], dp[j - w] + v);
			//for (int q = 1; q <= k; q++)
			//	cout << dp[q] << ' ';
			//cout << '\n';
		}

	}
	cout << dp[k];
}

//0 0 6 12 12 13 18 24