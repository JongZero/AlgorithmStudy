#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], visited[51][51], dp[51][51];	//dp는 y,x에서 동전을 최대한 움직일 수 있는 횟수
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int func(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= m) return 0;
	if (a[y][x] == 0) return 0;
	if (visited[y][x])
	{
		cout << -1;
		exit(0);
	}
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * a[y][x];
		int nx = x + dx[i] * a[y][x];
		dp[y][x] = max(dp[y][x], func(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] != 'H') a[i][j] = s[j] - '0';
		}
	}
	cout << func(0, 0);
}