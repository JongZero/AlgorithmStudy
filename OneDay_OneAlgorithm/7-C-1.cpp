#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], dp[51][51], visited[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= m) return 0;
	if (a[y][x] == 0) return 0;
	if (visited[y][x])
	{
		cout << -1;
		exit(0);
	}

	if (dp[y][x]) return dp[y][x];

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + (a[y][x] * dy[i]);
		int nx = x + (a[y][x] * dx[i]);
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c != 'H') a[i][j] = c - '0';
		}
	}
	dfs(0, 0);
	cout << dp[0][0];
}