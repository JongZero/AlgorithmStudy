#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], visited[51][51], dp[51][51];	// dp에는 y, x에서 최대 동전을 움직일 수 있는 횟수
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
	int& d = dp[y][x];
	if (d != -1) return d;
	d = 0;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * a[y][x];
		int nx = x + dx[i] * a[y][x];
		d = max(d, func(ny, nx) + 1);
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
	cout << func(0, 0);
}