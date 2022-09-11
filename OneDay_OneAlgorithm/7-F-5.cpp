#include <bits/stdc++.h>
using namespace std;

int n, dp[1000001];	// dp에는 최솟값을 1부터 갱신, 1에서 1을 만들 수 있는 횟수의 최솟값, 2에서 1을 만들 수 있는 횟수의 최솟값, 3에서 1을 만들 수 있는 횟수의 최솟값...
					// 4에서 1을 만들 수 있는 횟수의 최솟값은 2에서 1을 만들 수 있는 횟수의 최솟값 + 1 이거나 3에서 1을 만들 수 있는 횟수의 최솟값 + 1이다.

const int INF = 1e9;

void print(int s)
{
	cout << s << ' ';
	if (s % 3 == 0 && dp[s] == dp[s / 3] + 1) print(s / 3);
	else if (s % 2 == 0 && dp[s] == dp[s / 2] + 1) print(s / 2);
	else if (dp[s] == dp[s - 1] + 1) print(s - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	//memset(dp, INF, sizeof(dp));
	fill(dp, dp + 1000001, INF);
	cin >> n;
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (i % 3 == 0) dp[i] = min(dp[i], (dp[i / 3] + 1));
		if (i % 2 == 0) dp[i] = min(dp[i], (dp[i / 2] + 1));
		dp[i] = min(dp[i], (dp[i - 1] + 1));
	}
	cout << dp[n] << '\n';
	print(n);
}