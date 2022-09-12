#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], dp[51][51];	// dp���� y,x���� �ִ�� ������ �� �ִ� ���� Ƚ��
int visited[51][51];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x)
{
	if (a[y][x] == 0) return 0;
	if (y < 0 || y >= n || x < 0 || x >= m) return 0;
	if (visited[y][x])
	{
		cout << -1;
		exit(0);
	}
	if (dp[y][x] != -1) return dp[y][x];
	int& d = dp[y][x];
	d = 0;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * a[y][x];
		int nx = x + dx[i] * a[y][x];
		d = max(d, dfs(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return d;
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
	cout << dfs(0, 0);
}