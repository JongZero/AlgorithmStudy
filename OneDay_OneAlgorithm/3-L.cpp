#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
char a[21][21];
int visited[21][21];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int v[28];
void dfs(int y, int x, int cnt)
{
	ret = max(ret, cnt);
	//cout << y << ", " << x << " : " << a[y][x] << " cnt: " << cnt << '\n';
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		char nc = a[ny][nx];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (v[nc - 'A']) continue;
		visited[ny][nx] = 1;
		v[nc - 'A'] = 1;
		dfs(ny, nx, cnt + 1);
		visited[ny][nx] = 0;
		v[nc - 'A'] = 0;
	}
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
			cin >> a[i][j];
		}
	}
	visited[0][0] = 1;
	v[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret;
}