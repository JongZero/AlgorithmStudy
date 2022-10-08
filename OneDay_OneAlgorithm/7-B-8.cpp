#include <bits/stdc++.h>
using namespace std;

int n, a[18][18], dp[18][18][3];
enum eType
{
	G,
	S,
	D,
};
bool check(int y, int x, eType t)
{
	if (a[y][x]) return false;
	if (t == D)
	{
		if (a[y - 1][x] || a[y][x - 1]) return false;
	}
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	dp[1][2][G] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 가로
			if (check(i, j + 1, G)) dp[i][j + 1][G] += dp[i][j][G];
			if (check(i + 1, j + 1, D)) dp[i + 1][j + 1][D] += dp[i][j][G];

			// 세로
			if (check(i + 1, j, S)) dp[i + 1][j][S] += dp[i][j][S];
			if (check(i + 1, j + 1, D)) dp[i + 1][j + 1][D] += dp[i][j][S];

			// 대각
			if (check(i, j + 1, G)) dp[i][j + 1][G] += dp[i][j][D];
			if (check(i + 1, j, S)) dp[i + 1][j][S] += dp[i][j][D];
			if (check(i + 1, j + 1, D)) dp[i + 1][j + 1][D] += dp[i][j][D];
		}
	}
	cout << dp[n][n][G] + dp[n][n][S] + dp[n][n][D];
}