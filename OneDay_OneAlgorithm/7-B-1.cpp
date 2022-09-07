#include <bits/stdc++.h>
using namespace std;

int n, a[20][20], dp[20][20][3];
enum eType
{
	GARO,
	SERO,
	DAEGAK,
};

bool check(int y, int x, int t)
{
	if (a[y][x]) return false;
	if (t == DAEGAK)
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
			// 세로 -> 대각
			if (check(i + 1, j + 1, DAEGAK)) dp[i + 1][j + 1][DAEGAK] += dp[i][j][SERO];

			// 대각 -> 가로
			if (check(i, j + 1, GARO)) dp[i][j + 1][GARO] += dp[i][j][DAEGAK];
			// 대각 -> 세로
			if (check(i + 1, j, SERO)) dp[i + 1][j][SERO] += dp[i][j][DAEGAK];
			// 대각 -> 대각
			if (check(i + 1, j + 1, DAEGAK)) dp[i + 1][j + 1][DAEGAK] += dp[i][j][DAEGAK];
		}
	}
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

	//for (int i = 1; i <= n; i++)
	//{
	//	for (int j = 1; j <= n; j++)
	//	{
	//		cout << dp[i][j][0] + dp[i][j][1] + dp[i][j][2] << ' ';
	//	}
	//	cout << '\n';
	//}
}