#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 1000000;
int n, dp[MAX + 1];	// dp는 XXX에서 1을 만드는 연산의 최솟값을 저장한다.

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

	fill(dp, dp + MAX + 1, INF);

	cin >> n;
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[n] << '\n';
	print(n);
}