#include <bits/stdc++.h>
using namespace std;

int n, a[17][17], dp[17][17][3];
enum eType
{
	GARO,
	SERO,
	DAEGAK,
};
bool check(int y, int x, eType t)
{
	if (y < 1 || y > n || x < 1 || x > n) return false;
	if (a[y][x]) return false;
	if (t == DAEGAK)
	{
		if (a[y - 1][x] || a[y][x - 1])
			return false;
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
	dp[1][2][GARO] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 가로 -> 가로
			if (check(i, j + 1, GARO)) dp[i][j + 1][GARO] += dp[i][j][GARO];
			// 가로 -> 대각
			if (check(i + 1, j + 1, DAEGAK)) dp[i + 1][j + 1][DAEGAK] += dp[i][j][GARO];

			// 세로 -> 세로
			if (check(i + 1, j, SERO)) dp[i + 1][j][SERO] += dp[i][j][SERO];
			if (check(i + 1, j + 1, DAEGAK)) dp[i + 1][j + 1][DAEGAK] += dp[i][j][SERO];

			// 대각
			if (check(i, j + 1, GARO)) dp[i][j + 1][GARO] += dp[i][j][DAEGAK];
			if (check(i + 1, j, SERO)) dp[i + 1][j][SERO] += dp[i][j][DAEGAK];
			if (check(i + 1, j + 1, DAEGAK)) dp[i + 1][j + 1][DAEGAK] += dp[i][j][DAEGAK];
		}
	}
	cout << dp[n][n][GARO] + dp[n][n][SERO] + dp[n][n][DAEGAK];
}